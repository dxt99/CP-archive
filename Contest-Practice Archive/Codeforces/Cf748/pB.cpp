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

void solve(){
	string s; cin>>s;
	ll ans1=0;
	bool fst=0;
	for(int i=s.size()-1;i>=0;i--){
		if(fst&&(s[i]=='2'||s[i]=='7'))break;
		else if(fst)ans1++;
		if(!fst&&s[i]!='5')ans1++;
		else if(!fst&&s[i]=='5')fst=1;
		
	}
	ll ans2=0;
	fst=0;
	for(int i=s.size()-1;i>=0;i--){
		if(fst&&(s[i]=='0'||s[i]=='5'))break;
		else if(fst) ans2++;
		if(!fst&&s[i]!='0')ans2++;
		else if(!fst&&s[i]=='0') fst=1;
		
	}
	cout<<min(ans1,ans2)<<endl;
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

