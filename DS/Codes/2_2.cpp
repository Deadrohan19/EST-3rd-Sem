#include<bits/stdc++.h>
using ll = long long;
using namespace std;

void insert(vector<int>& v,int x, int pivot){
    int pos = upper_bound(v.begin(),v.begin()+pivot, x) - v.begin();
    for(int i=pivot-1;i>=pos;--i)
        v[i+1]=v[i];
    v[pos]=x;
}

void insertionSort(vector<int>& v){
	int n= v.size();
    int pivot = 1;
    while(pivot<n){
        cout<<"Step "<<pivot<<": ";
        for(auto i: v) cout<<i<<" ";
        cout<<"\n";
        insert(v,v[pivot], pivot);
        pivot++;
    }
}
int main(){
    cout<<"Enter size followed by elements of array: ";
    int n;cin>>n;
    vector<int> v(n);
    for(auto &i: v)
    	cin>>i;

    insertionSort(v);
    
    cout<<"\nFinal Step: ";
    for(auto i: v)
    	cout<<i<<" ";
}

//Algorithm for Insertion Sort
/*
Step 1 - If the element is 1st element, assume that it is already sorted.
Step 2 - Pick the next element and store it seperately in a key
Step 3 - Compare the key with all the elements in the sorted array
Step 4 - If the element in sorted array is smaller than the current element then move to the next element
         else shift the greater elements towards right
Step 5 - Repeat till array is sorted.
*/
