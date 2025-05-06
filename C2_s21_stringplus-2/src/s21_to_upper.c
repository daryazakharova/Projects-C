#include "s21_string.h"

char *s21_to_upper(const char *str) {
  char *result = s21_NULL;
  if (str) {
    int lenghtStr = (int)s21_strlen(str) + 1;
    result = calloc(lenghtStr, sizeof(char));
    if (result) {
      for (int i = 0; i < lenghtStr; i++) {
        if (str[i] >= 97 && str[i] <= 122)
          result[i] = (str[i] - 32);
        else
          result[i] = str[i];
      }
      result[lenghtStr - 1] = '\0';
    }
  }
  return result;
}
