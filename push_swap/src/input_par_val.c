#include "../include/push_swap.h"

// CHULETA static  char    *get_next_word(char *s, char c)
// siendo char *s la cadena completa y c el delimitador
// declarar cursor (static) = 0, len = 0, i = 0;
// avanzar cursor en s mientras estemos en el delimitador
// avanzar len si s[cursor + len] no se el delimitador (no avanza el cursor)
// reservar espacio next_word para len (para la palabra) con malloc y proteger
// ahora sí avanzar cursor e ir rellenando next_word[i++] con s[cursor++]
// null terminate next_word
// devolver next_word