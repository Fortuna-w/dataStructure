#pragma once
#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;


class Solution_Intersect {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> result;
		unordered_map<int, int> umap;
		//vector<int> umap(100);
		for (int num : nums1) {
			umap[num]++;
		}
		//umap.insert(pair<int, int>(8,1));
		//for (auto it = umap.begin(); it != umap.end(); it++) {
		//	cout << it->first << " " << it->second << endl;
		//}
		
		for (int num : nums2) {
			if (umap[num] > 0) {
				result.push_back(num);
				umap[num]--;
			}
		}
		return result;

	}

	vector<int> intersect_1(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		int len1 = nums1.size();
		int len2 = nums2.size();
		vector<int> res;
		int index1 = 0;
		int index2 = 0;
		while (index1 < len1&&index2 < len2) {
			if (nums1[index1] < nums2[index2]) {
				index1++;
			}
			else if (nums1[index1] > nums2[index2]) {
				index2++;
			}
			else {
				res.push_back(nums1[index1]);
				index1++;
				index2++;
			}
		}
		return res;
	}
};


void test_intersect() {
	vector<int> nums1 = { 1,2,2,1 ,3,5,4,7,5,4};
	vector<int> nums2 = { 2,2 };
	vector<int> res;
	Solution_Intersect s;
	res = s.intersect(nums1, nums2);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
}