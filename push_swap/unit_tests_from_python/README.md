# Unit Tests

This directory contains Criterion unit tests for the push_swap project.

## Quick Start

```bash
# Run all unit tests
python test_runner.py --unit

# Keep test binaries for manual testing
python test_runner.py --unit --keep-binaries

# Run specific tests manually (after --keep-binaries)
./unit_tests_from_python/test_order_utils --list
./unit_tests_from_python/test_order_utils --filter test_name
```

## Current Test Suites

### `test_ft_split_ps.c`
Tests for argument parsing function `ft_split_ps`.

**Important:** This function uses a static variable and can only be called once per program execution. Works in tests because Criterion runs each test in a separate process (fork mode).

**Coverage:**
- Basic splits
- Edge cases (empty strings, multiple spaces)
- Error handling

### `test_order_utils.c`
Tests for stack utility functions. Clean TDD example with 28 tests.

**Functions tested:**
- `find_index_of`: Find index of value in list
- `update_indexes`: Update position indexes
- `is_ordered`: Check if stack is sorted
- `find_min_number`: Find minimum value
- `find_max_number`: Find maximum value

## Writing New Tests

### 1. Create test file
```bash
vim unit_tests_from_python/test_my_module.c
```

### 2. Write tests
```c
#include <criterion/criterion.h>
#include "my_module.h"

Test(my_module, basic_test) {
    int result = my_function(42);
    cr_assert_eq(result, 42, "Expected 42");
}
```

### 3. Update dependencies
Edit `test_runner.py`:

```python
def get_dependencies_for_test(self, test_file: Path) -> List[Path]:
    # ...
    if "my_module" in test_name:
        dependencies.append(self.src_dir / "my_module.c")
```

### 4. Run tests
```bash
python test_runner.py --unit
```

## Criterion Resources

- [Criterion Documentation](https://criterion.readthedocs.io/)
- Use `cr_assert_*` macros for assertions
- Test naming: `Test(suite_name, test_name)`
- Each test runs in isolated process (fork mode)

## Requirements

- Criterion installed (`libcriterion-dev`)
- libft built
- C compiler (cc)
