#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *s1 = dest;
  const char *s2 = src;
  while (n > 0) {
    *s1++ = *s2++;
    n--;
  }
  return dest;
}
