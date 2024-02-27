#include<bits/stdc++.h>
using namespace std;

int n = 10;

float a[] = {2.1, -3.4, -1.5, 6.4, -5.9, 3.8, 5.5, -7.4, 4.8, 11.7};

float sum(float *a, int n) {
	if(n==0) return a[n]>0?a[n]:0;
	if(a[n]>0) return a[n]+sum(a, n-1);
	return sum(a, n-1);
}

void run() {
	cout<<"Tong cua cac so duong trong a la: "<<sum(a, n)<<endl;
}

int main() {
	run();



	return 0;
}

