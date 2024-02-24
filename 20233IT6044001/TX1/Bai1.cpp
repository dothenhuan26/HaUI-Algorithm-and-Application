#include<bits/stdc++.h>
using namespace std;

int n=4;
char chairs[] = {'A', 'B', 'C', 'D'};
string str[]={"Tung", "Cuc", "Truc", "Mai"};
int x[1000], used[1000]{0};

void init() {
	for(int i=1; i<=n; i++) x[i]=i;
}


void view_pos(int n, string str[], char chairs[],int a[]) {
	for(int i=1; i<=n; i++) 
		cout<<chairs[i-1]<<" - "<<str[a[i]-1]<<", ";
	cout<<endl;
}

void next_config(int a[], int n ,int i) {
	int j=n;
	while(a[i]>a[j]) j--;
	swap(a[i], a[j]);
	int r = n; i++;
	while(r>i) {
		swap(a[r], a[i]);
		i++;
		r--;
	}
}

void gen_pos(int n, string str[], char chairs[]) {
	int a[n+1]{0};
	for(int i=1; i<=n; i++) a[i]=i;
	int i;
	do {
		view_pos(n, str, chairs, a);
		i=n-1;
		while(i>=1 && a[i]>a[i+1]) i--;
		if(i>0) {
			next_config(a, n, i);
		}
	} while(i>=1);
}

void Try(int i) {
	for(int j=1; j<=n; j++) {
		if(used[j]==0) {
			x[i]=j;
			used[j]=1;
			if(i==n) view_pos(n, str, chairs, x);
			else Try(i+1);
			used[j]=0;
		}
	}
}

int main() {
//	gen_pos(n, str, chairs);
	init();
	Try(1);
	
	return 0;
}

