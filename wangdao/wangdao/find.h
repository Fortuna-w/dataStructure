#pragma once


const int MAXN = 100;
int arr[MAXN];
//二分查找
bool BinarySearch(int n, int target) {
	int left = 0;
	int right = n - 1;
	while (left <= right) {
		//int middle = (left + right) / 2;
		int middle = left + (right - left) / 2;//中间位置
		if (arr[middle] < target) {//小于关键字，舍弃左边
			left = middle + 1;
		}
		else if (arr[middle]>target) {//大于关键字，舍弃右边
			right = middle - 1;
		}
		else {
			return true;//查找成功
		}
	}
	return false;
}