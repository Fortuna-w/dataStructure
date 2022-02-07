#pragma once
#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;


//十进制转换成二进制
//unsigned int数转二进制
void ten2er() {
	unsigned int n;
	while (scanf_s("%d", &n) != EOF) {
		vector<int> binary;
		if (n == 0) {
			binary.push_back(0);
		}
		else {
			while (n != 0) {
				binary.push_back(n % 2);
				n /= 2;
			}
		}
		for (int i = binary.size() - 1; i >= 0; i--) {//逆序输出
			printf("%d", binary[i]);
		}
		printf("\n");
	}
}


//将一个长度最多为30位数字的十进制非负整数转换为二进制
/*
	注意点：30位数字，因此无法再用整型数来保存该题的输入，而要用字符串来模拟数字。
	对于取模运算，可以将其转换为对字符串中的最低数位进行取模运算。
	对于取整运算，把字符串从高到低逐位除以除数。如果某位不能整除，那么就保留它除以除数的余数，
余数乘以10后和低一位一起进行处理。
	需注意该做法可能会前置多余的0，只需取首个非0位之后的字符串。
*/
//字符串除法
string Divide(string str, int x) {
	int remainder = 0;//保存余数
	for (int i = 0; i < str.size(); i++) {
		int current = remainder * 10 + str[i] - '0';
		str[i] = current / x + '0';
		remainder = current % x;
	}
	int pos = 0;
	while (str[pos] == '0') {//寻找首个非0下标
		pos++;
	}
	return str.substr(pos);//删除前置多余的0
}

void ten2two() {
	string str;
	while (cin >> str) {
		vector<int> binary;
		while (str.size() != 0) {
			int last = str[str.size() - 1] - '0';//最低位的值
			binary.push_back(last % 2);//取模运算
			str = Divide(str, 2);//整除运算
		}
		for (int i = binary.size() - 1; i >= 0; i--) {
			printf("%d", binary[i]);
		}
		printf("\n");
	}
}

//字符串乘法
/*
	核心：将字符串从低到高逐位乘以乘数。如果某位乘以乘数后超过了10，那么就让其对10取模，并保留进位。
之后，将进位和高一位一起进行处理。
*/
string Multiple(string str, int x) {
	int carry = 0;//保存进位
	for (int i = str.size() - 1; i >= 0; i--) {
		int current = x*(str[i] - '0') + carry;
		str[i] = current % 10 + '0';
		carry = current / 10;
	}
	if (carry != 0) {//仍有进位
		str = "1" + str;
	}
	return str;
}

//字符串加法
string Add(string str, int x) {
	int carry = x;
	for (int i = str.size() - 1; i >= 0; i--) {
		int current = (str[i] - '0') + carry;
		str[i] = current % 10 + '0';
		carry = current / 10;
	}
	if (carry != 0) {//仍有进位
		str = "1" + str;
	}
	return str;
}

void ten2two2ten() {
	string str;
	while (cin >> str) {
		vector<int> binary;
		while (str.size() != 0) {
			int last = str[str.size() - 1] - '0';//最低位的值
			binary.push_back(last % 2);//取模运算
			str = Divide(str, 2);//整除运算
		}
		string answer = "0";
		for (int i = 0; i < binary.size(); i++) {
			answer = Multiple(answer, 2);//乘法运算
			answer = Add(answer, binary[i]);//加法运算
		}
		cout << answer << endl;
	}
}


//数字转字符
char IntToChar(int x) {
	if (x < 10) {
		return x + '0';
	}
	else {
		return x - 10 + 'a';
	}
}

//字符转数字
int CharToInt(char c) {
	if (c >= '0'&&c <= '9') {
		return c - '0';
	}
	else {
		return c - 'a' + 10;
	}
}

//M进制转换成N进制
void M2N() {
	int m, n;
	scanf_s("%d%d", &m, &n);
	string str;
	cin >> str;
	long long number = 0;
	for (int i = 0; i < str.size(); i++) {//m进制转十进制
		number *= m;
		number += CharToInt(str[i]);
	}
	vector<char> answer;
	while (number != 0) {//十进制转n进制
		answer.push_back(IntToChar(number % n));
		number /= n;
	}
	for (int i = answer.size() - 1; i >= 0; i--) {//逆序输出
		printf("%c", answer[i]);
	}
	printf("\n");
}



//最大公约数
int GCD(int a,int b) {
	if (b == 0) {
		return a;
	}
	else {
		return GCD(b, a%b);
	}
}

void fun_GCD() {
	int a, b;
	while (scanf_s("%d%d", &a, &b) != EOF) {
		printf("%d\n", GCD(a, b));
	}
}

//最小公倍数
int LCM(int a, int b) {
	return a*b / GCD(a, b);
}

void fun_LCM() {
	int a, b;
	while (scanf_s("%d%d", &a, &b) != EOF) {
		printf("%d\n", LCM(a, b));
	}
}


//判断质数
bool Judge(int x) {
	if (x < 2) {
		return false;
	}
	int bound = sqrt(x);
	for (int i = 2; i <= bound; i++) {
		if (x % 2 == 0) {
			return false;
		}
	}
	return true;
}

void fun_Judge() {
	int n;
	while (scanf_s("%d", &n) != EOF) {
		if (Judge(n)) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	}
}