#include<bits/stdc++.h>
using namespace std;

int c[5] = {100, 25, 10, 5, 1};
int n = 34;
int s[5] = {0};

bool CASHIERS_ALGORITHM(int *c, int m, long n, int *s) {
	memset(s, 0, sizeof(s));
	int i=0;
	while(n>0 && i<m) {
		s[i] = n/c[i];
		n-=c[i]*s[i];
		i++;
	}
	if(n>0) return false;
	else return true;
}

void result() {
	if(CASHIERS_ALGORITHM(c, 5, n, s)) {
		for(auto x:s) cout<<x<<" ";
		cout<<endl;
	} else {
		cout<<"Khong tim thay ket qua"<<endl;
	}
	
	
}

int main() {
	


	return 0;
}
