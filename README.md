# push_swap
Este proyecto te hará ordenar datos en un stack, con un conjunto limitado de instrucciones, y utilizando el menor número posible de acciones. Para tener éxito, deberás probar a utilizar varios tipos de algoritmos y elegir la solución más apropiada (de entre muchas posibles) para conseguir la ordenación optimizada de los datos.

# complejidad
https://en.wikipedia.org/wiki/Analysis_of_algorithms

# Instrucciones
Nombre del programa: push_swap
Archivos a entregar: Makefile, *.h, *.c
Argumentos: un stack de números enteros
Funciones autorizadas: read, write, malloc, free, exit, ft_printf y cualquier función
equivalente que hayas creado

```c
/**
 * Reads data from a file.
 *
 * @param file The file to read from.
 * @param buffer The buffer to store the read data.
 * @param size The number of bytes to read.
 * @return The number of bytes read, or -1 if an error occurred.
 */
ssize_t read(int file, void *buffer, size_t size);

/**
 * Writes data to a file.
 *
 * @param file The file to write to.
 * @param buffer The buffer containing the data to write.
 * @param size The number of bytes to write.
 * @return The number of bytes written, or -1 if an error occurred.
 */
ssize_t write(int file, const void *buffer, size_t size);

/**
 * Allocates a block of memory.
 *
 * @param size The size of the memory block to allocate.
 * @return A pointer to the allocated memory, or NULL if the allocation failed.
 */
void *malloc(size_t size);

/**
 * Frees a previously allocated block of memory.
 *
 * @param ptr A pointer to the memory block to free.
 */
void free(void *ptr);

/**
 * Terminates the program.
 *
 * @param status The exit status of the program.
 */
void exit(int status);
```

# Evaluación

mi propio checker en python
Makefile leer otros proyectos

• Para una validación mínima del proyecto (que implica una nota mínima de
80), deberás ser capaz de ordenar 100 números aleatorios en menos de 700
operaciones.
• Para una validación máxima del proyecto y así poder obtener los bonus, deberás
cumplir el primer paso anterior, pero también para 500 números aleatorios, no
deberás superar las 5500 operaciones.
Todo esto será verificado durante la evaluación.

## Pasos sí o sí

#### Parseado de argumentos
➜  hu8813 git:(main) ✗ ./push_swap "1 2    3" 4 5 6 "8"
➜  hu8813 git:(main) ✗ ./push_swap "1 2        3" 4 5 6 "8"
➜  hu8813 git:(main) ✗ 1 2         3 4 5 6   

lluvia de idea de tareas
Entonces el procedimiento es hacer un join de todos los argumentos (comprobar que solo tengo '-', ' ' y números) y luego hacer un split por ' '. 
TODO: Revisar requisitos y ver como usa la chica del video casos límite (usa long long en algún momento)

manejar la entrada como string o como ints
manejar casos de errores
inicializar las listas
check si está ordenado
checkear duplicados
Below is a suggested breakdown of tasks and sub-tasks you can use to organize your work on the push_swap project. Of course, you can (and should) adapt it to your own preferences and to any particular constraints of the assignment.

---

## 1. **Project Setup**

1. **Read and Understand Requirements**  
   - Review the push_swap requirements carefully (including input/output format, allowed operations, performance constraints).
   - Decide on the language features you will use (e.g., standard C library functions allowed or disallowed, memory management constraints, etc.).

2. **Plan Your Folder/Files Structure**  
   - Create separate files or folders for logic, utilities, error handling, main function, etc.
   - Example:
     - `push_swap.h` (header containing function prototypes, structs, etc.)
     - `main.c` (entry point for push_swap)
     - `checker.c` (entry point for checker if you plan a separate program)
     - `operations.c` (implements `sa`, `sb`, `ra`, etc.)
     - `sort_small.c`, `sort_big.c` (sorting logic for different input sizes)
     - `utils.c` (utility functions, parsing, printing, etc.)

---

## 2. **Input Parsing & Validation**

1. **Command-Line Arguments Parsing**  
   - Handle the number of arguments (`argc` check).
   - Handle the case where arguments can come as separate integers or as a single quoted string containing multiple integers.

2. **Data Validation**  
   - Convert strings to integers (or `long` checks to detect overflow).
   - Detect if any input is not a valid integer (non-numeric characters, etc.).
   - Decide how to handle integer overflow/underflow (e.g., if outside the `int` range, trigger an error).
   - Collect all numbers in a temporary array or list structure to check for duplicates.

3. **Check for Duplicates**  
   - If duplicates are found, handle according to project requirements (usually exit with an error).

4. **Finalize Storing of Values**  
   - After validation, store the values in your chosen data structure (linked list, double-linked list, or array).  
   - **Task**: Implement a function that appends each integer to the “stack a.”

