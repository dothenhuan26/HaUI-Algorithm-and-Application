#include <bits/stdc++.h>
using namespace std;

int sum(int x[], int l, int r) {
	if(l == r) {
		return x[l];
	}else {
		int c = (l+r) / 2;
		int lSum = sum(x,l,c);
		int rSum = sum(x,c+1,r);
		return lSum + rSum;
	}
}

int main() {
	int n = 10;
	int x[n] = {1,2,3,4,5,6,7,8,9,0};
	int s = sum(x,0,n-1);
	cout << s;
	return 0;
} 
