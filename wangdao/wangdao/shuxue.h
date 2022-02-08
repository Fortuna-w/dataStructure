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

//����ɸ��
const int MAXJ = 10001;
vector<int> prime;//��������
bool isPrime[MAXJ];//�������

void Initial() {
	//��ʼ��
	for (int i = 0; i < MAXJ; i++) {
		isPrime[i] = true;
	}
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i < MAXJ; i++) {
		//������������
		if (!isPrime[i]) {
			continue;
		}
		prime.push_back(i);
		for (int j = i * i; j < MAXJ; j += i) {
			//�����ı���Ϊ������
			isPrime[j] = false;
		}
	}
}

/*
	����һ������Ϊn��2<=n<=10000)��Ҫ��������д�1���������֮�䣨������1�������������λΪ1����������û�������-1.
*/
void func_Judge_2() {
	Initial();
	int n;
	while (scanf_s("%d", &n) != EOF) {
		bool isOutput = false;//�ж��Ƿ������
		for (int i = 0; i < prime.size() && prime[i] < n; i++) {
			if (prime[i] % 10 == 1) {
				isOutput = true;
				printf("%d ", prime[i]);
			}
		}
		if (!isOutput) {
			printf("-1");
		}
		printf("\n");
	}
}



const int MAXJ_1 = 1e3 + 1;//sqrt(1e9)+1------------����ʾ���ǳ���
vector<int> prime_1;//��������
bool isPrime_1[MAXJ_1];//�������

void Initial_1() {
	//��ʼ��
	for (int i = 0; i < MAXJ_1; i++) {
		isPrime_1[i] = true;
	}
	isPrime_1[0] = false;
	isPrime_1[1] = false;
	for (int i = 2; i < MAXJ_1; i++) {
		//������������
		if (!isPrime_1[i]) {
			continue;
		}
		prime_1.push_back(i);
		for (int j = i * i; j < MAXJ_1; j += i) {
			//�����ı���Ϊ������
			isPrime_1[j] = false;
		}
	}
}

//�������ĸ���
void func_Judge_3() {
	Initial_1();
	int n;
	while (scanf_s("%d", &n) != EOF) {
		int answer = 0;
		for (int i = 0; i < prime_1.size() && prime_1[i] < n; i++) {
			int factor = prime_1[i];
			while (n%factor == 0) {//�����Գ�
				n /= factor;
				answer++;
			}
		}
		if (n > 1) {//������һ��������
			answer++;
		}
		printf("%d\n", answer);
	}
}

//��A^B�������λ����ʾ������
/*
	���ģ�A^B�ĺ���λ����ʵֻ��A�ĺ���λ����B�й�
*/
int FastExponentiation(int a, int b, int mod) {
	int answer = 1;
	while (b != 0) {//���Ͻ�bת��Ϊ��������
		if (b % 2 == 1) {//����ǰλΪ1���۳�a��2^k����
			answer *= a;
			answer %= mod;//�����λ
		}
		b /= 2;
		a *= a;//a����ƽ��
		a %= mod;
	}
	return answer;
}

void func_FastExponentiation() {
	int a, b;
	while (scanf_s("%d%d", &a, &b) != EOF) {
		if (a == 0 && b == 0) {
			break;
		}
		printf("%d\n", FastExponentiation(a, b, 1000));
	}
}


//������������ĳ˻�
struct Matrix {
	int matrix[3][3];
	int row, col;//������
	Matrix(int r,int c):row(r),col(c){}  //���캯��
};
//����˷�
Matrix Multiply(Matrix x, Matrix y) {
	Matrix answer(x.row, y.col);
	for (int i = 0; i < answer.row; i++) {
		for (int j = 0; j < answer.col; j++) {
			answer.matrix[i][j] = 0;
			for (int k = 0; k < x.col; k++) {
				answer.matrix[i][j] += x.matrix[i][k] * y.matrix[k][j];
			}
		}
	}
	return answer;
}
//�������
void PrintMatrix(Matrix x) {//���û�н��������������
	for (int i = 0; i < x.row; ++i) {
		for (int j = 0; j < x.col; ++j) {
			printf("%d", x.matrix[i][j]);
		}
		printf("\n");
	}
}

