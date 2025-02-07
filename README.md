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

Entonces el procedimiento es hacer un join de todos los argumentos (comprobar que solo tengo '-', ' ' y números) y luego hacer un split por ' '. 
TODO: Revisar requisitos y ver como usa la chica del video casos límite (usa long long en algún momento)
