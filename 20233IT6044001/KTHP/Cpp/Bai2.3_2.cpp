#include<bits/stdc++.h>
using namespace std;

struct Hang{
	int m;
	float v;
	int index;
};

int n = 8;
float c = 12.6;
int m = 20;
bool selected[100];
int pos[100];

Hang a[] = {
	{3, 4.1, 1},
	{1, 2.5, 2},
	{6, 5.2, 3},
	{4, 3.9, 4},
	{8, 6.3, 5},
	{9, 5.2, 6},
	{3, 6.1, 7},
	{4, 2.1, 8},
};

void sort_by_v(Hang *a, int n) {
	for(int i=1; i<n; i++) {
		Hang x=a[i];
		int j = i - 1;
		while(j>=0 && x.v<a[j].v) {
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=x;
	}
}

void display_hang(Hang x) {
	cout<<"Khoi luong: "<<x.m<<" - Gia tri: "<<x.v<<" - "<<" - Thu tu: "<<x.index<<endl;
}

int D(Hang *a, int n, float c, bool *selected, int *pos) {
	for(int i=0; i<n; i++) {
		selected[i]=false;
		pos[i]=-1;
	};
		
	sort_by_v(a, n);
	
	int i=0, dem=0;
	float tmp = 0, c_cp=c;
	while(i<n && c>0) {
		if(c>=a[i].v) {
			c-=a[i].v;
			tmp+=a[i].v;
			dem++;
			selected[i]=true;
			pos[dem]=a[i].index;
		}
		i++;	
	}
	if(tmp==c_cp) return dem;
	return -1;
}

void handleD() {
	int d = D(a, n, c, selected, pos);
	if(d!=-1) {
		cout<<"D: "<<d<<endl;
//		for(int i=0; i<n; i++) {
//			if(selected[i]) cout<<a[i].index<<" ";
//		}
//		cout<<endl;
		cout<<"So thu tu cac goi hang da lay la: ";
		sort(pos, pos+n);
		for(int i=0; i<n; i++) {
			if(pos[i]!=-1) cout<<pos[i]<<" ";
		}
		cout<<endl;
	} else {
		cout<<"Khong co dap an!\n";
	}
	
}

float F[100][100];
float P(Hang *a, int n, int m, float F[100][100]) {
	for(int j=0; j<=m; j++) F[0][j] = 0;
	
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=m; j++) {
			F[i][j]=F[i-1][j];
			if(a[i-1].m<=j) {
				float temp = a[i-1].v+F[i-1][j-a[i-1].m];
				if(F[i][j]<temp) F[i][j]=temp;
			}
		}
	}
	return F[n][m];
}

void Truy(Hang *a, int n, int m, float F[100][100]) {
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


int main() {

	handleD();
	Truy(a, n, m, F);
	
	
//	sort_by_v(a, n);
//	
//	for(int i=0; i<n; i++) display_hang(a[i]);
//
//	cout<<D(a, n, c, selected);

	return 0;
}

