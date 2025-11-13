#!/usr/bin/env python3
"""
Valgrind memory leak tests for push_swap.
Checks that push_swap has no memory leaks.
"""

import random
import subprocess
import sys
from pathlib import Path
from typing import List


class Colors:
    RED = '\033[1;31m'
    GREEN = '\033[1;32m'
    YELLOW = '\033[1;33m'
    BLUE = '\033[1;34m'
    CYAN = '\033[1;36m'
    RESET = '\033[0m'
    BOLD = '\033[1m'


def log(message: str, color: str = ""):
    """Print a log message."""
    if color:
        print(f"{color}{message}{Colors.RESET}")
    else:
        print(message)


def generate_random_numbers(size: int, min_val: int = -999, max_val: int = 999) -> List[int]:
    """Generate a list of unique random integers."""
    return random.sample(range(min_val, max_val + 1), size)


def run_valgrind_test(push_swap_binary: Path, size: int, num_tests: int = 10) -> bool:
    """Run Valgrind memory leak tests for a given size."""
    log(f"  → Stack size: {size}", Colors.CYAN)
    
    # Create log directory
    log_dir = Path(__file__).parent.parent / "tests" / "check_leaks" / str(size)
    log_dir.mkdir(parents=True, exist_ok=True)
    
    leak_free_count = 0
    
    for i in range(1, num_tests + 1):
        # Generate random numbers
        numbers = generate_random_numbers(size)
        args = [str(n) for n in numbers]
        
        log_file = log_dir / f"checker_{i}.log"
        
        # Run with Valgrind
        valgrind_cmd = [
            "valgrind",
            "--leak-check=full",
            "--show-leak-kinds=all",
            "--track-origins=yes",
            f"--log-file={log_file}",
            str(push_swap_binary)
        ] + args
        
        try:
            subprocess.run(
                valgrind_cmd,
                stdout=subprocess.DEVNULL,
                stderr=subprocess.DEVNULL,
                check=False
            )
            
            # Check log for leaks
            with open(log_file, 'r') as f:
                log_content = f.read()
            
            if ("All heap blocks were freed -- no leaks are possible" in log_content and
                "ERROR SUMMARY: 0 errors from 0 contexts" in log_content):
                leak_free_count += 1
            else:
                log("Memory leak detected!", Colors.RED)
                log(f"Failing ARG: {' '.join(args)}", Colors.YELLOW)
                log(f"See: {log_file}", Colors.YELLOW)
                return False
                
        except Exception as e:
            log(f"Valgrind test failed: {e}", Colors.RED)
            return False
    
    log(f"     Leak check passed: {leak_free_count}/{num_tests}", Colors.GREEN)
    return True


def main():
    """Main entry point."""
    project_root = Path(__file__).parent.parent
    push_swap_binary = project_root / "push_swap"
    
    # Test configuration
    test_sizes = [3, 5, 100, 500]
    num_tests_per_size = 10
    
    log("\n" + "="*70, Colors.BOLD)
    log("VALGRIND MEMORY LEAK TESTS", Colors.BOLD)
    log("="*70, Colors.BOLD)
    
    # Check if binary exists
    if not push_swap_binary.exists():
        log(f"Error: {push_swap_binary} not found!", Colors.RED)
        log("Run 'make' first to build the project.", Colors.YELLOW)
        return 1
    
    # Run tests
    for size in test_sizes:
        if not run_valgrind_test(push_swap_binary, size, num_tests_per_size):
            log("\n✗ Valgrind tests FAILED", Colors.RED)
            return 1
    
    log("\n✓ All Valgrind tests PASSED", Colors.GREEN)
    return 0


if __name__ == "__main__":
    sys.exit(main())

