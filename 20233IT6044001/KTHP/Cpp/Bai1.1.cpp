#include<bits/stdc++.h>
using namespace std;

int n=10;

float a[] = {2.1, 3.4, 5.9, 6.2, 3.3, 12.4, 16.9, 15, 21.2, 19};

float res(float *a, int l, int r) {
	float sum=0;
	if(l==r) return a[l];
	int m=(l+r)/2;
	float suml = res(a, l, m);
	float sumr = res(a, m+1, r);
	
	return suml+sumr;
}

void use() {
	cout<<"Tong cua "<<n<<" so thuc cua mang a la: "<<res(a, 0, n-1)<<endl;
}


int main() {
	use();
	return 0;
}

