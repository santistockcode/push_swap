# Understanding the Test Suites

This document explains the two test suites and their different approaches.

## Two Examples: Clean vs. Special Case

### 1. `test_order_utils.c` - Clean TDD Example ✅

**Perfect for learning TDD!**

```c
// Clean, reusable functions with no hidden state
int find_min_number(t_list *a_head);
int find_max_number(t_list *a_head);
int is_ordered(t_list *a_head);
void update_indexes(t_list *a_head);
int find_index_of(t_list *a_head, int number);
```

**Why it's clean:**
- ✅ No static variables
- ✅ No global state
- ✅ Pure functions (same input → same output)
- ✅ Can be called unlimited times
- ✅ Thread-safe
- ✅ Perfect for TDD

**Test structure:**
```c
Test(order_utils, is_ordered_empty_list)
{
    t_list *stack = NULL;
    cr_assert_eq(is_ordered(stack), 1);
}

Test(order_utils, is_ordered_single_element)
{
    int values[] = {42};
    t_list *stack = create_stack(values, 1);
    cr_assert_eq(is_ordered(stack), 1);
    free_stack(stack);
}

// ... many more tests, all work perfectly!
```

**Coverage (28 test cases):**
- `is_ordered()`: 8 tests
- `find_min_number()`: 6 tests
- `find_max_number()`: 5 tests
- `find_index_of()`: 6 tests
- `update_indexes()`: 3 tests

### 2. `test_ft_split_ps.c` - Special Case ⚠️

**Works, but has a limitation due to design choice**

```c
// Uses static variable internally (in alloc_word)
char **ft_split_ps(char *str);
```

**The limitation:**
```c
char *alloc_word(char *str)
{
    static int cursor;  // ← Persists across calls!
    // ...
}
```

**Why it works in push_swap:**
```c
// main.c (simplified)
int main(int argc, char **argv)
{
    char *joined = ft_join_spaces(argv, argc);
    char **numbers = ft_split_ps(joined);  // ← Called ONCE
    // ... use numbers ...
    exit(0);  // ← Process ends, static resets
}
```

**Why it works in tests:**
Criterion runs each test in a **separate forked process** by default:

```
Process 1: Test case 1 → ft_split_ps() → cursor = 0
           Process ends → static resets

Process 2: Test case 2 → ft_split_ps() → cursor = 0 (fresh start!)
           Process ends → static resets

Process 3: Test case 3 → ft_split_ps() → cursor = 0 (fresh start!)
           ...
```

**Test structure:**
```c
// Each test runs in separate process
Test(ft_split_ps, simple_single_word)
{
    char **result = ft_split_ps("42");  // Fresh process, cursor = 0
    cr_assert_str_eq(result[0], "42");
    free_split(result);
}  // Process ends

Test(ft_split_ps, multiple_words)
{
    char **result = ft_split_ps("1 2 3");  // NEW process, cursor = 0
    cr_assert_eq(count_elements(result), 3);
    free_split(result);
}  // Process ends
```

**Coverage (14 test cases):**
- Simple cases: single word, multiple words
- Whitespace handling: spaces, tabs, newlines, mixed
- Edge cases: empty, only whitespace
- Real-world: negative numbers, large numbers, complex patterns

## Key Differences

| Aspect | `test_order_utils.c` | `test_ft_split_ps.c` |
|--------|---------------------|---------------------|
| **Design** | Clean, pure functions | Uses static variable |
| **Reusability** | Fully reusable | Single-use per process |
| **Test isolation** | Works in same process | Needs separate processes |
| **TDD example** | ✅ Perfect | ⚠️ Works but not ideal |
| **Criterion mode** | Any mode works | Requires fork mode (default) |
| **Thread safety** | Yes | No |
| **Learning value** | High - best practices | Medium - special case |

## Running the Tests

Both work perfectly with the test runner:

```bash
# Run both test suites
python3 test_runner.py --unit

# Expected output:
# ✓ test_order_utils: 28/28 tests passed
# ✓ test_ft_split_ps: 14/14 tests passed
```

## Which One to Study?

### Start with `test_order_utils.c` 📚

This is your **gold standard** for TDD:

1. **Read the tests first** to understand what the function should do
2. **Observe the pattern**:
   ```c
   // 1. Setup
   t_list *stack = create_stack(values, count);
   
   // 2. Execute
   int result = find_min_number(stack);
   
   // 3. Assert
   cr_assert_eq(result, expected);
   
   // 4. Cleanup
   free_stack(stack);
   ```
3. **See multiple test cases** for same function
4. **Edge cases**: empty list, single element, etc.

### Then Look at `test_ft_split_ps.c` 🔍

Understand the **special case**:

1. Why it uses static variables (design trade-off)
2. How Criterion's fork mode solves the problem
3. When this pattern is acceptable vs. problematic

## TDD Workflow Example: `is_ordered()`

### 1. Write Test First (RED)

