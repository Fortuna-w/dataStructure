#pragma once
#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution_hasCycle {
public:
	bool hasCycle(ListNode *head) {
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast != NULL && fast->next != NULL) {
			slow = slow->next;
			fast = fast->next->next;
			// ����ָ��������˵���л�
			if (slow == fast) return true;
		}
		return false;
	}
};