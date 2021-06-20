#pragma once

#include <string.h>

void reduceString(char* str, int size, int pos, int c) {
	int l = strlen(str);
	int x = l - size + c;
	for (int i = 0; i < c; i++)
		str[pos + i] = '.';
	strcpy(str + pos + c, str + pos + x);
}

void compare(char** str, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (strcmp(str[i], str[j]) == 0) {
				int len = strlen(str[j]);
				str[j][len] = '1';
				str[j][len + 1] = '\0';
			}
		}
	}
}