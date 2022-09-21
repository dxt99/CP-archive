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
	ll n; cin>>n;
	vl arr(n);
	for(int i=0; i<n; i++)arr[i]=i+1;
	ll ans=0;
	do {
		vl newarr(n);
		for(int i=0; i<n; i++){
			newarr[arr[i]-1]=i+1;
		}
		for(int i=0; i<n; i++){
			if(abs(arr[i]-newarr[i])>1)break;
			if(i==n-1){
				ans++;
				for(auto x: arr)cout<<x<<" ";
				cout<<endl;
			}
		}
	} while (next_permutation(arr.begin(), arr.end()));
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
