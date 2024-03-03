#include<bits/stdc++.h>
using namespace std;

int n=4;
int m=6;
int w[] = {0,2,1,4,3};
int v[] = {0,3,3,4,2};
int f[5][7];

int result(int *w, int *v, int n, int m) {
	for(int j=0;j<=m; j++) f[0][j]=0;
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=m; j++) {
			f[i][j] = f[i-1][j];
			if(w[i]<=j) {
				int temp = v[i]+f[i-1][j-w[i]];
				if(f[i][j]<temp) f[i][j]=temp;
			}
		}
	}
	return f[n][m];
}

void truy(int *w, int *v, int n, int m) {
	cout<<"Max value: "<<f[n][m]<<endl;
	int i=n, j=m;
	while(i>=0) {
		if(f[i][j]!=f[i-1][j]) {
			cout<<i<<" ";
			j=j-w[i];
		}
		i--;
	} 
}

void run() {
	result(w, v, n, m);
	truy(w, v, n, m);
}


int main() {
	run();



	return 0;
}

