#pragma once

#include <string.h>
//#include "Vlad.h"

bool reduce(char** str, int n, int size, int i) {
	if (i == n) return true;

	char* tmp = new char[256];
	bool unique;

	int c = 3;
	if (size == 3) c = 2;
	else if (size == 2) c = 1;
	for (; c > 0; c--) {
		for (int pos = 0; pos <= size - c; pos++) {
			strcpy(tmp, str[i]);
			//reduceString(str[i], size, pos, c);
			unique = true;

			for (int j = 0; j < i; j++) {
				if (strcmp(str[i], str[j]) == 0) {
					unique = false;
					break;
				}
			}

			if (!unique) {
				strcpy(str[i], tmp);
			}
			else {
				if (reduce(str, n, size, i + 1)) {
					delete[] tmp;
					return true;
				}
				else {
					strcpy(str[i], tmp);
				}
			}
		}
	}
	return false;
}