#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution_maxProfit {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		vector<int> dp(len);
		dp[0] = 0;
		int minpro = prices[0];
		int res = 0;
		for (int i = 1; i < len; i++) {
			if (prices[i] <= minpro) {
				minpro = prices[i];
				dp[i] = 0;
			}
			else {
				dp[i] = prices[i] - minpro;
			}
		}
		for (int i = 0; i < len; i++) {
			if (res<=dp[i]) {
				res = dp[i];
			}
		}
		return res;
	}

	int maxProfit_1(vector<int>& prices) {
		int len = prices.size();
		int minpro = prices[0];
		int res = 0;
		for (int i = 1; i < len; i++) {
			if (prices[i] <= minpro) {
				minpro = prices[i];
				res = max(0, res);
			}
			else {
				res = max(prices[i] - minpro, res);
			}
		}
		return res;
	}

	int maxProfit_2(vector<int>& prices) {
		if (prices.size() <= 1) {
			return 0;
		}
		int minp = prices[0];
		int maxp = 0;
		for (int i = 1; i < prices.size(); i++) {
			maxp = max(maxp, prices[i] - minp);
			minp = min(minp, prices[i]);
		}
		return maxp;
	}
};

void test_maxProfit() {
	vector<int> prices = { 3,2,6,5,0,3 };
	Solution_maxProfit s;
	cout << s.maxProfit_2(prices) << endl;

}