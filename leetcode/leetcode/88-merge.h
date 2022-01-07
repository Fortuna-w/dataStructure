#pragma once
#include<iostream>
#include<vector>
using namespace std;

class Solution_Merge {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int len1 = nums1.size();
		int len2 = nums2.size();
		int* a = new int[len1 + 1];
		int x = 0;
		int y = 0;
		if (m == 0) {
			for (int i = 0; i < n; i++) {
				nums1[i] = nums2[i];
			}
		}
		else if (m == len1) {
		}
		else {
			for (int i = 0; i < len1; i++) {
				if ((x!=m)&&(y!=n)) {
					if (nums1[x] <= nums2[y]) {
						a[i] = nums1[x];
						x++;
					}
					else {
						a[i] = nums2[y];
						y++;
					}
				}
				else if((x!=m)&&(y==n)){
					a[i] = nums1[x];
					x++;
				}
				else if ((x == m) && (y != n)) {
					a[i] = nums2[y];
					y++;
				}
			}
			for (int i = 0; i < len1; i++) {
				nums1[i] = a[i];
			}
		}
	}

	//从后往前排
	void merge_1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int len = nums1.size();
		while (n > 0) {//nums2排完了就相当于全部排完了
			if ((m > 0) && nums1[m - 1] > nums2[n - 1]) {
				nums1[len - 1] = nums1[m - 1];
				m--;
				len--;
			}
			else {
				nums1[len - 1] = nums2[n - 1];
				n--;
				len--;
			}
		}
	}
};

void test_merge() {
	vector<int> nums1 = { 2,0 };
	vector<int> nums2 = { 1 };
	int m = 1;
	int n = 1;
	Solution_Merge s;
	//s.merge(nums1, m, nums2, n);
	s.merge_1(nums1, m, nums2, n);
	int len = nums1.size();
	for (int i = 0; i < len; i++) {
		cout << nums1[i] << endl;
	}
}