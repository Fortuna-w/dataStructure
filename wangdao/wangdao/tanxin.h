#pragma once
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

/*
	鸡兔同笼
*/
void func_RJ() {
	int a;
	while (scanf_s("%d", &a) != EOF) {
		int minnum = 0;
		int maxnum = 0;
		if (a % 2 == 0) {
			minnum = a / 4 + (a % 4) / 2;
			maxnum = a / 2;
		}
		printf("%d %d\n", minnum, maxnum);
	}
}

/*
	FatMouse'Trade
*/
const int MAXF = 1000;

struct JavaBean {
	double weight;
	double cost;
};

JavaBean arr[MAXF];

bool Compare(JavaBean x,JavaBean y) {
	return (x.weight / x.cost) > (y.weight / y.cost);
}

void func_FMT() {
	int m, n;
	while (scanf_s("%d%d", &m, &n) != EOF) {
		if (m == -1 && n == -1) {
			break;
		}
		for (int i = 0; i < n; i++) {
			scanf_s("%lf%lf", &arr[i].weight, &arr[i].cost);
		}
		sort(arr, arr + n, Compare);//性价比降序排序
		double answer = 0;
		for (int i = 0; i < n; i++) {
			if (m >= arr[i].cost) {//全部买下
				m -= arr[i].cost;
				answer += arr[i].weight;
			}
			else {//只能买下部分
				answer += arr[i].weight*(m / arr[i].cost);
				break;
			}
		}
		printf("%.3f\n", answer);
	}
}


/*
	Senior's Gun
*/
const int MAXS = 100001;

long long gun[MAXS];
long long monstor[MAXS];

bool Compare_1(long long x, long long y) {
	return x > y;
}

void func_SG() {
	int caseNumber;
	scanf_s("%d", &caseNumber);
	while (caseNumber--) {
		int n, m;
		scanf_s("%d%d", &n, &m);
		for (int i = 0; i < n; i++) {
			scanf_s("%lld", &gun[i]);
		}
		for (int i = 0; i < m; i++) {
			scanf_s("%lld", &monstor[i]);
		}
		sort(gun, gun + n, Compare_1);//枪从大到小排序
		sort(monstor, monstor + m);//怪物从小到大排序
		long long answer = 0;
		for (int i = 0; i < n; i++) {
			if (i >= m || gun[i] <= monstor[i]) {
				break;
			}
			answer += (gun[i] - monstor[i]);
		}
		printf("%lld\n", answer);
	}
}