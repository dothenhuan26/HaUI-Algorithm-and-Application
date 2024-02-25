#include<bits/stdc++.h>
using namespace std;

struct Quat {
	string tenhang;
	string mausac;
	int giaban;
	
	Quat(string _tenhang, string _mausac, int _giaban) {
		tenhang = _tenhang;
		mausac = _mausac;
		giaban = _giaban;
	}
};

int p = 1000000;
int n = 8;
int cnt=0;
bool selected[8] = {0};
Quat d[] = {
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
	cout<<"Ten hang: "<<quat.tenhang<<" - Mau sac: "<<quat.mausac<<" - Gia ban: "<<quat.giaban<<endl;
}

void sort(Quat *d, int n) {
	for(int i=1; i<n; i++) {
		Quat x = d[i];
		int j = i -1;
		while(j>=0 && d[j].giaban<x.giaban) {
			d[j+1] = d[j];
			j--;
		}
		d[j+1] = x;
	}
}

bool handle(Quat *d, int n, int p, int &cnt, bool *selected) {
	int i=0;
	while(i<n && p>=0) {
		cnt++;
		p-=d[i].giaban;
		selected[i]=true;
		i++;
	}
	if(p>=0) return false;
	return true;
	
}

void result() {
	
	for(auto x:d) display_quat(x);
	
	cout<<"------------*"<<endl;
	
	sort(d, n);
	for(auto x:d) display_quat(x);
	
	cout<<"------------*"<<endl;
	
	if(handle(d, n, p, cnt, selected)) {
		cout<<"So quat it nhat can ban la: "<<cnt<<endl;
		for(int i=0; i<n; i++) {
			if(selected[i]) display_quat(d[i]);
		}
	} else {
		cout<<"Khong co ket qua"<<endl;
	}
	
}

int main() {

	result();

	return 0;
}

