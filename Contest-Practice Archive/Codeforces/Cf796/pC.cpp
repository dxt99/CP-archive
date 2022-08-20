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
typedef vector<pair<ll,pl>> vlll;
typedef priority_queue <ll, vector<ll>, greater<ll>> minh;

const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN=1e3+3;

void solve(){
	ll n; cin>>n;
	map<char, int> zzz;
	for(int i=0; i<26; i++){
		zzz[(char)('a'+i)]=0; 
	}
	vector<string> s;
	for(int i=0; i<2*n; i++){
		string x; cin>>x;
		for(int j=0; j<=x.size(); j++){
			zzz[x[j]]+=1;
		}
	}
	string tar; cin>>tar;
	map<char, int> zz;
	for(int i=0; i<26; i++){
		zz[(char)('a'+i)]=0; 
	}
	for(int i=0; i<tar.size(); i++){
		zz[tar[i]]+=1;
	}
	for(int i=0; i<26; i++){
		if(zz['a'+i]%2 != zzz['a'+i]%2){
			cout<<(char)('a'+i)<<endl;
			return;
		}
	}
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
	cin>>t;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
