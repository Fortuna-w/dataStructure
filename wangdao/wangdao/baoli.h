#pragma once
#include<stdio.h>

void abc() {
	int a, b, c;
	for (a = 1; a < 10; a++) {
		for (b = 1; b < 10; b++) {
			for (c = 0; c < 10; c++) {
				if (a * 100 + b * 110 + c * 12 == 532) {
					printf("%d %d %d\n", a, b, c);
				}
			}
		}
	}
}

//Çó·´ÐòÊý
int Reverse(int x) {
	int res = 0;
	while (x != 0) {
		res = res * 10;
		res += x % 10;
		x = x / 10;
	}
	return res;
}

void test_Reverse() {
	for (int i = 1000; i <= 1111; i++) {
		if (i * 9 == Reverse(i)) {
			printf("%d\n",i);
		}
	}
}

void test_Symmetry() {
	for (int i = 0; i <= 256; i++) {
		if (i*i == Reverse(i*i)) {
			printf("%d\n", i);
		}
	}
}