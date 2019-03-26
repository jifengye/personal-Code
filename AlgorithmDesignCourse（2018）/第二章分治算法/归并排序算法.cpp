/*
使用了分治算法 
*/
/*
版一 
*/
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//void Merge(int A[],int B[],int low,int mid,int top){
//	int i=low;
//	int j=mid+1;
//	int k=low;
//	while(i<=mid && j<=top){
//		if(A[i]<=A[j])  B[k++]=A[i++];
//		else  B[k++]=A[j++];
//	}
//	while(i<=mid) B[k++]=A[i++];
//	while(j<=top) B[k++]=A[j++];
//	
//	for(int t=low; t<=top; t++) A[t]=B[t];
//}
// 
//void MergeSort(int A[],int B[],int low,int top){
//	if(low>=top) return; //递归结束 
//	
//	//对半切为左右两部分，并分别排序 
//	int mid = (low+top) >> 1;
//	MergeSort(A,B,low,mid);
//	MergeSort(A,B,mid+1,top);
//	
//	//合并左右两部分 
//	Merge(A,B,low,mid,top);
//}
//
//int main(){
//	int A[8]={10,3,5,1,9,34,54,565},B[8];
//	MergeSort(A,B,0,7);
//	for(int q=0; q<8; q++)
//		cout<<" "<<A[q];
//	return 0;
//}

/*
版二 
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//
//void Merge(int A[],int low,int mid,int top){
//	int i=low;
//	int j=mid+1;
//	vector<int> B;
//	while(i<=mid && j<=top) A[i]<=A[j] ? B.push_back(A[i++]) : B.push_back(A[j++]);
//	while(i<=mid) B.push_back(A[i++]);
//		
//	for(int i=0; i<B.size(); i++) A[i+low]=B[i];
//}
//
//void MergeSort(int A[],int low,int top){
//	if(low>=top) return; //递归结束 
//	
//	//对半切为左右两部分，并分别排序 
//	int mid = (low+top) >> 1;
//	MergeSort(A,low,mid);
//	MergeSort(A,mid+1,top);
//	
//	//合并左右两部分 
//	Merge(A,low,mid,top);
//}
//
//int main(){
//	//int A[]={10,3,5,1,9,34,54,565};
//	int A[4];
//	cin>>A[0]>>A[1]>>A[2]>>A[3];
//	int n = sizeof(A)/sizeof(int); 
//	MergeSort(A,0,n-1);
//	
//	cout<<A[0];
//	for(int i=1; i<n; i++) cout<<" "<<A[i];
//	return 0;
//}

/*
版三 
*/
#include <iostream>
#include <vector>
using namespace std;

void reversePairs(vector<int>& nums) {
	//递归结束
	if(nums.size() < 2) return;
	
	//nums对半分成左右两个left、right，返回的是排好序的 
	int mid = nums.size() >> 1; 
	vector<int> left(nums.begin(), nums.begin() + mid);
	vector<int> right(nums.begin() + mid, nums.end());
	reversePairs(left);
	reversePairs(right);
	
	//左右两部left、right 分归并 nums
	nums.clear();
	int i=0,j=0;
	while(i<left.size() && j<right.size()) 
		left[i]<right[j] ? nums.push_back(left[i++]) : nums.push_back(right[j++]);
	while(i<left.size()) 
		nums.push_back(left[i++]); 
	while(j<right.size()) 
		nums.push_back(right[j++]);
}

int main() {
	vector<int> nums = {1,65,8,7,500};
	reversePairs(nums);
	for(auto e:nums) cout<<e<<' ';
	return 0;
} 

