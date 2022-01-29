#pragma once
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution_firstUniqChar {
public:
	int firstUniqChar(string s) {
		int len = s.length();
		if (len == 1) {
			return 0;
		}
		for (int i = 0; i < len ; i++) {
			for (int j = 0; j < len; j++) {
				if (j != i) {
					if (s[i] == s[j]) {
						break;
					}
					if (j == len - 1) {
						return i;
					}
				}
				else {
					if (j == len - 1) {
						return i;
					}
					continue;
				}
				
			}
			
		}
		return -1;
	}


	int firstUniqChar_1(string s) {
		if (s.empty())
			return -1;
		int len = s.size();
		unordered_map<char, int> m;
		for (int i = 0; i < len; i++) {
			m[s[i]]++;
		}
		for (int i = 0; i < len; i++) {
			if (m[s[i]] == 1) {
				return i;
			}
		}
		return -1;
	}
};

void test_firstUniqChar() {
	string str = "leetcode";
	Solution_firstUniqChar s;
	cout << s.firstUniqChar_1(str) << endl;

}