#include<bits/stdc++.h>
using namespace std;

void init(int a[], int n) {
	for(int i=1; i<=n; i++) {
		a[i]=0;
	}
}

void output(int a[], int n) {
	for(int i=1; i<=n; i++) cout<<a[i];
	cout<<endl;
}



void list_binary(int n) {
	int a[n+1], i;
	init(a, n);
	do {
		output(a, n);
		i=n;
		while(i>=1 && a[i]==1) {
			a[i]=0;
			i--;
		}
		if(i==0) return;
		else a[i]=1;
	} while(i>=1);
}


int main() {
	int n; cin>>n;
	list_binary(n);
	
	
	
	return 0;
}
