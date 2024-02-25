#include<bits/stdc++.h>
using namespace std;

int k=41, n=8, dem=0;

string d[] = {
	"child is superman",
	"the bird like a child",
	"tank vlog on youtube",
	"this is a pen",
	"i love child",
	"you are beautiful",
	"never give up",
	"child can fly",
};

bool selected[100];

void sort(string *d, int n) {
	for(int i=1; i<n; i++) {
		string x = d[i];
		int j = i-1;
		while(j>=0 && x.length()>d[j].length()) {
			d[j+1]=d[j];
			j--;
		}
		d[j+1]=x;
	}
}

bool thamlam(string *d, int n, int k, int &dem, bool *selected) {
	sort(d, n);
	int i=0;
	while(k>0 && i<n) {
		if(d[i].length()<=k) {
			k-=d[i].length();
			dem++;
			selected[i]=true;
		}
		i++;
	}
	if(k==0) return true;
	return false;
}

string p = "child";
bool found[100];
int char_in_string(char x, string p) {
	for(int i=p.length()-1; i>=0; i--) {
		if(x==p[i]) return i;
	}
	return -1;
}

int boyer_moore(string p, string t) {
	int dem=0, v=p.length(), i=v;
	while(i<=t.length()) {
		int j=i-1;
		int x=v-1;
		while(t[j]==p[x] && x>=0) {
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
				i+= v-k-1;
			}
		}
	}
	return dem;
}


int search_sub_str(string *d, int n, string p, bool *found) {
	int dem=0;
	for(int i=0; i<n; i++) {
		int cnt = boyer_moore(p, d[i]);
		if(cnt>0) {
			dem++;
			found[i]=true;
		}
	}
	return dem;
}

void run() {
		
	for(auto x:d) cout<<x<<endl;
	
	cout<<"-----*\n";
	
	if(thamlam(d,n,k,dem,selected)) {
		cout<<"So xau ky tu it nhan can lay la: "<<dem<<endl;
		for(int i=0; i<n; i++) {
			if(selected[i]) cout<<d[i]<<endl;
		}
	}else {
		cout<<"Khong co ket qua\n";
	}
	
	cout<<"-----*\n";
	
	int countFound = search_sub_str(d, n, p, found);
	if(countFound>0) {
		cout<<"So xau co xuat hien la: "<<countFound<<endl;
		for(int i=0; i<n; i++) {
			if(found[i]) cout<<d[i]<<endl;
		}
	}
	
//	sort(d, n);
	
//	for(auto x:d) cout<<x<<endl;
		
		
}

int main() {

	run();
	
	
	
	
	return 0;
}

