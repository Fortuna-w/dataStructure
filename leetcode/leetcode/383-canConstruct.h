#pragma once
#include<iostream>
#include<unordered_map>

using namespace std;

class Solution_canConstruct {
public:
	bool canConstruct(string ransomNote, string magazine) {
		int len1 = ransomNote.length();
		int len2 = magazine.length();
		unordered_map<char, int> m;
		for (int i = 0; i < len1; i++) {
			m[ransomNote[i]]++;
		}
		for (int i = 0; i < len2; i++) {
			m[magazine[i]]--;
		}
		for (int i = 0; i < len1; i++) {
			if (m[ransomNote[i]] > 0) {
				return false;
			}
		}
		return true;
	}


	bool canConstruct_1(string ransomNote, string magazine) {
		int record[26] = { 0 };
		int len1 = ransomNote.length();
		int len2 = magazine.length();
		for (int i = 0; i < len2; i++) {
			record[magazine[i]-'a']++;
		}
		for (int i = 0; i < len1; i++) {
			record[ransomNote[i] - 'a']--;
			if (record[ransomNote[i] - 'a'] < 0)
				return false;
		}
		return true;
	}
};

void test_canConstruct() {
	string str1 = "aa";
	string str2 = "aab";
	Solution_canConstruct s;
	cout << s.canConstruct(str1, str2) << endl;
}