#pragma once
#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;


//ʮ����ת���ɶ�����
//unsigned int��ת������
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
		for (int i = binary.size() - 1; i >= 0; i--) {//�������
			printf("%d", binary[i]);
		}
		printf("\n");
	}
}


//��һ���������Ϊ30λ���ֵ�ʮ���ƷǸ�����ת��Ϊ������
/*
	ע��㣺30λ���֣�����޷������������������������룬��Ҫ���ַ�����ģ�����֡�
	����ȡģ���㣬���Խ���ת��Ϊ���ַ����е������λ����ȡģ���㡣
	����ȡ�����㣬���ַ����Ӹߵ�����λ���Գ��������ĳλ������������ô�ͱ��������Գ�����������
��������10��͵�һλһ����д���
	��ע����������ܻ�ǰ�ö����0��ֻ��ȡ�׸���0λ֮����ַ�����
*/
//�ַ�������
string Divide(string str, int x) {
	int remainder = 0;//��������
	for (int i = 0; i < str.size(); i++) {
		int current = remainder * 10 + str[i] - '0';
		str[i] = current / x + '0';
		remainder = current % x;
	}
	int pos = 0;
	while (str[pos] == '0') {//Ѱ���׸���0�±�
		pos++;
	}
	return str.substr(pos);//ɾ��ǰ�ö����0
}

void ten2two() {
	string str;
	while (cin >> str) {
		vector<int> binary;
		while (str.size() != 0) {
			int last = str[str.size() - 1] - '0';//���λ��ֵ
			binary.push_back(last % 2);//ȡģ����
			str = Divide(str, 2);//��������
		}
		for (int i = binary.size() - 1; i >= 0; i--) {
			printf("%d", binary[i]);
		}
		printf("\n");
	}
}

//�ַ����˷�
/*
	���ģ����ַ����ӵ͵�����λ���Գ��������ĳλ���Գ����󳬹���10����ô�������10ȡģ����������λ��
֮�󣬽���λ�͸�һλһ����д���
*/
string Multiple(string str, int x) {
	int carry = 0;//�����λ
	for (int i = str.size() - 1; i >= 0; i--) {
		int current = x*(str[i] - '0') + carry;
		str[i] = current % 10 + '0';
		carry = current / 10;
	}
	if (carry != 0) {//���н�λ
		str = "1" + str;
	}
	return str;
}

//�ַ����ӷ�
string Add(string str, int x) {
	int carry = x;
	for (int i = str.size() - 1; i >= 0; i--) {
		int current = (str[i] - '0') + carry;
		str[i] = current % 10 + '0';
		carry = current / 10;
	}
	if (carry != 0) {//���н�λ
		str = "1" + str;
	}
	return str;
}

void ten2two2ten() {
	string str;
	while (cin >> str) {
		vector<int> binary;
		while (str.size() != 0) {
			int last = str[str.size() - 1] - '0';//���λ��ֵ
			binary.push_back(last % 2);//ȡģ����
			str = Divide(str, 2);//��������
		}
		string answer = "0";
		for (int i = 0; i < binary.size(); i++) {
			answer = Multiple(answer, 2);//�˷�����
			answer = Add(answer, binary[i]);//�ӷ�����
		}
		cout << answer << endl;
	}
}


//����ת�ַ�
char IntToChar(int x) {
	if (x < 10) {
		return x + '0';
	}
	else {
		return x - 10 + 'a';
	}
}

//�ַ�ת����
int CharToInt(char c) {
	if (c >= '0'&&c <= '9') {
		return c - '0';
	}
	else {
		return c - 'a' + 10;
	}
}

//M����ת����N����
void M2N() {
	int m, n;
	scanf_s("%d%d", &m, &n);
	string str;
	cin >> str;
	long long number = 0;
	for (int i = 0; i < str.size(); i++) {//m����תʮ����
		number *= m;
		number += CharToInt(str[i]);
	}
	vector<char> answer;
	while (number != 0) {//ʮ����תn����
		answer.push_back(IntToChar(number % n));
		number /= n;
	}
	for (int i = answer.size() - 1; i >= 0; i--) {//�������
		printf("%c", answer[i]);
	}
	printf("\n");
}



//���Լ��
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

//��С������
int LCM(int a, int b) {
	return a*b / GCD(a, b);
}

void fun_LCM() {
	int a, b;
	while (scanf_s("%d%d", &a, &b) != EOF) {
		printf("%d\n", LCM(a, b));
	}
}


//�ж�����
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