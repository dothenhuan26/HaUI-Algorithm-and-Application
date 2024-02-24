#include<bits/stdc++.h>
using namespace std;

struct CongViec{
	string macv;
	float batdau;
	float thuchien;
	
	CongViec() {}

	CongViec(string _mavc, float _batdau, float _thuchien) {
		macv = _mavc;
		batdau = _batdau;
		thuchien = _thuchien;
	}
};

int n=8, k=5;
CongViec c[] = {
	{"CV01", 8, 30},
	{"CV02", 9, 20},
	{"CV03", 11, 60},
	{"CV04", 12, 30},
	{"CV05", 14, 10},
	{"CV06", 17, 45},
	{"CV07", 20, 30},
	{"CV08", 23, 20},
}; 
int a[1000]{0}, flag=1;

void khoitao() {
	for(int i=1; i<=k; i++) a[i]=i;
}

void view_option(CongViec c[], int k) {
	for(int i=1; i<=k; i++)
		cout<<c[a[i]-1].macv<<" ";
	cout<<endl;
}

void view_cv(CongViec cv) {
	cout<<"Ma cong viec: "<<cv.macv<<" - Thoi gian bat dau: "<<cv.batdau<<" Gio - Thoi gian thuc hien: "<<cv.thuchien<<" phut"<<endl;
}

void displayListCv(CongViec c[], int n) {
	if(n<0) return;
	view_cv(c[n]);
	displayListCv(c, n-1);
}

void displayByRecursive(CongViec c[], int n) {
	cout<<"Danh sach cong viec la: \n";
	displayListCv(c, n);
}

void next_config(int a[], int k, int i) {
	a[i]++;
	for(int j=i+1; j<=k; j++) a[j]= a[j-1]+1;
}

void gen_config(int a[], int n, int k) {
	int i=k;
	while(i>=1 && a[i]==n-k+i) i--;
	if(i==0) flag=0;
	else next_config(a, k, i);
}

void showOption(CongViec c[], int n, int k) {
	khoitao();
	while(flag) {
		view_option(c, k);
		gen_config(a, n, k);
	}
}

//void showOption(CongViec c[], int n, int k) {
//	int i;
//	khoitao();
//	do {
//		view_option(c, k);
//		i=k;
//		while(i>=1 && a[i]==n-k+i) i--;
//		if(i>0) {
//			next_config(a, k, i);
//		} else{
//			return;
//		}
//		
//	} while (i>=1);
//}

int main() {
	displayByRecursive(c, n-1);
	cout<<"********\n";
//	showOption(c, n, k);
	showOption(c, n, k);

	return 0;
}

