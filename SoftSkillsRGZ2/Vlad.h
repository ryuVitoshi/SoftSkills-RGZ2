#pragma once

#include <string.h>

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