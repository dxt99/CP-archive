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
	ll n, k, m;
	cin>>n>>k>>m;
	n-=k;
	n%=2;
	n^=1;
	m = m%2;
	if(!m){
		cout<<"Kedua"<<endl; return;
	}
	k = k%3;
	if(k){
		cout<<"Pertama"<<endl; return;
	}
	if(k==2)k=1;
	k^=n;
	if(m&k)cout<<"Pertama"<<endl;
	else cout<<"Kedua"<<endl;
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
