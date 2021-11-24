#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<pair<ll,ll>>> vll;

const int N = 1e6 + 3, Mod = 1e9 + 7;

void solve(){
	string s;
	cin>>s;
	bool nol=0;
	char prev=s[0];
	int change=0;
	bool one=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')nol=1;
		else one=1;
		if(s[i]!=prev){
			change++;
			prev=s[i];
		}
	}
	if(!nol)cout<<0<<endl;
	else if(!one)cout<<1<<endl;
	else if(s[0]=='1'&&change>2)cout<<2<<endl;
	else if(s[0]=='0'&&change>1)cout<<2<<endl;
	else cout<<1<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
