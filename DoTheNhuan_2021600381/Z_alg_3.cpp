#include<bits/stdc++.h>
using namespace std;

bool Z(string p, string t, int *z) {
	string s = p+"$"+t;
	int p_len=p.length(), n = s.length(), left=0, right=0;
	
	z[0]=-1;
	for(int i=1; i<n; i++) z[i]=0;
	
	for(int i=1; i<n; i++) {
		if(i>right) {
			left=right=i;
			while(right<n && s[right-left]==s[right]) right++;
			z[i] = right-left;
			right--;
		} else if(z[i-left]<right-i+1) {
			z[i]=z[right-left];
		} else {
			left=i;
			while(right<n && s[right-left]==s[right]) right++;
			z[i] = right-left;
			right--;
		}
	}
	
	for(int i=0; i<n; i++) if(z[i]==p_len) return true;
	return false;
}


bool Z_alg(string p, string t, int *z) {
	string s = p+"$"+t;
	int p_len=p.length(), n=s.length(), left=0, right=0;
	z[0]=-1;
	for(int i=1; i<n; i++) z[0]=0;
	
	for(int i=1; i<n; i++) {
		if(i>right) {
			left=right=i;
			while(right<n && s[right-left]==s[right]) right++;
			z[i]=right-left;
			right--;
		} else if(z[i-left]<right-i+1) {
			z[i]=z[right-left];
		} else {
			left=i;
			while(right<n && s[right-left]==s[right]) right++;
			z[i]=right-left;
			right--;
		}
	}
	
	for(int i=0; i<n; i++) {
		if(p_len==z[i]) return true;
	}
	return false;
}

int main() {
	string p="con";
	string t = "Chuoi con nam trong mot chuoi cha la mot chuoi con";
	
	int z[1001];
	
	if(Z_alg(p, t, z)) cout<<"Co";
	else cout<<"Khong";



	return 0;
}

