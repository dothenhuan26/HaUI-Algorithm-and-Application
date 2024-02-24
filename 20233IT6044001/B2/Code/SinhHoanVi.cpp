#include<bits/stdc++.h>
using namespace std;

void init(int a[], int n) {
	for(int i=1; i<=n; i++) a[i]=i;
}

void output(int a[], int n) {
	for(int i=1; i<=n; i++) cout<<a[i];
	cout<<endl;
}

void list_res(int a[], int n) {
	int i;
	do {
		output(a, n);
		i=n-1;
		
		while(i>=1 && a[i]>a[i+1])i--;
		if(i==0) return;
		else {
			int j=n;
			while(a[i]>a[j]) j--;
			swap(a[i], a[j]);
			int r=n; i++;
			while(r>i) {
				swap(a[i], a[j]);
				i++;
				r--;
			}
		}
		
	} while(i>=1);
}

int main() {
	int n; cin>>n;
	int a[n+1];
	init(a, n);
	list_res(a, n);
	return 0;
}

