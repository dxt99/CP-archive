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
const int maxN=1e2+3;

string arr[maxN];
vl adj[maxN];
ll w[maxN];

bool exists(ll idx,ll k){
	for(auto v:adj[idx])if(v==k)return 1;
	return 0;
}

bool check(string a, string b){
	int n=min(a.size(),b.size());
	int i=0;
	while(a[i]==b[i]&&i<n)i++;
	if(i==n&&a.size()>b.size()){
		cout<<"Impossible"<<endl;
		return 0;
	}
	if(i==n)return 1;
	if(!exists(a[i]-'a',b[i]-'a')){
		adj[a[i]-'a'].pb(b[i]-'a');
		w[b[i]-'a']++;
		//cout<<b[i]-'a'<<"-";
	}
	return 1;
}

void solve(){
	ll n; cin>>n;
	for(int i=0;i<n;i++)cin>>arr[i];
	for(int i=1;i<n;i++){
		bool f=check(arr[i-1],arr[i]);
		if(!f)return;
	}
	// toposort
	vl ans;
	priority_queue <ll, vector<ll>, greater<ll>>pq;
	for(ll i=0;i<=25;i++){
		if(w[i])continue;
		pq.push(i);
	}
	while(!pq.empty()){
		ll idx=pq.top(); pq.pop();
		ans.pb(idx);
		for(auto v: adj[idx]){
			w[v]--;
			if(!w[v])pq.push(v);
		}
	}
	if(ans.size()==26)for(auto c: ans)cout<<(char)(c+'a');
	else cout<<"Impossible";
	cout<<endl;
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

