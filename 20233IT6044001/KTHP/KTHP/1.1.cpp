#include<bits/stdc++.h>
using namespace std;

int n = 10;

float a[] = {2.1, 3.4, 1.5, 6.4, 5.9, 3.8, 5.5, 7.4, 4.8, 11.7};

float res(float *a, int l, int r) {
	if(l==r) return a[l];
	int m=(l+r)/2;
	float resL = res(a, l, m);
	float resR = res(a, m+1, r);
	return resL+resR;
}

void run() {
	cout<<"Tong cac so trong mang a la: "<<res(a, 0, n-1)<<endl;
}

int main() {
	
	run();

		

	return 0;
}

