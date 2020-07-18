#include<bits/stdc++.h>
using namespace std;

int min_size(string l,string r){
	int i = 1;
	int j = 1;
	while(l[0] != r[r.length()-1]){
		while(l[0] == l[i]){
			i++;
		}
		l.erase(0 , i);
		while(r[r.length()-1] == r[r.length()-j]){
			j++;
		}
		r.erase(r.length()-j, j);
		i=1;
		j=1;
	}
	int size = l.length() + r.length();
	return size;
}

int main(){
	string s;
	cin>>s;
	int n = s.length();
	string l = s.substr(0,n/2-1);
	string r = s.substr(n/2,n-1);
	cout<<min_size(l,r);
	return 0;
}