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
	ll v; cin>>v;
	map<string, ll> p[5];
	for(int k=0; k<5; k++){
		ll pn; cin>>pn;
		for(int i=0; i<pn; i++){
			string s; cin>>s;
			ll cst; cin>>cst;
			p[k][s]=cst;
		}
	}
	vl ls;
	map<ll, string> kk;
	for(auto a: p[0]){
		for(auto b: p[1]){
			ls.pb(-1*(a.sd+b.sd));
			kk[-1*(a.sd+b.sd)] = a.fs+"\n"+b.fs;
		}
	}
	sort(ls.begin(), ls.end());
	pair<ll, string> maxi = mp(0, "");
	for(auto c: p[2]){
		for(auto d: p[3]){
			for(auto e: p[4]){
				ll cur = c.sd+d.sd+e.sd;
				if(cur>=v)continue;
				string name = c.fs+"\n"+d.fs+"\n"+e.fs;
				ll it = lower_bound(ls.begin(), ls.end(), cur-v)-ls.begin();
				cur += -1 * ls[it];
				name = kk[ls[it]] + "\n" + name;
				if(cur > maxi.fs){
					maxi = mp(cur, name);
				}else if(cur == maxi.fs && name < maxi.sd){
					maxi = mp(cur, name);
				}
				
			}
		}
	}
	cout<<maxi.sd<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
	//cin>>t;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
