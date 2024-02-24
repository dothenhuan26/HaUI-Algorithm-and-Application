#include<bits/stdc++.h>
using namespace std;

void init(int a[], int k) {
	for(int i=1; i<=k; i++) a[i]=i;
}

void output(int a[], int k) {
	for(int i=1; i<=k; i++) cout<<a[i];
	cout<<endl;
}

void list_sub(int a[], int n, int k) {
	int i;
	do {
		output(a, k);
		i=k;
		while(i>=1 && a[i]==n-k+i) i--;
		if(i==0) return;
		else {
			a[i]++;
			for(int j=i+1; j<=k; j++) {
				a[j]=a[j-1]+1;
			}
		}
	} while(i>=1);
}


int main() {
	int n, k; cin>>n>>k;
	int a[k+1];
	init(a, k);
	list_sub(a, n, k);
		

	return 0;
}

