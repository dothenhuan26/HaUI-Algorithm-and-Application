#include<bits/stdc++.h>
using namespace std;

int L[256][256];

int alg(string a, string b) {
	int n_a = a.length(), n_b = b.length();
	for(int i=0; i<=n_a; i++) L[i][0]=0;
	for(int j=0; j<=n_b; j++) L[0][j]=0;
	
	for(int i=1; i<=n_a; i++) {
		for(int j=1; j<=n_b; j++) {
			if(a[i-1]==b[j-1]) L[i][j]=L[i-1][j-1]+1;
			else {
				L[i][j] = max(L[i-1][j], L[i][j-1]);
			}
		}
	}
	
	return L[n_a][n_b];
}

void Truy(string a, string b) {
	int i=a.length(), j=b.length(), k=0;
	int len = L[i][j];
	char xc[len];
	
	while(L[i][j]!=0) {
		if(a[i-1]==b[j-1]) {
			xc[k]=a[i-1];
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
	string a = "con";
	string b = "chuoi cha chua 1 chuoi con nam trong chuoi con";
	cout<<alg(a,b)<<endl;
	Truy(a,b);

	return 0;
}

