#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *result = s21_NULL;
  if (src) {
    char *ptrRes = (char *)src;
    char *endRes = (char *)src + s21_strlen(src);
    if (!trim_chars || trim_chars[0] == '\0') {
      trim_chars = "\t\n ";
    }
    while (*ptrRes && s21_strchr(trim_chars, *ptrRes)) ptrRes++;

    while (endRes != ptrRes && s21_strchr(trim_chars, *(endRes - 1))) endRes--;

    result = (char *)calloc((endRes - ptrRes + 1), sizeof(char));
    if (result) {
      s21_strncpy(result, ptrRes, endRes - ptrRes);
      *(result + (endRes - ptrRes)) = '\0';
    }
  }
  return (void *)result;
}
