#include<bits/stdc++.h>
using namespace std;

int n=10, m=5;
int c[] = {2,3,4,5,8};
int res=0;

int handle(int *c, int m, int n, int &res) {
	//sxep tang dang mang c (mang cac chai dung nuoc)
	int i=0;
	while(i<m && n>=c[i]) {
		res++;
		n-=c[i];
		i++;
	}

	if(res>0) return true;
	return false;

}

int main() {

	if(handle(c, m, n, res)) {
		cout<<"So chai toi da co the do day: "<<res<<endl;
	} else {
		cout<<"Khong co phuong an\n";
	}

	return 0;
}
