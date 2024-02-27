#include<bits/stdc++.h>
using namespace std;

struct Hang{
	int m;
	float v;
	int index;
	Hang(int _m, float _v, int _index) {
		m = _m;
		v = _v;
		index = _index;
	}
};

int D(Hang *a, int n, float c, int *pos) {
	int dem=0, i=0;
	float c_tmp=c;
	float m;
	while(i<n && c>0) {
		if(c>=a[i].v) {
			c-=a[i].v;
			m+=a[i].v;
			pos[dem]=a[i].index;
			dem++;
		}
		i++;
	}
	if(c_tmp==m) return dem;
	return -1;
}

float P(Hang *a, int n, int m,float F[][100]) {
	for(int j=0; j<=m; j++) F[0][j]=0;
	
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=m; j++) {
			F[i][j] = F[i-1][j];
			if(a[i-1].m<=j) {
				float temp = a[i-1].v+F[i-1][j-a[i-1].m];
				if(temp>F[i][j]) F[i][j]=temp;
			}
		}
	}
	return F[n][m];
}

void Truy(Hang *a, int n, int m, float F[][100]) {
	cout<<"P: "<<P(a, n, m, F)<<endl;
	
	int i=n, j=m;
	while(i!=0) {
		if(F[i][j]!=F[i-1][j]) {
			cout<<a[i-1].v<<" ";
			j=j-a[i-1].m;
		}
		i--;
	}
}

void run() {
	int n=8;
	Hang a[] = {
		{4, 1.8, 1},
		{2, 2.1, 2},
		{6, 3.5, 3},
		{9, 4.6, 4},
		{5, 5.7, 5},
		{5, 6.6, 6},
		{7, 8.2, 7},
		{5, 8.3, 8},
	};
	float c = 17.7;
	int pos[100] = {0};
	float m=20;
	
	//Tham lam
	int d = D(a, n, c, pos);
	if(d>0) {
		cout<<"D: "<<d<<endl;
		cout<<"So thu tu cac goi hang da lay trong a la: ";
		for(int i=0; i<d; i++) cout<<pos[i]<<" ";
	} else {
		cout<"Khong co dap an!";
	}
	cout<<endl;
	
	//QHD
	float F[100][100];
	Truy(a, n, m, F);
}

int main() {
	run();

	return 0;
}

