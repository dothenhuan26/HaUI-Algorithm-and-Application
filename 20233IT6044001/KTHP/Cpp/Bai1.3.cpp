#include<bits/stdc++.h>
using namespace std;

int n = 10;
float a[] = {2.1, -3.4, -5.9, 6.2, -3.3, 12.4, 16.9, -15, 21.2, 19};


float res(float *a, int l, int r) {
	if(l==r)
		return a[l]>0?a[l]:0;
	int m = (l+r)/2;
	float resl = res(a, l, m);
	float resr = res(a, m+1, r);	
	return resl+resr;
}

void useRes() {
	cout<<"Tong cua cac so duong co trong mang a la: "<<res(a, 0, n-1)<<endl;
}

int main() {
	useRes();

	return 0;
}

