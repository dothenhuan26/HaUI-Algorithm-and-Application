#include<bits/stdc++.h>
using namespace std;

int n=10;
int a[] = {1, 5, 2, 9, 7, 14, 6, 12, 5, 11};

int recursive(int *a, int n) {
	if(n==0) return a[n]&1?a[n]:0;
	if(a[n]&1) return a[n]+recursive(a, n-1);
	return recursive(a, n-1);
}

void handleRecursive() {
	cout<<"Tong cua cac so le trong mang a la: "<<recursive(a, n)<<endl;
}

int main() {
	handleRecursive();



	return 0;
}

