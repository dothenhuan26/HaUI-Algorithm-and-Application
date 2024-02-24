#include<bits/stdc++.h>
using namespace std;

//khai bao cau truc 
struct ChuyenBay {
	string sohieu;
	long long giave;
	int soghe;
	ChuyenBay() {
	}
	ChuyenBay(string _sohieu, long long _giave, int _soghe) {
		sohieu = _sohieu;
		giave = _giave;
		soghe = _soghe;
	}
};

//fake data
int n=8, k=4;
long long giave = 700000;
ChuyenBay b[] = {
	{"VN001", 500000, 36},
	{"VN002", 700000, 40},
	{"VN003", 900000, 50},
	{"VN004", 600000, 45},
	{"VN005", 800000, 60},
	{"VN006", 1000000, 40},
	{"VN007", 300000, 70},
	{"VN008", 700000, 100},
};

int a[1000]{0};


//khoi tao mang vi tri co the lua chon
void khoitao() {
	for(int i=1; i<=k; i++) a[i]=i;
}

//hien thi thong tin chuyen bay
void view(ChuyenBay b) {
	cout<<"So hieu: "<<b.sohieu<<" - Gia ve: "<<b.giave<<" - So ghe: "<<b.soghe;
	cout<<endl;
}

//hien thi so hieu cua cac chuyen bay duoc chon
void viewSelected() {
	for(int i=1; i<=k; i++) {
		cout<<b[a[i]-1].sohieu<<" ";
	}
	cout<<endl;
}

//de qui tim cac chuyen bay co gia ve lon hon giave
void listChuyenBay(ChuyenBay b[], int n, long long giave) {
	if(n<0) return;
	if(b[n].giave>giave) view(b[n]);
	listChuyenBay(b, n-1, giave);
}

//hien thi cac chuyen bay co gia ve lon hon giave
void displayListChuyenBay(ChuyenBay b[], int n, long long giave) {
	cout<<"Nhung chuyen bay co gia ve lon hon "<<giave<<" la: \n";
	listChuyenBay(b, n-1, giave);
}

//chia de tri tim vi tri chuyen bay co gia ve nho nhat
int findGiaVeMin(ChuyenBay b[], int l, int r) {
	if(l==r) return l;
	int m = (l+r)/2;
	long long left = findGiaVeMin(b, l, m);
	long long right = findGiaVeMin(b, m+1, r);
	if(b[left].giave>b[right].giave) return right;
	return left;
}

//Hien thi chuyen co gia ve nho nhat
void displayGiaVeMin(ChuyenBay b[], int n) {
	if(n==0) {
		cout<<"Danh sach khong co may bay nao!\n";
		return;
	} 
	int pos = findGiaVeMin(b, 0, n-1);
	cout<<"Chuyen bay co gia ve thap nhat la: \n";
	view(b[pos]);
}

//Quay lui
void Try(int i) {
	for(int j=a[i-1]+1; j<=n-k+i; j++) {
		a[i]=j;
		if(i==k) {
			viewSelected();
		} else {
			Try(i+1);
		}
	}
}

//Hien thi cac phuong an
void displayRes() {
	cout<<"Cac phuong an de chon ra "<<k<<" chuyen bay tu danh sach cac chuyen bay la:\n";
	Try(1);
}

int main() {
	displayListChuyenBay(b, n ,giave);
	cout<<"*********\n";
	displayGiaVeMin(b, n);
	cout<<"*********\n";
	displayRes();
	
	return 0;
}

