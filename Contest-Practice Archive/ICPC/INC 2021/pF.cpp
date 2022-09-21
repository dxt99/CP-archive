#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fs first
#define sd second
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pl;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vll;

const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN=1e5+3;
string s; 
int n;
bool chc(int k){
	int l=0; int r=k;
	bool ret=1;
	while(l<r){
		if(s[l]!=s[r])ret=0;
		l++; r--;
	}
	l=k+1; r=n-1;
	while(l<r){
		if(s[l]!=s[r])ret=0;
		l++; r--;
	}
	return ret;
}
void solve(){
	cin>>s;
	n=s.size();
	for(int i=0;i<n-1;i++){
		if (chc(i)){
			for(int j=0;j<=i;j++)cout<<s[j];
			cout<<" ";
			for(int j=i+1;j<n;j++)cout<<s[j];
			cout<<endl;
			return;
		}
	}
	cout<<"NO"<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}

