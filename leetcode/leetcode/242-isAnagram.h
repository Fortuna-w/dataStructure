#pragma once
#include<iostream>

using namespace std;

class Solution_isAnagram {
public:
	bool isAnagram(string s, string t) {
		int len1 = s.length();
		int len2 = t.length();
		int res[26] = { 0 };
		if (len1 != len2)
			return false;
		for (int i = 0; i < len1; i++) {
			res[s[i] - 'a']++;
		}
		for (int i = 0; i < len2; i++) {
			res[t[i] - 'a']--;
		}
		for (int i = 0; i < len1; i++) {
			if (res[t[i] - 'a'] != 0)
				return false;
		}
		return true;
	}
};

void test_isAnagram() {
	string s1 = "anagram";
	string s2 = "nagaram";
	Solution_isAnagram s;
	cout << s.isAnagram(s1, s2) << endl;

}