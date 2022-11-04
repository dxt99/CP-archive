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

const int N = 1e5+30, Mod = 1e9 + 7;
const int maxN=1e3+3;


long long modpow(long long x, long long y) {
    long long ret = 1;
    while (y > 0) {
        if (y & 1) ret = (ret * x) % Mod;
        y >>= 1;
        x = (x * x) % Mod;
    }
    return ret;
}

ll arr[N];


ll calc(const string& k){
	ll ans=0;
	for(int i=0; i<N; i++){
		if(k[N-i-1]=='1'){
			ans += modpow(2, i);
			ans %= Mod;
		}
	}
	return ans;
}

void solve(){
	ll n,m; cin>>n>>m;
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	string s = "";
	for(int i=0; i<N; i++){
		s += "0";
	}
	priority_queue <string, vector<string>, greater<string>> pq;
	for(int i=0; i<m; i++){
		pq.push(s);
	}
	
	sort(arr, arr+n);
	reverse(arr, arr+n);
	for(int j=0; j<n; j++){
		string a = pq.top();
		pq.pop();
		int i = N-arr[j]-1;
		while(a[i]=='1'){
			a[i]='0';
			i--;
		}
		a[i]='1';
		pq.push(a);
	}
	for(int i=0; i<m-1; i++){
		pq.pop();
	}
	string k = pq.top();
	
	cout<<calc(k)<<endl;
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