---

## 3. **Data Structures**

1. **Decide on Singly vs. Doubly Linked List (or Array)**  
   - Weigh pros/cons:
     - **Singly Linked List**: simpler to implement, but may be less convenient for reverse rotates.
     - **Doubly Linked List**: easy to rotate in both directions but slightly more overhead.
     - **Dynamic Array**: simpler indexing, but might require more memory manipulations for certain operations.

2. **Implement the Chosen Data Structure**  
   - Define a `t_node` or `t_stack` struct (or an array-based approach).
   - Functions to:
     - Create a new node.
     - Append a node to the stack.
     - Pop/push elements (stack operations).
     - Print or debug the contents (optional for debugging).

---

## 4. **Core Operations (swaps, pushes, rotations)**

Implement each move as a separate function, each conforming to the project’s specification. For example:

1. **Swap**  
   - `sa`, `sb`, `ss`
2. **Push**  
   - `pa`, `pb`
3. **Rotate**  
   - `ra`, `rb`, `rr`
4. **Reverse Rotate**  
   - `rra`, `rrb`, `rrr`

**Tasks** for each operation:

- Write the logic that performs the operation on the data structure.
- Confirm edge cases (e.g., if there is only one element, do nothing).
- Print the corresponding move name (`"sa"`, `"sb"`, etc.) when executed (if printing is required immediately).

---

## 5. **Error Handling & Edge Cases**

1. **Edge Cases**  
   - No arguments or just one argument.
   - All numbers are already sorted.
   - Input containing invalid characters or outside allowed integer limits.
2. **Error Messages and Exit**  
   - Consistent error message / exit code as per project requirements.

---

## 6. **Check if Stack is Already Sorted**

- **Implement a `is_sorted` function**  
  - Quickly verify if the list/array is in ascending order.  
  - If sorted, your program can simply exit or do nothing (depending on the requirement).

---

## 7. **Sorting Logic for Small Sets (2 or 3 Elements, up to 5)**

1. **Sort 2 elements**  
   - If `a` has 2 elements, just swap if they are out of order.

2. **Sort 3 elements**  
   - Implement a small, direct algorithm with minimal moves.

3. **Sort up to 5 elements**  
   - Often done by a simple approach (like partial insertion sort or direct condition checks).

---

## 8. **Sorting Logic for Larger Sets**

1. **Decide on Your Main Algorithm**  
   - Common approaches:
     - **Radix Sort** (bitwise sorting)
     - **Quick Sort** based approach
     - **Merge Sort** approach
   - Some projects do a “chunk” approach (divide-and-conquer with partial sorting).

2. **Implement**  
   - The main logic for dividing stack `a` into smaller pieces, pushing/popping elements between stacks, etc.
   - Make sure to keep track of the moves so you can print them.

3. **Optimize (if needed)**  
   - You might need to refine your approach to reduce the number of moves (especially for large inputs).
   - Some solutions rely on refining or combining operations (`ra` followed by `rb` replaced by `rr`, etc.).

---

## 9. **Output**

1. **Printing Moves**  
   - Each time you perform a move (`sa`, `pb`, etc.), print it.
   - Ensure the format matches project requirements exactly.

2. **Handle No Moves**  
   - If the stack is already sorted and no moves are made, do you print nothing or handle differently?

---

## 10. **Checker (Optional or Mandatory Depending on Project)**

1. **Checker Program**  
   - Reads initial stack from input arguments.
   - Reads the list of operations from standard input (or file) until EOF.
   - Applies each operation to the stacks internally.
   - After all operations, check if stack `a` is sorted and stack `b` is empty.
   - Print `OK` or `KO` (or whatever the project requires).

2. **Integration**  
   - Make sure the checker and the push_swap program can work together, or at least test your push_swap output through your own checker.

---

## 11. **Testing & Debugging**

1. **Unit Tests for Each Operation**  
   - Test `sa`, `pa`, `ra`, etc. with small known stacks.

2. **Integration Tests**  
   - Run the program with various inputs (sorted, reverse-sorted, random).
   - Check the moves output and confirm the final stacks are as expected.

3. **Performance / Move Count**  
   - Check how many moves your program uses on typical or extreme cases (large input sets).
   - Compare to known bounds if you have them.

---

### Final Notes

- **Iterate**: Expect to revisit the design as you discover better ways to structure your operations or sorting logic.
- **Keep it Modular**: The more isolated your operations and sorting logic are, the easier it is to debug or extend.
- **Document**: Briefly comment your functions—especially ones that perform tricky pointer manipulations or sorting steps.  
- **Refactor**: If your code grows unwieldy, break out functions and keep each piece small and focused.

Good luck with your push_swap project!
