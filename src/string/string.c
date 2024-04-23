// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */

	int x = strlen(source);
	for (int i = 0; i < x; i++)
		destination[i] = source[i];

	destination[x] = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */

	for (int i = 0; i < (int)len; i++)
		destination[i] = source[i];

	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */

	int x = strlen(destination);
	for (int i = 0; i < (int)strlen(source); i++) {
		destination[x + i] = source[i];
	}
	destination[x + strlen(source)] = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */

	int x = strlen(destination);
	for (int i = 0; i < (int)len; i++) {
		destination[x + i] = source[i];
	}
	destination[x + len] = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	for (int i = 0; i < (int)strlen(str1); i++)
        if (str1[i] != str2[i]) {
            if (str1[i] - 'A' < str2[i] - 'A')
                return (-1);
            else
                return 1;
        }
	if (strlen(str1) == strlen(str2)) {
        return 0;
    } else {
        if (strlen(str1) > strlen(str2))
            return 1;
        else
            return -1;
    }
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	for (int i = 0; i < (int)len; i++) {
		if (str1[i] != str2[i]) {
			if (str1[i] - 'A' < str2[i] - 'A')
				return (-1);
			else
				return 1;
		}
	}
	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	for (int i = 0; i < (int)strlen(str); i++) {
		if (*(str + i)== (char)c) {
			return ((char *)(str + i));
		}
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */

	for (int i =(int)strlen(str) - 1; i >= 0; i--) {
		if (*(str + i)== (char)c) {
			return ((char *)(str + i));
		}
	}
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	for (int i = 0; i < (int)strlen(haystack); i++) {
		if (*(needle) == *(haystack + i)) {
			int k = 1;
			for (int j = i + 1; j <= i + (int)strlen(needle) - 1; j++) {
				if (*(needle + k) == *(haystack + j)) {
					k++;
				} else {
					break;
				}
			}
			if (k == (int)strlen(needle))
				return ((char *)(haystack + i));
		}
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	for (int i = strlen(haystack) - 1 - strlen(needle); i >= 0; i--) {
		if (*(needle) == *(haystack + i)) {
			int k = 1;
			for (int j = i + 1; j <= i + (int)strlen(needle) - 1; j++) {
				if (*(needle + k) == *(haystack + j)) {
					k++;
				} else {
					break;
				}
			}
			if (k == (int)strlen(needle))
				return ((char *)(haystack + i));
		}
	}
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *dest = (char *)destination;
	char *src = (char *)source;
	int k = 0;
	while (k < (int)num) {
		dest[k] = src[k];
		k++;
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *dest = (char *)destination;
	char * src = (char *)source;
	int k = 0;
	while (k < (int)num) {
		dest[k]= src[k];
		k++;
	}
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	char *p1, *p2;
	p1 = (char *)ptr1;
	p2 = (char *)ptr2;
	int k = 0;
	while (k < (int)num) {
		if (p1[k] != p2[k]) {
			return -1;
		}
		k++;
	}
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	char *src;
	src = (char *)source;
    for (int i = 0; i < (int)num; i++) {
        src[i] = value;
    }
    return source;
}
