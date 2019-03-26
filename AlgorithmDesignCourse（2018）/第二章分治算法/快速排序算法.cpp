#include <iostream>
using namespace std;
 
void Qsort(int a[], int low, int high) {
    if(low >= high) return;/*递归结束*/ 
    int first = low;
    int last = high;
    int key = a[first];/*用字表的第一个做基准数*/
 
    while(first < last) {
        while(first < last && a[last] >= key) --last;
        a[first] = a[last];/*比基准数小的移到基准数的右边*/
 
        while(first < last && a[first] <= key) ++first;
        a[last] = a[first];/*比基准数大的移到基准数的左边*/   
    }
    
    a[first] = key;/*基准数归位，此时first等于last*/ 
    Qsort(a, low, first-1);
    Qsort(a, first+1, high);
}

int main(){
    int a[] = {57, 68, 59, 52, 72, 28, 96, 33, 24};
 
    Qsort(a, 0, sizeof(a)/sizeof(a[0])-1);/*第三个参数要减1否则内存越界*/
 
    for(int i=0; i<sizeof(a)/sizeof(a[0]); i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
