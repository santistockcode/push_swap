#!/usr/bin/env python3
"""
Checker validation tests for push_swap.
Validates that push_swap produces correct sorting operations.
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


def run_checker_test(push_swap_binary: Path, checker_binary: Path, 
                     size: int, threshold: int, num_tests: int = 10) -> bool:
    """Run checker_linux tests for a given size."""
    log(f"  → Stack size: {size} | Threshold: {threshold}", Colors.CYAN)
    
    total_instructions = 0
    correct_count = 0
    
    for i in range(1, num_tests + 1):
        # Generate random numbers
        numbers = generate_random_numbers(size)
        args = [str(n) for n in numbers]
        
        # Run push_swap and count instructions
        try:
            result = subprocess.run(
                [str(push_swap_binary)] + args,
                capture_output=True,
                text=True,
                check=True
            )
            operations = result.stdout
            instr_count = len(operations.strip().split('\n')) if operations.strip() else 0
            
            # Check threshold
            if instr_count > threshold:
                log(f"Test failed! Instruction count {instr_count} exceeded threshold {threshold}", Colors.RED)
                log(f"Failing ARG: {' '.join(args)}", Colors.YELLOW)
                return False
            
            # Validate with checker_linux
            checker_result = subprocess.run(
                [str(checker_binary)] + args,
                input=operations,
                capture_output=True,
                text=True
            )
            
            total_instructions += instr_count
            
            if checker_result.stdout.strip() == "OK":
                correct_count += 1
            else:
                log(f"Checker returned: {checker_result.stdout.strip()}", Colors.RED)
                log(f"Failing ARG: {' '.join(args)}", Colors.YELLOW)
                return False
                
        except subprocess.CalledProcessError as e:
            log(f"push_swap failed: {e}", Colors.RED)
            return False
    
    # Calculate and report results
    avg_instructions = total_instructions // num_tests
    
    log(f"     Tests run: {num_tests}")
    log(f"     Sorted OK: {correct_count}/{num_tests}")
    log(f"     Avg instructions: {avg_instructions}")
    
    if avg_instructions <= threshold and correct_count == num_tests:
        log(f"     Performance: PASS (<= {threshold})", Colors.GREEN)
    else:
        log(f"     Performance: FAIL (> {threshold})", Colors.RED)
        return False
    
    return True


def main():
    """Main entry point."""
    project_root = Path(__file__).parent.parent
    push_swap_binary = project_root / "push_swap"
    checker_binary = project_root / "checker_linux"
    
    # Test configuration
    test_sizes = [3, 5, 100, 500]
    thresholds = [2, 12, 700, 5500]
    num_tests_per_size = 10
    
    log("\n" + "="*70, Colors.BOLD)
    log("CHECKER VALIDATION TESTS", Colors.BOLD)
    log("="*70, Colors.BOLD)
    
    # Check if binaries exist
    if not push_swap_binary.exists():
        log(f"Error: {push_swap_binary} not found!", Colors.RED)
        log("Run 'make' first to build the project.", Colors.YELLOW)
        return 1
    
    if not checker_binary.exists():
        log(f"Error: {checker_binary} not found!", Colors.RED)
        return 1
    
    # Run tests
    for size, threshold in zip(test_sizes, thresholds):
        if not run_checker_test(push_swap_binary, checker_binary, size, threshold, num_tests_per_size):
            log("\n✗ Checker validation tests FAILED", Colors.RED)
            return 1
    
    log("\n✓ All checker validation tests PASSED", Colors.GREEN)
    return 0


if __name__ == "__main__":
    sys.exit(main())

