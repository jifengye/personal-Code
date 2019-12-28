/*
删除链表中重复的结点

在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/

/*
注意题目是排序的链表
所以重复的都相邻
所以：
	先创建出一个节点，最后返回 head->next（因为所给头节点又可能是重复的）
	当当前节点值等于下一节点值，用while一直下去直到不等 
*/
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 链表的建立 
template <class T>
struct ListNode *CreatList(T &a){
	int ArrayLength = sizeof(a)/sizeof(a[0]);
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

// 链表的遍历 
void output(struct ListNode *head){
	while(head != NULL){
		cout << head->val << " ";
		head = head->next;
	}
}

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        ListNode* head=new ListNode(0);
        ListNode* p=head;
        ListNode* q=pHead;
        while(q){
            while(q!=NULL&&q->next!=NULL&&q->next->val==q->val){
                int tmp=q->val;
                while(q!=NULL&&q->val==tmp) q=q->next;
            }
            p->next=q;
            p=p->next;
            if(q) q=q->next;
        }   
        return head->next;
    }
};

int main(){
	class Solution solu;
	int a[] = {0,1,1,2,3};
	struct ListNode *LN = CreatList(a);
	struct ListNode *LN2 = solu.deleteDuplication(LN);
	output(LN2);
	return 0;
}
