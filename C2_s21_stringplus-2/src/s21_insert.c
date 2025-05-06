#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *result = s21_NULL;
  if (src && str) {
    s21_size_t lenghtSrc = s21_strlen(src);
    s21_size_t lenghtStr = s21_strlen(str);
    s21_size_t lenghtRes = lenghtSrc + lenghtStr;
    if (start_index <= lenghtSrc)
      result = (char *)calloc(lenghtRes, sizeof(char) + 1);
    if (result) {
      for (s21_size_t i = 0; i < lenghtRes; i++) {
        if (i < start_index) {
          result[i] = src[i];
        } else if (i < lenghtStr + start_index) {
          result[i] = str[i - start_index];
        } else {
          result[i] = src[i - lenghtStr];
        }
      }
    }
  }
  return (void *)result;
}
