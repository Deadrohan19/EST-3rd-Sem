#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int binarySearch(vector<int>& v, int target){
	int low = 0, high = v.size()-1;

	while(low<=high){
		int mid = (low + high)/2;
		if(v[mid]==target)
			return mid;
		if(v[mid]>target)
			high = mid -1;
		else 
			low = mid +1;
	}
	return -1;
}

int linearSearch(vector<int>& v, int target){
	for(int i=0;i<v.size();++i)
		if(v[i]==target)
			return i;
	return -1;
}

int main(){
	cout<<"Enter the size of array followed by its elements: ";
	int n;cin>>n;
	vector<int> v(n);
	for(auto &i: v)
		cin>>i;
	
	cout<<"Enter the number you want to search: ";
	int num;cin>>num;
	
	cout<<"Linear Search: \n";
	int linear = linearSearch(v,num);
	if(linear==-1)
		cout<<num<<" is not present in the array!";
	else
		cout<<num<<" is present at index "<<linear;
		
	cout<<"\n\n";
	sort(v.begin(), v.end());
	cout<<"Sorted array: ";
	for(auto i: v)
		cout<<i<<" ";
	cout<<"\n\n";

	cout<<"Binary Search: \n";
	int binary = binarySearch(v,num);
	if(binary==-1)
		cout<<num<<" is not present in the array!";
	else
		cout<<num<<" is present at index "<<binary;
}