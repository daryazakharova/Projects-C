#include "s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  char *s = str;
  while (n > 0) {
    *s++ = (unsigned char)c;
    n--;
  }
  return str;
}
