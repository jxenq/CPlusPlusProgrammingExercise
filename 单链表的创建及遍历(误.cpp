#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==0)
		return 0;
	else{
		for(int i=0;i<n-1;i++){
			cout<<a[i]<<" ";
		}
		cout<<a[n-1];
	}
}

