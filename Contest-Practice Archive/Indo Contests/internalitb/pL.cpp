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

map<int, int> cnt;

vl ara;
vl arb;

ll score(vl ar, ll x){
	ll num[10];
	for(int i=0; i<10; i++)num[i]=0;
	for(auto c: ar)num[c]++;
	num[x]++;
	ll ret=0;
	for(int i=1; i<10; i++){
		ret += i*(pow(10, num[i]));
	}
	return ret;
}

bool fight(ll a, ll b){
	ll sca= score(ara, a);
	ll scb= score(arb, b);
	return sca>scb;
}

void solve(){
	ll n; cin>>n;
	string a; cin>>a;
	string b; cin>>b;
	for(int i=0; i<5; i++){
		if(a[i]!='#')ara.pb(a[i]-'0');
		if(b[i]!='#')arb.pb(b[i]-'0');
	}
	for(auto a:ara)cnt[a]++;
	for(auto b:arb)cnt[b]++;
	ll tot = 0;
	ll win = 0;
	for(int i=1; i<10; i++){
		if(cnt[i]==n)continue;
		cnt[i]++;
		for(int j=1; j<10; j++){
			if(cnt[j]==n)continue;
			ll num = (n-cnt[i]+1)*(n-cnt[j]);
			tot+=num;
			if(fight(i, j))win+=num;
		}
		cnt[i]--;
	}
	double ans = (double)win/(double)tot;
	cout<<ans<<endl;
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
