#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6+3;
int ans[N];

bool isDiv(char a, char b, char c){
	int n = (a-'0')*100 + (b-'0')*10 + (c-'0');
	return n%8==0;
}

int main(){
	string s; cin>>s;
	int n=s.size();
	// threes
	for(int i=0; i+2<n; i++){
		if(isDiv(s[i], s[i+1], s[i+2]))ans[i]++;
	}
	for(int i=n-2; i>=0; i--)ans[i]+=ans[i+1];
	// twos
	for(int i=0; i+1<n; i++){
		if(isDiv('0', s[i], s[i+1]))ans[i]++;
	}
	// ones
	for(int i=0; i<n; i++){
		if(isDiv('0', '0', s[i]))ans[i]++;
	}
	for(int i=0; i<n; i++)cout<<ans[i]<<" ";
	cout<<endl;
}
