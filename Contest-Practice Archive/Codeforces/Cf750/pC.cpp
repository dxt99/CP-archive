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

ll n;
string s;

ll check(char a){
	ll ret=0;
	int l=0;
	int r=s.size()-1;
	while(l<r){
		if(s[l]!=s[r]){
			if(s[l]==a){
				ret++; l++;
			}else if(s[r]==a){
				ret++; r--;
			}else{
				return Mod;
			}
		}else{
			l++; r--;
		}
	}
	return ret;
}

void solve(){
	cin>>n; cin>>s;
	ll ans=Mod;
	for(int i=0;i<26;i++){
		ans=min(ans,check(char('a'+i)));
	}
	if(ans==Mod)ans=-1;
	cout<<ans<<endl;
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

