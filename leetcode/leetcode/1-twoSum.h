#pragma once
#include<iostream>
#include<vector>
#include<algorithm>

#include<unordered_map>
using namespace std;

class Solution_TwoSum {
public:
	struct node {
		int num;
		int sn;
	};
	void swap(node &a,node &b) {
		node temp;
		temp.num = a.num;
		temp.sn = a.sn;
		a.num = b.num;
		a.sn = b.sn;
		b.num = temp.num;
		b.sn = temp.sn;
	}
	node* bubble(node a[],int size) {
		for (int i = 0; i < size; i++) {
			for (int j = 1; j < size - i; j++) {
				if (a[j-1].num > a[j].num)
					swap(a[j - 1], a[j]);
			}
		}
		return a;
	}
	vector<int> twoSum(vector<int>& nums, int target) {
		//bubble(nums);
		int len = nums.size();
		node* a = new node[len];
		for (int i = 0; i < len; i++) {
			a[i].num = nums[i];
			a[i].sn = i;
		}
		bubble(a, len);
		for (int i = 0; i < len; i++) {
			cout << a[i].num << ":" << a[i].sn << endl;
		}
		vector<int> res(2);
		for (int i = 0, j = len - 1; i < j;) {
			if (a[i].num + a[j].num > target) {
				j--;
			}
			else if (a[i].num + a[j].num < target) {
				i++;
			}
			else
			{
				if (a[i].sn < a[j].sn) {
					res[0] = a[i].sn;
					res[1] = a[j].sn;
				}
				else
				{
					res[0] = a[j].sn;
					res[1] = a[i].sn;
				}
				break;
			}
		}
		return res;
	}

	//¹þÏ£±í
	vector<int> twoSum_1(vector<int>& nums, int target) {
		std::unordered_map <int, int> map;
		int len = nums.size();
		for (int i = 0; i < len; i++) {
			auto iter = map.find(target - nums[i]);
			if (iter != map.end()) {
				return { iter->second, i };
			}
			map.insert(pair<int, int>(nums[i], i));
		}
		return {};
	}
};

void test_twoSum() {
	vector<int> a = { 7,2,11,1,15 };
	int target = 3;
	Solution_TwoSum s;
	vector<int> ans;
	//ans = s.twoSum(a, target);
	ans = s.twoSum_1(a, target);
	cout << ans[0] << "," << ans[1] << endl;
}