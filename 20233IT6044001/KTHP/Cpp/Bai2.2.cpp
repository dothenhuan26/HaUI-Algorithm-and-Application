#include<bits/stdc++.h>
using namespace std;

int n=8;
float a[] = {2.1, 3.3, 3.4, 5.9, 6.2, 12.4, 15, 16.9};
float c = 25.13;
bool selected[100];
float m=0;
int dem=0;
string p = "Xin chao Viet Nam";
string q = "Hello every body, Day la: Xin chao Viet Nam 2024";



int pos[256]={0};

int D(float *a, int n, float c, float &m, bool *selected) {
	for(int i=0; i<n; i++) selected[i]=false;
	int i=n-1;
	int dem=0;
	while(n>=0 && c>=0) {
		selected[i]=true;
		m+=a[i];
		dem++;
		c-=a[i];
		i--;
	}
	return dem;
}

int char_in_string(char x, string p) {
	for(int i=p.length()-1; i>=0; i--) {
		if(p[i]==x) return i;
	}
	return -1;
}

int boyer_moore_horspool(string p, string t) {
	int cnt=0, v=p.length(), i=v;
	while(i<=t.length()) {
		int j=i-1;
		int x=v-1;
		while(p[x]==t[j] && x>=0) {
			x--; j--;
		}
		if(x<0) {
			pos[cnt]=i-v;
			i+=v;
			cnt++;
		} else {
			int k = char_in_string(t[j], p); 
			if(k<0) {
				i+=v;
			} else {
				i+=v-k-1;
			}
		}
	}
	return cnt;
}

void handleD() {
	int thamlam=D(a, n, c, m, selected);
	if(thamlam>0) {
		cout<<"So luong phan tu it nhat co the lay trong day a de duoc gia tri lon hon c = "<<c<<" la: "<<thamlam<<endl;
		
		cout<<"Gia tri cua m = "<<m<<endl;
		
		for(int i=0;i<n;i++) {
			if(selected[i]) {
				cout<<a[i]<<" ";
			}
		}
	} else {
		cout<<"Khong co dap an!\n";
	}
	cout<<endl;
}

void handleBYM() {
//	int bym = boyer_moore_horspool(p, q);
int bym = boyer_moore_horspool(p, q);
	if(bym>0) {
		cout<<"So lan xuat hien la: "<<bym<<endl;
		cout<<"Vi tri xuat hien cua P trong Q la: ";
		for(int i=0; i<bym; i++) {
			cout<<pos[i]<<" ";
		}
	} else {
		cout<<"P khong phai la chuoi con cua Q\n";
	}
}


int main() {
	handleD();
	handleBYM();	
	return 0;
}

