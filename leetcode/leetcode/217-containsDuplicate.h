#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution_ContainsDuplicate {
public:
	bool containsDuplicate(vector<int>& nums) {
		vector<int> a(nums.size(), 0);
		bool temp;
		int count = 0;
		int len1 = nums.size();
		int len2 = a.size();
		for (int i = 0; i < len1; i++) {
			a[nums[i] - 1]++;
		}
		for (int j = 0; j < len2; j++) {
			if (a[j] != 1) {
				count += 0;
			}
			else {
				count++;
			}
		}
		if (count == a.size()) {
			temp = false;
		}
		else {
			temp = true;
		}
		return temp;
	}

	bool containsDuplicate_1(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		for (int i = 0; i < n - 1; i++) {
			if (nums[i] == nums[i + 1]) {
				return true;
			}
		}
		return false;
	}
};

void test_containsDuplicate() {
	vector<int> a = { 1,2,3,1 };
	Solution_ContainsDuplicate s;
	cout << s.containsDuplicate(a) << endl;

}