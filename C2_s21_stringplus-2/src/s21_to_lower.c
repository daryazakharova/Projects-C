#include "s21_string.h"

void *s21_to_lower(const char *str) {
  char *result = s21_NULL;
  if (str) {
    s21_size_t lenghtStr = s21_strlen(str);
    result = calloc(lenghtStr + 1, sizeof(char));
    if (result) {
      for (s21_size_t i = 0; i < lenghtStr; i++) {
        result[i] = str[i];
        if (result[i] >= 65 && result[i] <= 90)
          result[i] = (result[i] + 32);
        else
          result[i] = result[i];
      }
      result[lenghtStr] = '\0';
    }
  }
  return (void *)result;
}
