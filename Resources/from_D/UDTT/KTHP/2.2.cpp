#include <bits/stdc++.h>
using namespace std;

int partition(double a[], int l, int r) {
	int pivot = a[r];
	int i = l - 1;
	for(int j=l; j<r; j++) {
		if(a[j] < pivot) {
			++i;
			swap(a[i],a[j]);
		}
	}
	++i;
	swap(a[i],a[r]);
	return i;
}

void quickSort(double a[], int l, int r) {
	if(l <= r) {
		int p = partition(a,l,r);
		quickSort(a,l,p-1);
		quickSort(a,p+1,r);
	}
}

int thamlam(double a[], int n, double c, double s[]) {
	int dem=0;
	for(int i=0; i<n; i++) {
		if(a[i] <= c) {
			s[i] = a[i];
			c -= a[i];
		}
	}
	
	for(int i=0; i<n; i++) {
		if(s[i] > 0) dem++;
	}
	return dem;
}

void hienthi(double s[], int n) {
	for(int i=0; i<n; i++) {
		if(s[i] > 0) cout << s[i] << " ";
	}
}

int char_in_string(char x, string p) {
	for(int i=p.length(); i>-1; i--) {
		if(p[i] == x) return i;
	}
	return -1;
}
//
//bool boyer_moore(string t, string p) {
//	int i = p.length();
//	if(i<t.length()) {
//		int k = p.length() - 1;
//		int j = i - 1;
//		while(p[k] == t[j] && k > -1) {
//			k--;j--;
//		}
//		if(k < 0) {
//			return true;
//			i += p.length();
//		} else {
//			k = char_in_string(t[j],p);
//			if(k < 0) {
//				i += p.length();
//			} else i = i + p.length() - k - 1;
//		}
//	}
//	return false;
//}

bool boyer_moore(string t, string p) {
	int i = p.length();
	while(i < t.length()) {
		int j = i-1;
		int k = p.length() - 1;
		while( k>-1 && t[j] == p[k]) {
			k--;j--;
		}
		if(k<0) {
			return true;
			i += p.length();
		} else {
			k = char_in_string(t[j],p);
			if(k<0) {
				i += p.length();
			} else {
				i = i + p.length() - k - 1;
			}
		}
		
	}
	return false;
}

int main() {
	int n = 8;
	double a[n] = {1.5,2,6.3,1,5,7.8,2.1,6};
	double s[n] = {0};
	quickSort(a,0,n-1);
	double c = 5.5;
	string q = "Nguyen Huu Dat";
	string p = "Nguyen Huu Dat sinh ngay 15/12/2003";
	
	if(thamlam(a,n,c,s) > 0) {
		 cout << "Cac phan tu lay duoc la: \n";
		 hienthi(s,n); 
	} else cout << "Khong lay duoc phan tu nao!";
	
	if(boyer_moore(p,q)) {
		cout << "Q la chuoi con cua chuoi P!";
	} else cout << "Q khong la chuoi con cua chuoi P!";
	
	return 0;
}
