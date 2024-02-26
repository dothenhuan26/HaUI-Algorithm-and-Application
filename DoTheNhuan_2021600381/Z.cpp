#include<bits/stdc++.h>
using namespace std;

//void Z(string s, int *z) {
//	int n = s.length(), l=0, r=0;
//	for(int i=1; i<n; i++) {
//		if(i>r) {
//			l=r=i;
//			while(r<n && s[r-l]==s[r]) r++;
//			z[i]=r-l; r--;
//		} else if(z[i-l]<r-i+1) {
//			z[i]=z[r-l];
//		} else {
//			l=i;
//			while(r<n && s[r-l]==s[r]) r++;
//			z[i] = r-l; r--;
//		}
//	}
//}

bool Z(string p, string t, int *z) {
	string s = p+"$"+t;
	int p_len=p.length(),n = s.length(), l=0, r=0;
	z[0]=-1;
	for(int i=1; i<n; i++) z[i]=0;
	
	for(int i=1; i<n;i++) {
		if(i>r) {
			l=r=i;
			while(r<n && s[r-l]==s[r]) 
				r++;
			z[i]=r-l; 
			r--;
		} else if(z[i-l]<r-i+1) {
			z[i]=z[r-l];
		} else {
			l=i;
			while(r<n && s[r-l]==s[r]) 
				r++;
			z[i]=r-l; 
			r--;
		}
	}

	for(int i=0; i<n; i++) 
		if(z[i]==p_len) return true;

	return false;
}



int main() {
	string p = "con";
	string t = "Chuoi con nam trong mot chuoi la chuoi con cua chuoi do";
//	string s = p+"$"+t;
//	int n = s.length();
//	int z[n];
//	memset(z, 0, sizeof z);
//	z[0] = -1;
	
//	Z(s, z);
//	cout<<" ";
//	for(int i=0; i<n; i++) cout<<s[i]<<" ";
//	cout<<endl;
//	for(int i=0; i<n; i++) cout<<z[i]<<" ";

	int z[1001];
	if(Z(p,t,z)) {
		cout<<"P la xau con cua t\n";
	} else {
		cout<<"P khong la xau con cua t\n";
	}


	return 0;
}

