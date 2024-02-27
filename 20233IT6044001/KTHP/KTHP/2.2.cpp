#include<bits/stdc++.h>
using namespace std;



int D(float *a, int n, float c, float &m, bool *selected) {
	for(int i=0; i<n; i++) selected[i]=false;
	
	int i=0, dem=0;
	while(i<n && c>=0) {
		dem++;
		selected[i]=true;
		c-=a[i];
		m+=a[i];
		i++;
	}
	
	if(c<0) return dem;
	return -1;
}

int char_in_string(char x, string p) {
	for(int i=p.length(); i>=0; i--) {
		if(x==p[i]) return i;
	}
	return -1;
}

int boyer_moore_horspool(string p, string t, int *pos) {
	int dem=0, v=p.length(), i=v;
	
	while(i<=t.length()) {
		int x=v-1;
		int j=i-1;
		while(p[x]==t[j] && x>=0) {
			x--; j--;
		}
		if(x<0) {
			pos[dem]=i-v;
			i+=v;
			dem++;
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

void run() {
	int n = 8;
	float a[n] = {1.7, 2.1, 3.8, 4.2, 4.5, 6.9, 7.3, 8.5};
	float c = 10.2;
	string p = "child 2024";
	string q = "This text contain child 2024 - less than 255 char, child 2024.";

	bool selected[100];
	float m=0;
	
	int d = D(a, n, c, m, selected);
	if(d>0) {
		cout<<"D: "<<d<<endl;
		cout<<"M: "<<m<<endl;
		for(int i=0; i<n; i++) if(selected[i]) cout<<a[i]<<" ";
	} else {
		cout<<"Khong co dap an!";
	}
	cout<<endl;
	
	int pos[256]={0};
	int bym = boyer_moore_horspool(p, q, pos);
	if(bym>0) {
		cout<<"Vi tri xuat hien cua p trong q la: ";
		for(int i=0; i<bym; i++) cout<<pos[i]<<" ";
	} else {
		cout<<"p khong phai la chuoi con cua q.";
	}
	cout<<endl;
}

int main() {
	run();

	return 0;
}

