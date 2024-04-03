#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Alice forgot her card's PIN code.She remembers that her PIN code had 4 digits, all the digits were distinct and in decreasing order, and that the sum of these digits was 24. 
// This C program that prints, on different lines, all the PIN codes which fulfill these constraints. 

int main(int argc, char* argv[]) {
	for (int i = 9; i >= 1; i--) {
		for (int j = 8; j >= 1; j--) {
			for (int k = 7; k >= 1; k--) {
				for (int l = 6; l >= 1; l--) {
					if (i + j + k + l == 24) {
						printf("%d%d%d%d\n", i, j, k, l);
					}
				}
			}
		}
	}
	return 0;
}

