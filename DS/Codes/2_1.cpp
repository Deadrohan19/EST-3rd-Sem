#include<bits/stdc++.h>
using ll = long long;
using namespace std;

void merge(int a[], int low, int mid, int high){
    int N = high-low+1;
    int b[N];
    int left = low, right = mid+1, bIdx = 0;

    while(left<=mid && right<=high)
        b[bIdx++] = (a[left]<=a[right]) ? a[left++] : a[right++];
    
    while(left<=mid)
        b[bIdx++] = a[left++];
    
    while(right<=high)
        b[bIdx] = a[right++];
    
    //copy to original array
    for(int i=0;i<N;++i)
        a[low+i]=b[i];
}

void mergeSort(int a[],int low, int high){
    if(low<high){
        int mid = (low + high)/2;
        mergeSort(a, low, mid);
        mergeSort(a, mid+1, high);
        merge(a, low, mid, high);
    }
}

int main(){
    cout<<"Enter the size of Array: ";
    int n;cin>>n;
    cout<<"Enter "<<n<<" Elements: ";
	int a[n];
	for(auto &i: a)
		cin>>i;
	mergeSort(a,0,n-1);
	
    cout<<"\nAccending Order: ";
	for(auto i: a)
		cout<<i<<" ";
}