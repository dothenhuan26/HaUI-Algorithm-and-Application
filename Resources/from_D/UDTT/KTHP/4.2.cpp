#include <bits/stdc++.h>
using namespace std;

struct hang {
	int khoiluong;
	int giatri;
};

int partition(hang a[], int l, int r) {
	int pivot = a[r].giatri;
	int i = l-1;
	for(int j=l; j<r; j++) {
		if(a[j].giatri <= pivot) {
			++i;
			swap(a[i],a[j]);
		}
	}
	++i;
	swap(a[i],a[r]);
	return i;
}

void quickSort(hang a[], int l, int r) {
	if( l < r) {
		int p = partition(a,l,r);
		quickSort(a,l,p-1);
		quickSort(a,p+1,r);
	}
}

bool thamlam(hang h[], int n, int c, hang s[]) {
	for(int i=0; i<n; i++) {
		if(h[i].giatri <= c) {
			c -= h[i].giatri;
			s[i] = h[i];
		}
	}
	if(c == 0) return true;
	
	return false;
}

//int quyhoachdong(hang h[], int n, int m, hang s1[] ) {
//	int dp[n+1][m+1];
//	memset(dp,0,sizeof(dp));
//	
//	for(int i=1; i<=n; i++) {
//		for(int j=1; j<=m; j++) {
//			dp[i][j] = dp[i-1][j];
//			if(j >= h[i-1].khoiluong) {
//				dp[i][j] = max(dp[i][j],dp[i-1][j - h[i-1].khoiluong] + h[i-1].giatri);
//			}
//		}
//	}
//	
//	int i=n, j=m, k=0;
//	while(i > 0 && j>0) {
//		if(dp[i][j] != dp[i-1][j]) {
//			s1[k] = h[i-1];
//			k++;
//			j -= h[i-1].khoiluong;
//		}
//		i--;
//	} 
//	
//	return dp[n][m];
//}

int quyhoachdong(hang h[], int n, int m, hang s1[]) {
	int dp[n+1][m+1];
	memset(dp,0,sizeof(dp));
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			dp[i][j] = dp[i-1][j];
			if( j >= h[i-1].khoiluong) {
				dp[i][j] = max(dp[i][j], dp[i-1][j - h[i-1].khoiluong] + h[i-1].giatri);
			}
		}
	}
	
	int i=n, j=m, k=0;
	while(i>0 && j>0) {
		if(dp[i][j] != dp[i-1][j]) {
			s1[k] = h[i-1];
			k++;
			j -= h[i-1].khoiluong;
		}
		i--;
	}
	
	return dp[n][m];
}

int main() {
	int n = 8;
	hang h[n] = {
		{1,8},
		{2,7},
		{3,6},
		{4,5},
		{5,4},
		{6,3},
		{7,2},
		{8,1},
	};
	quickSort(h,0,n-1);
	int c = 10;
	hang s[n];
	hang s1[n] = {0};
	int dem=0;
//	if(thamlam(h,n,c,s)) {
//		
//		for(int i=0; i<n; i++) {
//			if(s[i].giatri > 0) {
//				dem ++;
//			} 
//		}
//		cout << "Co " << dem;
//	} else cout << "Khong";
	quyhoachdong(h,n,10,s1);
	for(int i=0; i<n; i++) {
		cout << s1[i].khoiluong <<  " ";
	}
	return 0;
}
