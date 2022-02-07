#pragma once
#include<string>
using namespace std;

const int MAXN = 10000;
const int MAXM = 1000;

int nextTable[MAXM];
int nextvalTable[MAXM];
int pattern[MAXM];
int text[MAXN];

//创建next表
void GetNextTable(string pattern) {
	int m = pattern.size();
	int j = 0;
	nextTable[j] = -1;
	int i = nextTable[j];
	while (j < m) {
		if (i == -1 || pattern[j] == pattern[i]) {
			i++;
			j++;
			nextTable[j] = i;
		}
		else
		{
			i = nextTable[i];
		}
	}
}

void GetNextvalTable(string pattern) {
	int m = pattern.size();
	int j = 0;
	nextvalTable[j] = -1;
	int i = nextvalTable[j];
	while (j < m) {
		if (i == -1 || pattern[j] == pattern[i]) {
			i++;
			j++;
			if (pattern[j] != pattern[i]) {
				nextvalTable[j] = i;
			}
			else {
				nextvalTable[j] = nextvalTable[i];
			}
		}
		else {
			i = nextvalTable[i];
		}
	}
}

int KMP(string text,string pattern) {
	int n = text.size();
	int m = pattern.size();
	GetNextTable(pattern);
	int i = 0;
	int j = 0;
	while (i < n&&j < m) {
		if (j == -1 || text[i] == pattern[j]) {//当前字符匹配成功
			i++;
			j++;
		}
		else {
			j = nextTable[j];//当前字符匹配失败
		}
	}
	if (j == m) {
		return i - j ;//模式串匹配成功
	}
	else {
		return -1;//模式串匹配失败
	}
}