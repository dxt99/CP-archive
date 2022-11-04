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

const int N = 1e6 + 3, Mod = 998244353;
const int maxN=1e6+3;

ll len[maxN];
void preprocess(){
	len[0]=1;
	len[1]=1;
	len[2]=1;
	len[3]=2;
	for(int i=4; i<maxN; i++)len[i]=(len[i-1]+len[i-3]+1)%Mod;
}

void solve(){
	ll n,f; cin>>n>>f;
	if(f==1){
		for(int i=0; i<n; i++){
			if(i==0||i==n-1)cout<<1<<" ";
			else cout<<0<<" ";
		}
		cout<<endl;
		return;
	}
	for(ll i=1; i<=n; i++){
		if(i==1||i==n)cout<<len[n];
		else{
			ll tmp = min(i, n-i+1);
			tmp = tmp*2-1;
			cout<<(len[n-tmp]+len[n-tmp+1])%Mod;
		}
		cout<<" ";
	}
	cout<<endl;
}
 
int main(){
	preprocess();
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
//	cin>>t;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
