#include <bits/stdc++.h>
using namespace std;

int partition(double a[], int l, int r) {
	double pivot = a[r];
	int i = l-1;
	for(int j=l; j<r; j++) {
		if(a[j] <= pivot) {
			++i;
			swap(a[i],a[j]);
		}
	}
	++i;
	swap(a[i],a[r]);
	return i;
}

void quickSort(double a[], int l, int r) {
	if( l < r) {
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

bool z(string t, string p) {
	string new_t = p + "$" + t;
	int n = new_t.length();
	int z[n] = {0};
	int l=0, r=0;
	
	for(int i=1; i<n; i++) {
		if(i>r) {
			l=r=i;
			while(r<n && new_t[r-l] == new_t[r]) {
				r++;
			}
			z[i] = r-l;
			r--;
		} else if( z[i-l] < z[r-i+1]) {
			z[i] = z[r-l];
		} else {
			l=i;
			while(r<n && new_t[r-l] == new_t[r]) {
				r++;
			}
			z[i] = r-l;
			r--;
		}
	}
	for(int i=0; i<n; i++) {
		if(z[i] == p.length()) return true;
	}
	return false;
}

int main() {
	int n = 8;
	double a[n] = {1.5,2,6.3,1,5,7.8,2.1,6};
	double s[n] = {0};
	quickSort(a,0,n-1);
	
	double c = 0.5;
	string p = "Nguyen Huu Dat";
	string t = "Nguyen Huu Dat sinh ngay 15/12/2003";
	
	if(thamlam(a,n,c,s) > 0) {
		for(int i=0; i<n; i++) {
			if(s[i] > 0) cout << s[i] <<" ";
		}
	} else cout << "Khong!";
	
	if(z(t,p)) {
		cout << "Co";
	} else cout << "Khong";
	
	return 0;
}

