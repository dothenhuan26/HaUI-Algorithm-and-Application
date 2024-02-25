#include<bits/stdc++.h>
using namespace std;

int char_in_string(char x, string p){
	for(int i = p.length() - 1; i >= 0; i--){
		if(p[i] == x){
			return i;
		}
	}
	return -1;
}

int BoyerMooreHorspool(string p, string t){
	int dem = 0, v =p.length(), i = v;
	while(i <= t.length()){
		int j = i-1;
		int x = v - 1;
		while(p[x] == t[j] && x >= 0){
			x--; j--;
		}
		if(x < 0){
			dem++;
//			cout << i - p.length() + 1 << "\n";
			i += v;
		} else{
			int k = char_in_string(t[j], p);
			if(k < 0){
				i += v;
			} else{
				i += v - k - 1;
			}
		}
	}
	return dem;
}

int main() {
	string p = "con";
    string t = "con con day la mot chuoi co con va con";
    cout << BoyerMooreHorspool(p, t);
	
	return 0;
}

