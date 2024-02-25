#include<bits/stdc++.h>
using namespace std;

struct DienThoai{
	string nhanhieu;
	int kichthuoc;
	int giaban;
	
//	DienThoai(string _nhanhieu, int _kichthuoc, int _giaban) {
//		nhanhieu=_nhanhieu;
//		kichthuoc = _kichthuoc;
//		giaban = _giaban;
//	}
	
};
int f[100][100];


void display_dt(DienThoai dt) {
	cout<<"Nhan hieu: "<<dt.nhanhieu<<" - Kich thuoc: "<<dt.kichthuoc<<" - Gia ban: "<<dt.giaban<<endl;
}

int handle(DienThoai *d, int n, int s) {
	for(int j=0; j<=s; j++) f[0][j]=0;
	
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=s; j++) {
			f[i][j] = f[i-1][j];
			if(d[i].kichthuoc<=j) {
				int temp = d[i].giaban+f[i-1][j-d[i].kichthuoc];
				if(temp>f[i][j]) {
					f[i][j] = temp;
				}
			}
		}
	}
	return f[n][s];
}

void truy(DienThoai *d, int n, int s) {
	cout<<"Tong gia ban lon nhat: "<<f[n][s]<<endl;
	
	int i=n, j=s;
	while(i!=0) {
		if(f[i][j]!=f[i-1][j]) {
			cout<<i<<" ";
			j=j-d[i].kichthuoc;
		}
		i--;
	}	
}

void run() {
	int s=20;
	int n=8;
	DienThoai d[n+1];
	d[0]={"", 0, 0};
	d[1]={"SamSung J7", 5, 1000000};
	d[2]={"Iphone 8", 4, 3000000};
	d[3]={"SamSung A6", 3, 1000000};
	d[4]={"IphoneX", 5, 8000000};
	d[5]={"Oppo A3", 7, 2000000},
	d[6]={"Nokia", 6, 6500000};
	d[7]={"Sony", 5, 3000000};
	d[8]={"Xiaomi", 4, 4000000};
	
	for(auto x:d) display_dt(x);
	
	cout<<"-------------*\n";
	
	handle(d, n, s);
	truy(d, n ,s);
}

int main() {
	run();



	return 0;
}