void func_MatrixMultiply() {
	Matrix x(2, 3);
	Matrix y(3, 2);
	for (int i = 0; i < x.row; i++) {
		for (int j = 0; j < x.col; j++) {
			scanf_s("%d", &x.matrix[i][j]);
		}
	}
	for (int i = 0; i < y.row; i++) {
		for (int j = 0; j < y.col; j++) {
			scanf_s("%d", &y.matrix[i][j]);
		}
	}
	Matrix answer = Multiply(x, y);
	PrintMatrix(answer);
}


//����һ��n*n�ľ���P����þ����k����
struct Matrix_1 {
	int matrix[10][10];
	int row, col;//������
	Matrix_1(int r, int c) :row(r), col(c) {}  //���캯��
};

Matrix_1 Multiply(Matrix_1 x, Matrix_1 y) {
	Matrix_1 answer(x.row, y.col);
	for (int i = 0; i < answer.row; i++) {
		for (int j = 0; j < answer.col; j++) {
			answer.matrix[i][j] = 0;
			for (int k = 0; k < x.col; k++) {
				answer.matrix[i][j] += x.matrix[i][k] * y.matrix[k][j];
			}
		}
	}
	return answer;
}

void PrintMatrix_1(Matrix_1 x) {
	for (int i = 0; i < x.row; i++) {
		for (int j = 0; j < x.col; j++) {
			if (j != 0) {
				printf(" ");
			}
			printf("%d", x.matrix[i][j]);
		}
		printf("\n");
	}
}

Matrix_1 FastExponentiation(Matrix_1 x,int k) {
	Matrix_1 answer(x.row, x.col);
	for (int i = 0; i < answer.row; i++) {
		for (int j = 0; j < answer.col; j++) {
			if (i == j) {
				answer.matrix[i][j] = 1;
			}
			else {
				answer.matrix[i][j] = 0;
			}
		}
	}
	while (k != 0) {
		if (k % 2 == 1) {
			answer = Multiply(answer, x);
		}
		k /= 2;
		x = Multiply(x, x);
	}
	return answer;
}

void func_MatrixFastExponentiation() {
	int n, k;
	while (scanf_s("%d%d", &n, &k) != EOF) {
		Matrix_1 x(n, n);
		for (int i = 0; i < x.row; i++) {
			for (int j = 0; j < x.col; j++) {
				scanf_s("%d", &x.matrix[i][j]);
			}
		}
		Matrix_1 answer = FastExponentiation(x, k);
		PrintMatrix_1(answer);
	}
}


//�߾�������
const int MAXB = 10000;
struct BigInteger {
	int digit[MAXB];
	int length;
	BigInteger();
	BigInteger(int x);
	BigInteger(string str);
	BigInteger(const BigInteger& b);
	BigInteger operator=(int x);
	BigInteger operator=(string str);
	BigInteger operator=(const BigInteger& b);
	bool operator<=(const BigInteger& b);
	bool operator==(const BigInteger& b);
	BigInteger operator+(const BigInteger& b);
	BigInteger operator-(const BigInteger& b);
	BigInteger operator*(const BigInteger& b);
	BigInteger operator/(const BigInteger& b);
	BigInteger operator%(const BigInteger& b);
	friend istream& operator>>(istream& in, BigInteger& x);
	friend ostream& operator<<(ostream& out, const BigInteger& x);
};

istream& operator>>(istream& in, BigInteger& x) {
	string str;
	cin >> str;
	x = str;
	return in;
}

ostream& operator<<(ostream& out, const BigInteger& x) {
	for (int i = x.length - 1; i >= 0; i--) {
		out << x.digit[i];
	}
	return out;
}

BigInteger::BigInteger() {
	memset(digit, 0, sizeof(digit));
	length = 0;
}

BigInteger::BigInteger(int x) {
	memset(digit, 0, sizeof(digit));
	length = 0;
	if (x == 0) {
		digit[length++] = x;
	}
	while (x != 0) {
		digit[length++] = x % 10;
		x /= 10;
	}
}

BigInteger::BigInteger(string str) {
	memset(digit, 0, sizeof(digit));
	length = str.size();
	for (int i = 0; i < length; i++) {
		digit[i] = str[length - i - 1] - '0';
	}
}

BigInteger::BigInteger(const BigInteger& b) {
	memset(digit, 0, sizeof(digit));
	length = b.length;
	for (int i = 0; i < length; i++) {
		digit[i] = b.digit[i];
	}
}

BigInteger BigInteger::operator=(int x) {
	memset(digit, 0, sizeof(digit));
	length = 0;
	if (x == 0) {
		digit[length++] = x;
	}
	while (x != 0) {
		digit[length++] = x % 10;
		x /= 10;
	}
	return *this;
}