```c
Test(order_utils, is_ordered_empty_list)
{
    t_list *stack = NULL;
    cr_assert_eq(is_ordered(stack), 1, "Empty should be ordered");
}
```

Run: `python3 test_runner.py --unit` → ❌ FAILS (function doesn't exist)

### 2. Implement Minimum Code (GREEN)

```c
int is_ordered(t_list *a_head)
{
    if (!a_head)
        return (1);  // Empty is ordered
    // TODO: implement rest
    return (1);
}
```

Run: `python3 test_runner.py --unit` → ✅ PASSES

### 3. Add More Tests

```c
Test(order_utils, is_ordered_two_ascending)
{
    int values[] = {1, 2};
    t_list *stack = create_stack(values, 2);
    cr_assert_eq(is_ordered(stack), 1);
    free_stack(stack);
}

Test(order_utils, is_ordered_two_descending)
{
    int values[] = {2, 1};
    t_list *stack = create_stack(values, 2);
    cr_assert_eq(is_ordered(stack), 0);  // NOT ordered
    free_stack(stack);
}
```

Run: → ❌ FAILS (needs real implementation)

### 4. Complete Implementation

```c
int is_ordered(t_list *a_head)
{
    t_list *current;
    
    current = a_head;
    while (current && current->next)
    {
        if (((t_number *)current->content)->value
            > ((t_number *)current->next->content)->value)
            return (0);
        current = current->next;
    }
    return (1);
}
```

Run: → ✅ ALL PASS

### 5. Refactor with Confidence

You can now improve the code knowing tests will catch regressions!

## Helper Functions

Both test suites use helper functions:

### `test_order_utils.c` helpers:

```c
// Create a t_number with given value
t_number *create_number(int value);

// Create a stack from array
t_list *create_stack(int *values, int count);

// Free entire stack
void free_stack(t_list *head);
```

**Usage:**
```c
int values[] = {1, 2, 3};
t_list *stack = create_stack(values, 3);
// ... test ...
free_stack(stack);
```

### `test_ft_split_ps.c` helpers:

```c
// Free split result
void free_split(char **split);

// Count elements
int count_elements(char **split);
```

**Usage:**
```c
char **result = ft_split_ps("1 2 3");
cr_assert_eq(count_elements(result), 3);
free_split(result);
```

## Best Practices Demonstrated

### 1. Test Organization

```c
/*
** Tests for is_ordered()
*/

Test(suite, test_name)  // Clear naming
{
    // Setup
    // Execute
    // Assert
    // Cleanup
}
```

### 2. Edge Cases

Always test:
- ✅ Empty input
- ✅ Single element
- ✅ Two elements (boundary)
- ✅ Multiple elements
- ✅ Negative numbers
- ✅ Large numbers
- ✅ Special cases

### 3. Clear Assertions

```c
// ❌ Bad
cr_assert(result == 1);

// ✅ Good
cr_assert_eq(result, 1, "Empty list should be considered ordered");
```

### 4. Memory Management

```c
// Always free allocated memory
t_list *stack = create_stack(values, 3);
// ... test ...
free_stack(stack);  // ← Important!
```

## Common Patterns

### Testing a Function that Returns Int

```c
Test(suite, function_returns_correct_value)
{
    // Setup
    int values[] = {3, 1, 2};
    t_list *stack = create_stack(values, 3);
    
    // Execute
    int result = find_min_number(stack);
    
    // Assert
    cr_assert_eq(result, 1, "Minimum should be 1");
    
    // Cleanup
    free_stack(stack);
}
```

### Testing a Function that Modifies Data

```c
Test(suite, function_modifies_correctly)
{
    // Setup
    int values[] = {1, 2, 3};
    t_list *stack = create_stack(values, 3);
    
    // Execute
    update_indexes(stack);
    
    // Assert
    t_number *num = (t_number *)stack->content;
    cr_assert_eq(num->index, 0, "First element index should be 0");
    
    // Cleanup
    free_stack(stack);
}
```

### Testing NULL Cases

```c
Test(suite, handles_null_gracefully)
{
    t_list *stack = NULL;
    
    // Should not crash
    int result = find_min_number(stack);
    
    cr_assert_eq(result, 0, "NULL should return 0");
}
```

## Summary

- **Use `test_order_utils.c` as your TDD template** ✅
- **Understand `test_ft_split_ps.c` as a special case** ⚠️
- **Both work perfectly with Criterion's default fork mode** 🎯
- **Focus on edge cases and clear assertions** 📝
- **Always clean up memory** 🧹

## Next Steps

1. ✅ Study `test_order_utils.c` thoroughly
2. ✅ Run the tests: `python3 test_runner.py --unit`
3. ✅ Try adding a new test case to `test_order_utils.c`
4. ✅ Create tests for another module (operations, order_few, etc.)
5. ✅ Apply TDD in future projects!

Happy Testing! 🚀

