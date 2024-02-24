#include <bits/stdc++.h>
using namespace std;

int sum(int x[], int l, int r) {
	if(l == r) {
		if(x[l] > 0) return x[l];
		else return 0;
	} else {
		int c = (l+r) / 2;
		int lSum = sum(x,l,c);
		int rSum = sum(x,c+1,r);
		return lSum + rSum;
	}
}

s

int main() {
	int n = 11;
	int x[n] = {-5,-4,-3,-2,-1,0,1,2,3,4,5};
	cout << sum(x,0,n-1);
	return 0;
} 
