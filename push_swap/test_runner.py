#!/usr/bin/env python3
"""
Test runner for push_swap project.
- Unit tests: Criterion tests (compiled and run)
- Integration tests: Orchestrates separate test scripts
"""

import argparse
import subprocess
import sys
from pathlib import Path
from typing import List, Optional


class Colors:
    """ANSI color codes for terminal output."""
    RED = '\033[1;31m'
    GREEN = '\033[1;32m'
    YELLOW = '\033[1;33m'
    BLUE = '\033[1;34m'
    CYAN = '\033[1;36m'
    RESET = '\033[0m'
    BOLD = '\033[1m'


class TestRunner:
    """Test runner - compiles/runs unit tests, orchestrates integration tests."""
    
    def __init__(self, keep_binaries: bool = False):
        self.keep_binaries = keep_binaries
        self.project_root = Path(__file__).parent
        self.unit_tests_dir = self.project_root / "unit_tests_from_python"
        self.integration_tests_dir = self.project_root / "integration_tests_from_python"
        self.src_dir = self.project_root / "src"
        self.include_dir = self.project_root / "include"
        self.libft_dir = self.project_root / "libft"
        self.libft_lib = self.libft_dir / "libft.a"
        
        # Track compiled binaries for cleanup
        self.compiled_binaries: List[Path] = []
        
        # Compiler settings
        self.cc = "cc"
        self.cflags = ["-g", "-Wall", "-Wextra", "-Werror"]
        self.includes = [
            f"-I{self.include_dir}",
            f"-I{self.libft_dir}/include"
        ]
        self.libs = ["-lcriterion", "-lm", str(self.libft_lib)]
    
    def log(self, message: str, color: str = ""):
        """Print a log message."""
        if color:
            print(f"{color}{message}{Colors.RESET}")
        else:
            print(message)
    
    def ensure_libft_built(self) -> bool:
        """Ensure libft is built."""
        if not self.libft_lib.exists():
            self.log("Building libft...", Colors.BLUE)
            try:
                subprocess.run(
                    ["make", "-C", str(self.libft_dir)],
                    capture_output=True,
                    check=True
                )
                return True
            except subprocess.CalledProcessError as e:
                self.log(f"Failed to build libft: {e.stderr}", Colors.RED)
                return False
        return True
    
    def discover_test_sources(self) -> List[Path]:
        """Discover all test source files."""
        if not self.unit_tests_dir.exists():
            self.log(f"Tests directory not found: {self.unit_tests_dir}", Colors.RED)
            return []
        
        test_files = list(self.unit_tests_dir.glob("test_*.c"))
        return test_files
    
    def get_dependencies_for_test(self, test_file: Path) -> List[Path]:
        """Get source dependencies for a test file."""
        test_name = test_file.stem
        dependencies = []
        
        if "ft_split_ps" in test_name:
            dependencies.append(self.src_dir / "ft_split_ps.c")
        
        if "order_utils" in test_name:
            dependencies.extend([
                self.src_dir / "order_utils.c",
            ])
        
        return dependencies
    
    def compile_test(self, test_file: Path) -> Optional[Path]:
        """Compile a test file."""
        test_name = test_file.stem
        output_binary = self.unit_tests_dir / test_name
        
        self.log(f"Compiling {test_name}...", Colors.BLUE)
        
        dependencies = self.get_dependencies_for_test(test_file)
        
        compile_cmd = [
            self.cc,
            *self.cflags,
            *self.includes,
            str(test_file),
            *[str(dep) for dep in dependencies],
            *self.libs,
            "-o", str(output_binary)
        ]
        
        try:
            subprocess.run(
                compile_cmd,
                capture_output=True,
                check=True
            )
            self.log(f"✓ Compiled {test_name}", Colors.GREEN)
            self.compiled_binaries.append(output_binary)
            return output_binary
        except subprocess.CalledProcessError as e:
            self.log(f"✗ Failed to compile {test_name}", Colors.RED)
            self.log(f"Error: {e.stderr.decode() if e.stderr else 'Unknown error'}", Colors.RED)
            return None
    
    def run_test(self, binary: Path) -> int:
        """Run a test binary - let Criterion handle everything."""
        self.log(f"\nRunning {binary.name}...", Colors.YELLOW)
        
        # Run and let Criterion output directly to stdout
        result = subprocess.run([str(binary)])
        
        return result.returncode
    
    def cleanup_binaries(self):
        """Clean up compiled binaries."""
        if self.keep_binaries:
            return
        
        for binary in self.compiled_binaries:
            if binary.exists():
                try:
                    binary.unlink()
                except Exception:
                    pass
    
    def run_unit_tests(self) -> bool:
        """Run unit tests."""
        self.log("\n" + "="*70, Colors.BOLD)
        self.log("UNIT TESTS", Colors.BOLD)
        self.log("="*70, Colors.BOLD)
        
        if not self.ensure_libft_built():
            return False
        
        test_files = self.discover_test_sources()
        if not test_files:
            self.log("No test files found", Colors.YELLOW)
            return True
        
        success = True
        
        try:
            for test_file in test_files:
                binary = self.compile_test(test_file)
                if binary and binary.exists():
                    exit_code = self.run_test(binary)
                    if exit_code != 0:
                        success = False
                else:
                    success = False
        finally:
            self.cleanup_binaries()
        
        return success
    
    def run_integration_tests(self, checker: bool = True, valgrind: bool = True) -> bool:
        """Run integration tests by calling separate scripts."""
        success = True
        
        # Run checker validation tests
        if checker:
            checker_script = self.integration_tests_dir / "checker_validation.py"
            if checker_script.exists():
                result = subprocess.run(["python3", str(checker_script)])
                if result.returncode != 0:
                    success = False
            else:
                self.log(f"Warning: {checker_script} not found", Colors.YELLOW)
        
        # Run valgrind tests
        if valgrind:
            valgrind_script = self.integration_tests_dir / "valgrind_tests.py"
            if valgrind_script.exists():
                result = subprocess.run(["python3", str(valgrind_script)])
                if result.returncode != 0:
                    success = False
            else:
                self.log(f"Warning: {valgrind_script} not found", Colors.YELLOW)
        
        return success


