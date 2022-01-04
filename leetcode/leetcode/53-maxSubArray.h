#pragma once
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution_MaxSubArray {
public:
	int maxSubArray(vector<int>& nums) {
		int maxSum = nums[0];
		int temp = 0;
		int len = nums.size();
		for (int i = 0; i < len; i++) {
			temp = max(nums[i], nums[i] + temp);
			maxSum = max(maxSum, temp);
		}
		return maxSum;
	}

	int maxSubArray_1(vector<int>& nums) {
		int len = nums.size();
		vector<int> dp(len);
		int maxSum = dp[0] = nums[0];
		for (int i = 1; i < len; i++) {
			dp[i] = max(nums[i] + dp[i - 1], nums[i]);
			maxSum = max(dp[i], maxSum);
		}
		return maxSum;
	}

	int maxSubArray_2(vector<int>& nums) {
		int len = nums.size();
		vector<int> dp(len);
		int maxSum = dp[0] = nums[0];
		for (int i = 1; i < len; i++) {
			if (dp[i - 1] > 0) {
				dp[i] = dp[i - 1] + nums[i];
			}
			else {
				dp[i] = nums[i];
			}
			maxSum = max(dp[i], maxSum);
		}
		return maxSum;
	}

	int maxSubArray_3(vector<int>& nums) {
		int maxSum = nums[0];
		int temp = 0;
		int len = nums.size();
		for (int i = 0; i < len; i++) {
			if (temp >= 0) {
				temp += nums[i];
			}
			else {
				temp = nums[i];
			}
			maxSum = max(maxSum, temp);
		}
		return maxSum;
	}
};

void test_maxSubArray() {
	vector<int> a = { 5,4,-1,7,8 };
	Solution_MaxSubArray s;
	cout << s.maxSubArray_3(a) << endl;
}