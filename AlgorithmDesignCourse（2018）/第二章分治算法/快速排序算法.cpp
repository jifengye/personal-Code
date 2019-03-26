#include <iostream>
using namespace std;
 
void Qsort(int a[], int low, int high) {
    if(low >= high) return;/*�ݹ����*/ 
    int first = low;
    int last = high;
    int key = a[first];/*���ֱ�ĵ�һ������׼��*/
 
    while(first < last) {
        while(first < last && a[last] >= key) --last;
        a[first] = a[last];/*�Ȼ�׼��С���Ƶ���׼�����ұ�*/
 
        while(first < last && a[first] <= key) ++first;
        a[last] = a[first];/*�Ȼ�׼������Ƶ���׼�������*/   
    }
    
    a[first] = key;/*��׼����λ����ʱfirst����last*/ 
    Qsort(a, low, first-1);
    Qsort(a, first+1, high);
}

int main(){
    int a[] = {57, 68, 59, 52, 72, 28, 96, 33, 24};
 
    Qsort(a, 0, sizeof(a)/sizeof(a[0])-1);/*����������Ҫ��1�����ڴ�Խ��*/
 
    for(int i=0; i<sizeof(a)/sizeof(a[0]); i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
