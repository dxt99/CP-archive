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
	ll n, c, q; cin>>n>>c>>q;
	string s; cin>>s;
	vll appends;
	for(int i=0; i<c; i++){
		ll l, r; cin>>l>>r;
		appends.pb(mp(l,r));
	}
	for(int i=0; i<q; i++){
		ll pos; cin>>pos;
		vl sums;
		sums.pb(n);
		ll temp=n;
		ll idx=0;
		ll relative=-1; 
		if (pos<=temp){
			cout<<s[pos-1]<<endl;
			continue;
		}
		while(temp<pos){
			ll add = (appends[idx].sd - appends[idx].fs + 1);
			if (temp+add>=pos){
				relative = pos-temp-1;
			}
			temp+=add;
			sums.pb(temp);
			idx++;
		}
		idx--;
		relative += appends[idx].fs;
		//cout<<"relative: "<<relative<<endl;
		while(relative>n){
			//cout<<"relative: "<<relative<<endl;
			while(relative<=sums[idx])idx--;
			relative-=sums[idx];
			relative+=appends[idx].fs-1;
		}
		//cout<<"end relative"<<relative<<endl;
		cout<<s[relative-1]<<endl;
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
