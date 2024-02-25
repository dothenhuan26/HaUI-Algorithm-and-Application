#include<bits/stdc++.h>
using namespace std;

struct Quat {
	string tenhangsx;
	string mausac;
	int giaban;

	Quat(string _tenhangsx, string _mausac, int _giaban) {
		tenhangsx = _tenhangsx;
		mausac = _mausac;
		giaban = _giaban;
	}
};

//int p = 1000000;
int p = 1100000;
int n = 8;
int cnt = 0;
bool selected[8] = {0};
int cnt2 = 0;
bool selected2[8] = {0};

Quat d[8] = {
	{"Sony", "Trang", 500000},
	{"Tosiba", "Den", 700000},
	{"Sony", "Do", 150000},
	{"Dasin", "Hong", 200000},
	{"Rang dong", "Trang", 350000},
	{"Acer", "Vang", 600000},
	{"Sony", "Trang", 900000},
	{"Samsung", "Tim", 450000}
};

void display_quat(Quat quat) {
	cout<<"Ten hang sx: "<<quat.tenhangsx<<"- Gia ban: "<<quat.giaban<<endl;
}

void sort_quat(Quat *d, int n) {
	for(int i=1; i<n; i++) {
		int j=i-1;
		Quat x = d[i];
		while(x.giaban<d[j].giaban && j>=0) {
			d[j+1] = d[j];
			j--;
		}
		d[j+1] = x;
	}
}

bool buy_quat(Quat *d, int n, int p, int &cnt, bool *selected) {
	sort_quat(d, n);

	int i = 0;

	while(i<n && p>=d[i].giaban) {
		cnt++;
		selected[i]= true;
		p-=d[i].giaban;
		i++;
	}
	if(cnt>0) return true;
	return false;
}

bool buy_quat2(Quat *d, int n, int p, int &cnt2, bool *selected2) {
	sort_quat(d, n);
	
//	int i=n-1;
//	
//	while(i>=0 && p>=d[i].giaban) {
//		cnt2++;
//		selected2[i]=true;
//		p-=d[i].giaban;
//		i--;
//	}

	for(int i=n-1; i>=0; i--) {
		if(p>=d[i].giaban) {
			cnt2++;
			selected2[i]=true;
			p-=d[i].giaban;
		}
	}

	if(p==0) return true;
	return false;
}

void result() {
	
	for(auto x:d) {
		display_quat(x);
	}
	
	cout<<"-----\n";
	
	sort_quat(d, n);
	
	for(auto x:d) {
		display_quat(x);
	}
	
	cout<<"-----\n";
	
	if(buy_quat(d, n, p, cnt, selected)) {
		cout<<"So quat toi da co the mua la: "<<cnt<<endl;
		for(int i=0; i<n; i++) {
			if(selected[i]) display_quat(d[i]);
		}
	} else {
		cout<<"Khong mua duoc quat\n";
	}
	
	cout<<"-----\n";
	
	
	if(buy_quat2(d, n, p, cnt2, selected2)) {
		cout<<"So quat it nhat can mua la: "<<cnt2<<endl;
		for(int i=0; i<n; i++) {
			if(selected2[i]) display_quat(d[i]);
		}
	} else {
		cout<<"Khong mua duoc quat\n";
	}
	
	
}

int main() {
	result();

	return 0;
}
