#include<bits/stdc++.h>
using namespace std;

int char_in_string(char x, string p) {
	for(int i=p.length()-1; i>=0; i--) {
		if(p[i]==x) return i;
	}
	return -1;
}

int Boyer_Moore_Horspool(string p, string t) {
	int dem=0, v=p.length(), i=v;
	while(i<=t.length()) {
		int j = i-1;
		int x = v -1;
		while(p[x]==t[j] && x>=0) {
			x--; j--;
		}
		if(x<0) {
			dem++;
			i+=v;
		} else {
			int k = char_in_string(t[j], p);
			if(k<0) {
				i+=v;
			} else {
				i+=v-k-1;
			}
		}
	}
	return dem;
}


int main() {
	string p = "con";
	string t = "dang can tim xau con trong xau con nay co bao nhieu xau con";
	
	cout<<Boyer_Moore_Horspool(p, t);
	



	return 0;
}

