#include <bits/stdc++.h>
using namespace std;

//int dem(string s,int l, int r) {
//	if(l == r) {
//		if(isupper(s[l])) return 1;
//		else return 0;
//	} else {
//		int c = (l+r)/2;
//		int ls = dem(s,l,c);
//		int rs = dem(s,c+1,r);
//		return ls+rs;
//	}
//	
//}
int tong(int x[], int l, int r, int k) {
	if(l == r) {
		if(x[l] % k == 0) return x[l];
		else return 0;
	} else {
		int c = (l+r)/2;
		int ls = tong(x,l,c,k);
		int rs = tong(x,c+1,r,k);
		return ls+rs;
	}
}

int main() {
//	string s = "aBcDEfGh";
	int x[5] = {5,12,15,28,30};
	int k = 5;
	cout << tong(x,0,4,k);
	return 0;
}
 
