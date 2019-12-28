/*
�����л�����ڽ��

��һ�����������а����������ҳ�������Ļ�����ڽ�㣬�������null��
*/
#include<cstdio>
#include<set> 
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
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
	struct ListNode *p;
	p = head;
	while(p != NULL){
		cout << p->val << " ";
		p = p->next;
	}
}



class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        set<ListNode*> s;
        ListNode* node = pHead;
        while(node!=NULL){
            if(s.insert(node).second)
                node = node->next;
            else
                return node;
        }
        return NULL;
    }
};
 


int main(){
	struct ListNode *LN;
	int a[] = {0,1,2,3};
	LN = CreatList(a);
	output(LN);
	return 0;
}


