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

ll preb[N];
ll prec[N];

void solve(){
	ll n; cin>>n;
	string s; cin>>s;
	if(n==2){
		if(s[0]=='a'&&s[1]=='a')cout<<2<<endl;
		else cout<<-1<<endl;
		return;
	}
	for(int i=0;i<=n;i++){
		preb[i]=0;
		prec[i]=0;
	}
	vl pos;
	if(s[0]=='a')pos.pb(0);
	if(s[0]=='b')preb[0]=1;
	if(s[0]=='c')prec[0]=1;
	for(ll i=1;i<n;i++){
		preb[i]=preb[i-1];
		prec[i]=prec[i-1];
		if(s[i]=='a')pos.pb(i);
		if(s[i]=='b')preb[i]++;
		if(s[i]=='c')prec[i]++;
	}
	ll mini=Mod;
	if((int)pos.size()>1)for(int i=0;i<(int)pos.size()-1;i++){
		if(preb[pos[i+1]]-preb[pos[i]]<2&&prec[pos[i+1]]-prec[pos[i]]<2)mini=min(mini,pos[i+1]-pos[i]+1);
	}
	if((int)pos.size()>2)for(int i=0;i<(int)pos.size()-2;i++){
		if(preb[pos[i+2]]-preb[pos[i]]<3&&prec[pos[i+2]]-prec[pos[i]]<3)mini=min(mini,pos[i+2]-pos[i]+1);
	}
	if(mini==Mod)cout<<-1<<endl;
	else cout<<mini<<endl;
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