def main():
    """Main entry point."""
    parser = argparse.ArgumentParser(
        description="Test runner for push_swap project",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
Examples:
  # Unit tests
  python test_runner.py --unit
  python test_runner.py --unit --keep-binaries

  # Integration tests (both checker and valgrind)
  python test_runner.py --integration

  # Integration tests (specific)
  python test_runner.py --integration --checker
  python test_runner.py --integration --valgrind

  # Run everything
  python test_runner.py --unit --integration

Manual unit test execution (after --keep-binaries):
  ./unit_tests_from_python/test_order_utils --list
  ./unit_tests_from_python/test_order_utils --filter test_name
        """
    )
    
    parser.add_argument(
        '--unit',
        action='store_true',
        help='Run unit tests (Criterion)'
    )
    
    parser.add_argument(
        '--integration',
        action='store_true',
        help='Run integration tests (checker_linux and Valgrind)'
    )
    
    parser.add_argument(
        '--checker',
        action='store_true',
        help='Run only checker_linux tests (use with --integration)'
    )
    
    parser.add_argument(
        '--valgrind',
        action='store_true',
        help='Run only Valgrind tests (use with --integration)'
    )
    
    parser.add_argument(
        '--keep-binaries',
        action='store_true',
        help='Keep compiled test binaries (for manual testing)'
    )
    
    args = parser.parse_args()
    
    # If no test type specified, show help
    if not args.unit and not args.integration:
        parser.print_help()
        return 1
    
    runner = TestRunner(keep_binaries=args.keep_binaries)
    
    success = True
    
    # Run unit tests
    if args.unit:
        if not runner.run_unit_tests():
            success = False
    
    # Run integration tests
    if args.integration:
        # If neither --checker nor --valgrind specified, run both
        run_checker = args.checker or (not args.checker and not args.valgrind)
        run_valgrind = args.valgrind or (not args.checker and not args.valgrind)
        
        if not runner.run_integration_tests(checker=run_checker, valgrind=run_valgrind):
            success = False
    
    return 0 if success else 1


if __name__ == "__main__":
    sys.exit(main())
