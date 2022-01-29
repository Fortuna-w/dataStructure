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

class Solution_mergeTwoLists {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode * h1 = list1, *h2 = list2;
		ListNode * h = new ListNode();
		ListNode * head = h;
		while (h1 && h2) {
			if (h1->val >= h2->val) {
				h->next = h2;
				h2 = h2->next;
			}
			else {
				h->next = h1;
				h1 = h1->next;
			}
			h = h->next;
		}
		while (h1) {
			h->next = h1;
			h1 = h1->next;
			h = h->next;
		}
		while (h2) {
			h->next = h2;
			h2 = h2->next;
			h = h->next;
		}
		return head->next;
	}
};