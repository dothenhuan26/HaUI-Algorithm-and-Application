#include <bits/stdc++.h>
using namespace std;

int sum(int x[], int n) {
	if(n < 0) return 0;
	else if(x[n] % 2 == 1) {
		return x[n] + sum(x,n-1);
	} else sum(x,n-1);
}
 
int main() {
	int n = 10;
	int x[n] = {1,2,3,4,5,6,7,8,9,0};
	cout << sum(x,n);
	return 0;
}
