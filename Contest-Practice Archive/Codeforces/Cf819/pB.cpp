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
	ll n, m; cin>>n>>m;
	if(n>m || (n%2==0&&m%2==1)){
		cout<<"No"<<endl;
		return;
	}
	cout<<"Yes"<<endl;
	if(n==1){
		cout<<m<<endl;
		return;
	}
	
	for(int i=0; i<n-2; i++){
		cout<<"1 ";
	}
	m-=(n-2);
	if(n%2==0){
		ll tmp = m/2;
		cout<<tmp<<" "<<tmp<<endl;
	}else{
		cout<<1<<" "<<m-1<<endl;
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
