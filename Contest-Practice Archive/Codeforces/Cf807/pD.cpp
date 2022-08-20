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
	string s; cin>>s;
	string tar; cin>>tar;
	if(s[0]!=tar[0]||s[n-1]!=tar[n-1]){
		cout<<-1<<endl;
		return;
	}
	vll ps;
	vll pt;
	ll temps, tempt;
	temps=-1;
	tempt=-1;
	for(int i=0; i<n; i++){
		if(s[i]=='1'&&temps==-1)temps=i;
		if(i==n-1||(s[i+1]=='0'&&s[i]=='1')){
			if(temps!=-1)ps.pb(mp(temps,i));
			temps=-1;
		}
		if(tar[i]=='1'&&tempt==-1)tempt=i;
		if(i==n-1||(tar[i+1]=='0'&&tar[i]=='1')){
			if(tempt!=-1)pt.pb(mp(tempt,i));
			tempt=-1;
		}
	}
	if(ps.size()!=pt.size()){
		cout<<-1<<endl;
		return;
	}
	ll ans=0;
	for(int i=0; i<ps.size(); i++){
		ans+=abs(ps[i].fs-pt[i].fs);
		ans+=abs(ps[i].sd-pt[i].sd);	
	}
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
