#include<bits/stdc++.h>
using namespace std;

void move(int n, char a, char b, char c) {
	if(n==1) {
		cout<<"Chuyen tu cot "<<a<<" sang cot "<<c<<endl;
		return;
	}
	move(n-1, a, c, b);
	move(1, a, b, c);
	move(n-1, b,a,c);
}

int main() {
	move(3, 'A', 'B', 'C');
	return 0;
}

