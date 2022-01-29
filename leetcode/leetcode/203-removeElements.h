#pragma once
#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution_removeElements {
public:
	ListNode* removeElements(ListNode* head, int val) {
		while (head&&head->val == val) {
			head = head->next;
		}
		if (!head) {
			return head;
		}
		ListNode *p = head->next;
		ListNode *q = head;
		while (p) {
			if (p->val == val) {
				q->next = p->next;
				p = q->next;
			}
			else {
				p = p->next;
				q = q->next;
			}

		}
		return head;

	}
};