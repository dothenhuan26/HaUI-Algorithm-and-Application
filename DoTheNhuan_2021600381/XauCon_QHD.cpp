#include<bits/stdc++.h>
using namespace std;

//Xau con chung dai nhat

int L[256][256];

int alg(string a, string b) {
	for(int i=0; i<=a.length(); i++) L[i][0] = 0;
	for(int j=0; j<=b.length(); j++) L[0][j] = 0;
	for(int i=1; i<=a.length(); i++) {
		for(int j=1; j<=b.length(); j++) {
			if(a[i-1]==b[j-1]) {
				L[i][j] = L[i-1][j-1]+1;
			} else {
				L[i][j] = max(L[i-1][j], L[i][j-1]);
			}
		}
	}
	return L[a.length()][b.length()];
}

void truy(string a, string b) {
	int i=a.length(), j=b.length(), k=0;
	
	int len = L[i][j];
	
	char xc[len];
	
	while(L[i][j]!=0) {
		if(a[i-1]==b[j-1]) {
			xc[k] = a[i-1];
			k++;i--;j--;
		} else {
			if(L[i-1][j]>L[i][j-1]) i--;
			else j--;
		}
	}
	xc[k]='\0';
	strrev(xc);
	
	for(int i=0; i<len; i++) cout<<xc[i]<<" ";
	
}

int main() {
	string a = "nhun";
	string b = "my name is nhun do the";
	
	cout<<alg(a, b)<<endl;
	truy(a, b);
	

	return 0;
}

