#pragma once
#include<vector>
#include<iostream>
using namespace std;

class Solution_matrixReshape {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
		int m = mat.size();
		int n = mat[0].size();
		vector<vector<int>> res(r,vector<int>(c));
		int x = 0;
		int y = 0;
		if ((m*n)>(r*c)|| (m*n) < (r*c)) {
			return mat;
		}
		else {
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (y == n) {
						y = 0;
						x++;
					}
					res[i][j] = mat[x][y];
					y++;					
				}
			}
		}
		return res;
	}

	vector<vector<int>> matrixReshape_1(vector<vector<int>>& mat, int r, int c) {
		int m = mat.size();
		int n = mat[0].size();
		vector<vector<int>> res(r, vector<int>(c));
		if ((m*n) != (r*c)) {
			return mat;
		}
		else {
			for (int i = 0; i < m*n; i++) {
				res[i / c][i%c] = mat[i / n][i%n];
			}
		}
		return res;
	}
};

void test_matrixReshape() {
	vector<vector<int>> mat = { {1,2},{3,4} };
	int r = 1;
	int c = 4;
	vector<vector<int>> res;
	Solution_matrixReshape s;
	res = s.matrixReshape_1(mat, r, c);
	int m = res.size();
	int n = res[0].size();
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}