/*
ɾ���������ظ��Ľ��

��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣 
���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
*/

/*
ע����Ŀ�����������
�����ظ��Ķ�����
���ԣ�
	�ȴ�����һ���ڵ㣬��󷵻� head->next����Ϊ����ͷ�ڵ��ֿ������ظ��ģ�
	����ǰ�ڵ�ֵ������һ�ڵ�ֵ����whileһֱ��ȥֱ������ 
*/
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// ����Ľ��� 
template <class T>
struct ListNode *CreatList(T &a){
	int ArrayLength = sizeof(a)/sizeof(a[0]);
	if(ArrayLength==0) return NULL;
	struct ListNode *head;
	struct ListNode *p;
	struct ListNode *newnode;
	for(int i=0; i<ArrayLength; i++){
		newnode = (struct ListNode *)malloc( sizeof(struct ListNode) ); //���ٿռ�
		newnode->val = a[i];
		if(i==0) head = p = newnode; //�����׵�ַ
		else p->next = newnode;
		p = newnode;
	}
	p->next = NULL;
	return head;
}

// ����ı��� 
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
