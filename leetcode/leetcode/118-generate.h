#pragma once
#include<vector>
#include<iostream>

using namespace std;

class Solution_generate {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> res(numRows);
		for (int i = 0; i < numRows; i++) {
			vector<int> temp(i + 1);
			for (int j = 0; j <= i; j++) {
				if (j == 0 || j == i) {
					temp[j] = 1;
				}
				else {
					temp[j] = res[i - 1][j - 1] + res[i - 1][j];
				}
			}
			res[i] = temp;
		}
		return res;
	}
};

void test_generate() {
	int num = 5;
	Solution_generate s;
	vector<vector<int>> res;
	res = s.generate(num);
	for (int i = 0; i < num; i++) {
		for (int j = 0; j <= i; j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}