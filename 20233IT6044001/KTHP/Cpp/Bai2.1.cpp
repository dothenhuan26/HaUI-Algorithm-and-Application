#include<bits/stdc++.h>
using namespace std;

int n=8;
float a[] = {2.1, 3.3, 3.4, 5.9, 6.2, 12.4, 16.9, 15};
float c = 25.13;
bool selected[100];
int dem=0;
float m=0;

string q = "Xin chao Viet Nam";
string p = "Hello every body, Day la: Xin chao Viet Nam 2024";

bool D(float *a, int n, float c, int &dem, float &m,bool *selected) {
	for(int i=0; i<n; i++) selected[i]=false;
	int i=0;
	while(i<n && c>=a[i]) {
		selected[i]=true;
		m+=a[i];
		c-=a[i];
		dem++;
		i++;
	}
	
	if(c<0) return false;
	return true;
}

void handleD() {
	if(D(a,n,c,dem,m,selected)) {
		cout<<"So luong phan tu nhieu nhat co the lay trong day a la: "<<dem<<endl;
		for(int i=0; i<n; i++) {
			if(selected[i]) cout<<a[i]<<" ";
		}
		cout<<endl;
		cout<<"Gia tri cua m la: "<<m<<endl;
	} else {
		cout<<"Khong co dap an!";
	}
}

int char_in_string(char x, string p) {
	for(int i=p.length()-1; i>=0; i--) {
		if(x==p[i]) return i;
	}
	return -1;
}

int boyer_moore_horspool(string p, string t) {
	int dem=0, v=p.length(), i=v;
	
	while(i<=t.length()) {
		int x = v-1;
		int j = i-1;
		
		while(p[x]==t[j] && x>=0) {
			x--; j--;
		}
		if(x<0) {
			dem++;
			i+=v;
		} else {
			int k = char_in_string(t[j], p);
			if(k<0) {
				i+=v;
			} else {
				i+=v-k-1;
			}
		}
	}
	return dem;
}

void handleBMH() {
	if(boyer_moore_horspool(q, p)>0) {
		cout<<"q la mot chuoi con cua p\n";
	} else {
		cout<<"q khong phai la mot chuoi con cua q\n";
	}
}


int main() {
	handleD();
	handleBMH();

	return 0;
}