BigInteger BigInteger::operator=(string str) {
	memset(digit, 0, sizeof(digit));
	length = str.size();
	for (int i = 0; i < length; i++) {
		digit[i] = str[length - i - 1] - '0';
	}
	return *this;
}

BigInteger BigInteger::operator=(const BigInteger& b) {
	memset(digit, 0, sizeof(digit));
	length = b.length;
	for (int i = 0; i < length; i++) {
		digit[i] = b.digit[i];
	}
	return *this;
}

bool BigInteger::operator<=(const BigInteger& b) {
	if (length < b.length) {
		return true;
	}
	else if (b.length < length) {
		return false;
	}
	else {
		for (int i = length - 1; i >= 0; i--) {
			if (digit[i] == b.digit[i]) {
				continue;
			}
			else {
				return digit[i] < b.digit[i];
			}
		}
	}
	return true;
}

bool BigInteger::operator==(const BigInteger& b) {
	if (length != b.length) {
		return false;
	}
	else {
		for (int i = length - 1; i >= 0; i--) {
			if (digit[i] != b.digit[i]) {
				return false;
			}
		}
	}
	return true;
}

BigInteger BigInteger::operator+(const BigInteger& b) {
	BigInteger answer;
	int carry = 0;
	for (int i = 0; i < length || i < b.length; i++) {
		int current = carry + digit[i] + b.digit[i];
		carry = current / 10;
		answer.digit[answer.length++] = current % 10;
	}
	if (carry != 0) {
		answer.digit[answer.length++] = carry;
	}
	return answer;
}

BigInteger BigInteger::operator-(const BigInteger& b) {
	BigInteger answer;
	int carry = 0;
	for (int i = 0; i < length; i++) {
		int current = digit[i] - b.digit[i] - carry;
		if (current < 0) {
			current += 10;
			carry = 1;
		}
		else {
			carry = 0;
		}
		answer.digit[answer.length++] = current;
	}
	while (answer.digit[answer.length] == 0 && answer.length > 1) {
		answer.length--;
	}
	return answer;
}

BigInteger BigInteger::operator*(const BigInteger& b) {
	BigInteger answer;
	answer.length = length + b.length;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < b.length; j++) {
			answer.digit[i + j] += digit[i] * b.digit[j];
		}
	}
	for (int i = 0; i < answer.length; i++) {
		answer.digit[i + 1] += answer.digit[i] / 10;
		answer.digit[i] %= 10;
	}
	while (answer.digit[answer.length] == 0 && answer.length > 1) {
		answer.length--;
	}
	return answer;
}

BigInteger BigInteger::operator/(const BigInteger& b) {
	BigInteger answer;
	answer.length = length;
	BigInteger remainder = 0;
	BigInteger temp = b;
	for (int i = length - 1; i >= 0; i--) {
		if (!(remainder.length == 1 && remainder.digit[0] == 0)) {
			for (int j = remainder.length - 1; j >= 0; j--) {
				remainder.digit[j + 1] = remainder.digit[j];
			}
			remainder.length++;
		}
		remainder.digit[0] = digit[i];
		while (temp <= remainder) {
			remainder = remainder - temp;
			answer.digit[i]++;
		}
	}
	while (answer.digit[answer.length] == 0 && answer.length > 1) {
		answer.length--;
	}
	return answer;
}

BigInteger BigInteger::operator%(const BigInteger& b) {
	BigInteger remainder = 0;
	BigInteger temp = b;
	for (int i = length - 1; i >= 0; i--) {
		if (!(remainder.length == 1 && remainder.digit[0] == 0)) {
			for (int j = remainder.length - 1; j >= 0; j--) {
				remainder.digit[j + 1] = remainder.digit[j];
			}
			remainder.length++;
		}
		remainder.digit[0] = digit[i];
		while (temp <= remainder) {
			remainder = remainder - temp;
		}
	}
	return remainder;
}

void func_BigAdd() {
	BigInteger a, b;
	while (cin >> a >> b) {
		cout << a + b << endl;
	}
}

void func_BigFactorial() {
	int n;
	while (scanf_s("%d", &n) != EOF) {
		BigInteger answer(1);
		for (int i = 1; i <= n; i++) {
			answer = answer * BigInteger(i);
		}
		cout << answer << endl;
	}
}