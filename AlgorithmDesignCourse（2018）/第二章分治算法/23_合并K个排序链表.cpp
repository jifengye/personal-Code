/* 题目：23. 合并K个排序链表 
 * 要求：合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。 
 * 来源：https://leetcode-cn.com/problems/merge-k-sorted-lists/description/ 
 * 输入:
 *		[
 *		  1->4->5,
 *		  1->3->4,
 *		  2->6
 *		]
 * 输出: 1->1->2->3->4->4->5->6
 * 时间：2018/9/25 
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

template <class T>
struct ListNode *CreatList(T &a){ //建立动态链表 
	int ArrayLength =  sizeof(a)/sizeof(a[0]);
	if(ArrayLength==0) return NULL;
	
	struct ListNode *head;
	struct ListNode *p;
	struct ListNode *newnode;
	for(int i=0; i<ArrayLength; i++){
		newnode = (struct ListNode *)malloc( sizeof(struct ListNode) ); //开辟空间
		newnode->val = a[i];
		if(i==0) head = p = newnode; //记下首地址 
		else p->next = newnode;
		p = newnode;
	}
	p->next = NULL;
	return head;
}


class Solution {
	private:
		ListNode * merge2Lists(ListNode * list1, ListNode * list2) {
			ListNode head(0);
			ListNode * tail = &head;
			while (list1 && list2) {
				if (list1->val > list2->val) {
					swap(list1, list2);
				}
				tail->next = list1;
				tail = list1;
				list1 = list1->next;
			}
			if (list1) tail->next = list1;
			if (list2) tail->next = list2;
			return head.next;
		}
	public:
		ListNode* mergeKLists(vector<ListNode*>& lists) {
			if (lists.empty()) return NULL;
			if (lists.size() == 1) return lists[0];
			int mid = lists.size() + 1 >> 1;
			for (int i = mid; i < lists.size(); i++) {
				lists[i - mid] = merge2Lists(lists[i - mid], lists[i]);
			}
			lists.resize(mid);
			return mergeKLists(lists);
		}
};

void output(struct ListNode *head){
	struct ListNode *p;
	p = head;
	while(p != NULL){
		cout << p->val << " ";
		p = p->next;
	}	
}

int main() {
	Solution solu;
	int a1[] = {1,4,5};
	int a2[] = {1,3,4};
	int a3[] = {2,6};
	vector<ListNode*> lists;
	lists.push_back(CreatList(a1));
	lists.push_back(CreatList(a2));
	lists.push_back(CreatList(a3));
	output(solu.mergeKLists(lists)); 
	return 0;
}
