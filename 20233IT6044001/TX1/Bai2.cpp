#include<bits/stdc++.h>
using namespace std;

int n=7, k=6;
char s[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
int a[1000]{0};
int cnt=0;

void init() {
	for(int i=1; i<=k; i++) a[i]=i;
}

void view(int a[], int n, int k, char s[]) {
	for(int i=1; i<=k; i++)
		cout<<s[a[i]-1]<<" ";
	cout<<endl;
}
 
void next_config(int a[], int k, int i) {
	a[i]++;
	for(int j=i+1; j<=k; j++) 
		a[j] = a[j-1]+1;
}
 
void select(int a[], int n, int k, char s[]) {
	int i;
	do {
		cnt++;
		view(a, n, k, s);
		i=k;
		while(i>=1 && a[i]==n-k+i) i--;
		if(i>=1) {
			next_config(a, k, i);
		}
//		if(i==0) return;
//		a[i]++;
//		for(int j=i+1; j<=k; j++) 
//			a[j] = a[j-1]+1;
	} while(i>=1);
}

void handle() {
	init();
	cout<<"So cach lay "<<k<<" ky tu khac nhau tu tap S la: \n";
	select(a, n, k, s);
}

int main() {
	handle();
	
	return 0;
}

