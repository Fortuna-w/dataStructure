#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

#include"p103-Ranking.h"
using namespace std;

void test1() {
	// 初始化小顶堆
	priority_queue<int, vector<int>, less<int>> heap;   //vs2015的v140好像只有默认less，没有greater

	// 元素入堆
	heap.push(1);
	heap.push(10);
	heap.push(2);
	heap.push(6);
	heap.push(8);

	// 元素出堆（从小到大）
	for (int i = 0; i < 5; i++) {
		cout << heap.top() << endl;
		heap.pop();
	}
}

void test2() {
	//数组
	int a[5];
	int n;
	for (int i = 0; i < 5; i++) {
		scanf_s("%d", &n);
		a[i] = n;
	}
	for (int i = 0; i < 5; i++) {
		cout << "a["<<i<<"]="<< a[i];
		cout << endl;
		//printf("a[%d]=%d\n", i, a[i]);
	}
	vector<int> arr;
	arr.push_back(1);
	arr.push_back(4);
	arr.push_back(9);
	arr.push_back(16);
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << endl;
	}
	vector<int>::iterator t;
	for (t = arr.begin(); t != arr.end(); t++) {
		cout << *t << endl;
	}

}


int main() {
	

	//test1();

	//test2();

	test_ranking();

	return 0;
}

