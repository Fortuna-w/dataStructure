#pragma once
#include<iostream>
#include<vector>

using namespace std;

class Solution_setZeroes {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size();
		int n = matrix[0].size();
		bool row = false;
		bool col = false;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == 0) {
					if (i == 0) {
						row = true;
					}
					if (j == 0) {
						col = true;
					}
					matrix[0][j] = matrix[i][0] = 0;
				}
			}
		}
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (matrix[0][j] == 0 || matrix[i][0] == 0) {
					matrix[i][j] = 0;
				}
			}
		}
		if (col) {
			for (int i = 0; i < m; i++) {
				matrix[i][0] = 0;
			}
		}
		if (row) {
			for (int j = 0; j < n; j++) {
				matrix[0][j] = 0;
			}
		}
	}
};


void test_setZeroes() {
	vector<vector<int>> nums = { {1,0,3} };
	//{ {0,1,2,0},{3,4,5,2},{1,3,1,5} };
	//{ {1,1,1,},{1,0,1},{1,1,1} };
	Solution_setZeroes s;
	s.setZeroes(nums);
	for (int i = 0; i < nums.size(); i++) {
		for (int j = 0; j < nums[0].size(); j++) {
			cout << nums[i][j] << " ";
		}
		cout << endl;
	}
}