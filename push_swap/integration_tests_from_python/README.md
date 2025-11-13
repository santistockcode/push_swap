# Integration Tests

This directory contains integration test scripts for the push_swap project.

## Test Scripts

### `checker_validation.py`
Validates that `push_swap` produces correct sorting operations using `checker_linux`.

**What it tests:**
- Correctness: Does `push_swap` sort correctly?
- Performance: Does it stay within instruction thresholds?

**Configuration:**
- Stack sizes: 3, 5, 100, 500
- Thresholds: 2, 12, 700, 5500 instructions
- 10 random tests per size

**Run directly:**
```bash
python3 integration_tests_from_python/checker_validation.py
```

### `valgrind_tests.py`
Checks for memory leaks using Valgrind.

**What it tests:**
- Memory management: No leaks, no errors

**Configuration:**
- Stack sizes: 3, 5, 100, 500
- 10 random tests per size
- Logs saved to: `tests/check_leaks/<size>/`

**Run directly:**
```bash
python3 integration_tests_from_python/valgrind_tests.py
```

## Running via test_runner.py

The recommended way is through the main test runner:

```bash
# Run all integration tests
python test_runner.py --integration

# Run only checker tests
python test_runner.py --integration --checker

# Run only valgrind tests
python test_runner.py --integration --valgrind
```

## Requirements

- `push_swap` binary (build with `make`)
- `checker_linux` binary (provided)
- Valgrind installed (for memory tests)

## Customization

To modify test parameters, edit the configuration in each script:

```python
# In checker_validation.py or valgrind_tests.py
test_sizes = [3, 5, 100, 500]           # Stack sizes to test
thresholds = [2, 12, 700, 5500]         # Max instructions (checker only)
num_tests_per_size = 10                 # Number of tests per size
```

## Output

Both scripts provide:
- Clear pass/fail status
- Colored output for easy reading
- Failing test arguments (for debugging)
- Valgrind log paths (for memory issues)

## Exit Codes

- `0`: All tests passed
- `1`: One or more tests failed

Perfect for CI/CD pipelines!

