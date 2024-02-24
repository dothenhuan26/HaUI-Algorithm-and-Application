#include<bits/stdc++.h>
using namespace std;

int n=7, k=6;
char s[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
int a[1000]{0};
int dem=0,flag;

void init() {
	for(int i=1; i<=k; i++) a[i]=i;
}

void view(int a[], int k, char s[]) {
	for(int i=1; i<=k; i++)
		cout<<s[a[i]-1]<<" ";
	cout<<endl;
}
 
void next_config(int a[], int k, int i) {
	a[i]++;
	for(int j=i+1; j<=k; j++) 
		a[j] = a[j-1]+1;
}

void generate(int a[], int n, int k, char s[]) {
	int i=k;
	while(i>=1 && a[i]==n-k+i) i--;
	if(i>=1) {
		next_config(a, k, i);
	} else {
		flag=0;
	}
}

void select(int a[], int n, int k, char s[], int &cnt) {
	flag = 1;
	init();
	while(flag) {
		cnt++;
		view(a, k, s);
		generate(a, n, k, s);
	}
}

void Try(int i) {
	for(int j=a[i-1]+1; j<=n-k+i; j++) {
		a[i]=j;
		if(i==k) {
			view(a, k, s);
			dem++;
		}
		else Try(i+1);
	}
}

int main() {
	int cnt=0;
	cout<<"So cach lay "<<k<<" ky tu khac nhau tu tap S la: \n";
	select(a, n, k, s, cnt);
	cout<<cnt;
	cout<<endl;
	
	init();
	Try(1);
	cout<<dem;
	
	return 0;
}

