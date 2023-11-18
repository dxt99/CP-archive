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
	ll n, a, b; cin>>n>>a>>b;
	ll sum = a+b;
	ll mod = n % sum;
	if(!mod) mod+=sum;
	sum = (n+sum-1)/sum;
	if(sum%2){
		if(a>=mod)cout<<"Anto ";
		else cout<<"Budi ";
	}else{
		if(b>=mod)cout<<"Budi ";
		else cout<<"Anto ";
	}
	cout<<sum<<endl;
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
