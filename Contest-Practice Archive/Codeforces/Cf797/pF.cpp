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

vl b(N);

void back(string P, int m) { // call this before calling kmpSearch()
  int i = 0, j = -1; b[0] = -1; // starting values
  while (i < m) { // pre-process the pattern string P
    while (j >= 0 && P[i] != P[j]) j = b[j]; // if different, reset j using b
    i++; j++; // if same, advance both pointers
    b[i] = j; // observe i = 8, 9, 10, 11, 12 with j = 0, 1, 2, 3, 4
} }           // in the example of P = "SEVENTY SEVEN" above

int calc(string P, int n){
	int i=b[n];
	int k = i;
	if(b[n]==-1)return n;
	if(i*2>=n){
		int i=0;
		while(b[i]!=-1)i++;
		return i;
	}
	//cout<<n<<" "<<k<<endl;
	for(;i<=n;i++){
		//cout<<b[i]<<endl;
		if(b[i]!=(i-k))return n;
	}
	return k;
}

ll gcd(ll a, ll b){
	if(a>b)return gcd(b,a);
	if(a==0)return b;
	return gcd(b%a,a);
}

void solve(){
	ll n; cin>>n;
	string s; cin>>s;
	vl adj(n);
	vl cyc;
	for(ll& x: adj)cin>>x;
	for(ll& x: adj)x--;
	bool vis[n];
	for(int i=0; i<n; i++)vis[i]=0;
	for(int i=0; i<n; i++){
		if(vis[i])continue;
		int j=i;
		int cnt=1;
		vis[i]=1;
		string p = "";
		p += s[i];
		while(adj[j]!=i){
			j=adj[j];
			vis[j]=1;
			cnt++;
			p+=s[j];
		}
		back(p, cnt);
		cnt=(calc(p, cnt));
		if(cnt>0)cyc.pb(cnt);
	}
	ll ans = 1;
	for(auto x: cyc){
		ans *= (x/gcd(x,ans));
		//cout<<x<<"--";
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
