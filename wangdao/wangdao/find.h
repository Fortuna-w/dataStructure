#pragma once


const int MAXN = 100;
int arr[MAXN];
//���ֲ���
bool BinarySearch(int n, int target) {
	int left = 0;
	int right = n - 1;
	while (left <= right) {
		//int middle = (left + right) / 2;
		int middle = left + (right - left) / 2;//�м�λ��
		if (arr[middle] < target) {//С�ڹؼ��֣��������
			left = middle + 1;
		}
		else if (arr[middle]>target) {//���ڹؼ��֣������ұ�
			right = middle - 1;
		}
		else {
			return true;//���ҳɹ�
		}
	}
	return false;
}