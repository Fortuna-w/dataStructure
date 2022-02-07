#pragma once
#include<stdio.h>


void print() {
	int h;
	while (scanf_s("%d", &h) != EOF) {
		int row = h;
		int col = h + (h - 1) * 2;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (j < col - (h + 2 * i)) {
					printf(" ");
				}
				else {
					printf("*");
				}
			}
			printf("\n");
		}
	}

}

