#include <stdio.h>
#include <stdlib.h>

#ifndef S21_STRING_H
#define S21_STRING_H
#define s21_size_t unsigned long long
#define s21_NULL (void *)0
#endif

s21_size_t s21_strlen(const char *str);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_to_lower(const char *str);
char *s21_to_upper(const char *str);
void *s21_trim(const char *src, const char *trim_chars);

