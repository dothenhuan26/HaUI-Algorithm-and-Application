#include<bits/stdc++.h>
using namespace std;

struct Hang{
	int m;
	float v;
};

int n = 8;
float c = 18;
int m = 15;
Hang a[] = {
	{4,7},
	{2,1},
	{5,9},
	{1,3},
	{8,5},
	{11,14},
	{9,2},
	{4,8},
};
bool selected[100] = {0};

void sort(Hang *a, int n) {
	for(int i=1; i<n; i++) {
		Hang x = a[i];
		int j = i-1;
		while(j>=0 && x.v<a[j].v) {
			a[j+1]=a[j];
			j--;
		}
		a[j+1] = x;
	}
}

void display_hang(Hang x) {
	cout<<"Khoi luong: "<<x.m<<" - Gia tri: "<<x.v<<endl;
}

int D(Hang *a, int n, float c, bool *selected) {
	for(int i=0; i<n; i++) selected[i]=false;
	sort(a, n);
	
	int i = 0, dem=0;
	while(i<n && c>0) {
		selected[i]=true;
		dem++;
		c-=a[i].v;
		i++;
	}
	
	if(c==0) return dem;
	return -1;
}

void handleD() {
	int d = D(a,n,c,selected);
	if(d>0) {
		cout<<"So luong goi hang nhieu nhat co the lay la: "<<d<<endl;
		cout<<"So thu tu cac goi hang da lay la: ";
		for(int i=0; i<n; i++) if(selected[i]) cout<<i<<" ";
		
	} else {
		cout<<"Khong co phuong an!";
	}
	
	
	cout<<endl;
}

float dp[100][100];
float P(Hang *a, int n, int m) {
	for(int j=0; j<=m; j++) dp[0][j]=0;
	
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=m; j++) {
			dp[i][j] = dp[i-1][j];
			if(a[i-1].m<=j) {
				float temp = a[i-1].v+dp[i-1][j-a[i-1].m];
				if(dp[i][j]<temp) dp[i][j]=temp;
			}
		}
	}
	return dp[n][m];
}

void truy(Hang *a, int n, int m) {
	cout<<"Gia tri P la: "<<dp[n][m]<<endl;
	int i=n, j=m;
	while(i!=0) {
		if(dp[i][j]!=dp[i-1][j]) {
			cout<<i<<" ";
			j=j-a[i-1].m;
		}
		i--;
	}
}

int main() {

	for(int i=0;i<n; i++) display_hang(a[i]);
	
	cout<<P(a, n, m);
	cout<<endl;
	for(int i=0; i<=n; i++){
		for(int j=0; j<=m; j++) {
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	
	truy(a,n,m);
	
	return 0;
}
