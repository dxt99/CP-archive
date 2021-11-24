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
const int maxN=2e5+3;

ll arr[maxN];

ll binser(ll l,ll r,ll val){
	if(l>=r)return l;
	ll mid=(l+r)/2;
	//printf(".%d",mid);
	if(arr[mid]==val)return mid;
	if(arr[mid]>val&&arr[mid-1]<val)return mid;
	if(arr[mid]>val) return binser(l,mid-1,val);
	if(arr[mid]<val) return binser(mid+1,r,val);
}

void solve(){
	ll n;
	cin>>n;
	ll sum=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	sort(arr,arr+n);
	ll m;
	cin>>m;
	while(m--){
		ll a,b;
		cin>>a>>b;
		if(a>=arr[n-1])cout<<a-arr[n-1]+max(b+arr[n-1]-sum,(ll)0)<<endl;
		else if(a<=arr[0])cout<<max(b+arr[0]-sum,(ll)0)<<endl;
		else{
			ll x=binser(0,n-1,a);
			//cout<<x<<"--";
			cout<<min(max(b+arr[x]-sum,(ll)0),max(b+arr[x-1]-sum,(ll)0)+a-arr[x-1])<<endl;
		}
	}
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
