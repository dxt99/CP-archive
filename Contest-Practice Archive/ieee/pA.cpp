#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fs first
#define sd second
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vll;

const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN=1e5+3;

ll n,m;
ll arr[N];
vl ans;

bool count(ll i, ll rem){
	if(rem<0)rem+=m;
	if(arr[i]%m==0){
		ans={i+1};
		return 0;
	}
	if(arr[i]%m==rem){
		ans.pb(i+1);
		return 1;
	}
	if(i==n-1)return 0;
	if(count(i+1,rem-(arr[i]%m))){
		ans.pb(i+1);
		return 1;
	}
	if(count(i+1,rem))return 1;
	return 0;
}

void solve(){
	ans.clear();
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	count(0,m);
	cout<<ans.size()<<endl;
	for(auto k:ans)cout<<k<<" ";
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
