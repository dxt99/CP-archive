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

const ll N = 1e6 + 3, Mod = 1e17 + 7;
const int maxN=1e3+3;

bool isExtr(ll a, ll b, ll c){
	return ((b>a) && (b>c)) || ((b<a) && (b<c));
}

bool in(ll a, vl&arr){
	for(auto c:arr)if(c==a)return 1;
	return 0;
}

bool allIn(vl&fal, vl&arr){
	for(auto c:fal){
		if(!in(c,arr))return 0;
	}
	//cout<<"! "<<arr[1]<<" "<<arr[2]<<endl;
	return 1;
}

bool trySwap(ll l, ll r, vl&arr, vl&fal){
	if(r<l)return trySwap(r,l,arr,fal);
	if(r==l)return fal.size()==0;
	ll n=arr.size();
	if(l<1 || l>n)return 0;
	if(r<1 || r>n)return 0;
	// l-1 r r-1 ... l+1 l r+1
	if(!isExtr(arr[l-1], arr[r], arr[r-1]))return 0;
	if(l>1 && !isExtr(arr[l-2], arr[l-1], arr[r]))return 0;
	if(!isExtr(arr[l+1],arr[l],arr[r+1]))return 0;
	if(r<n && !isExtr(arr[l], arr[r+1], arr[r+2]))return 0;
	vl fix = {l-1, l, r, r+1};
	return allIn(fal, fix);
}

pl solve(ll l, ll r, vl&arr, ll n){
	arr[0]=l;
	if(n%2)arr[n+1]=l;
	else arr[n+1]=r;
	vl fal;
	for(ll i=1; i<=n; i++){
		if(arr[i]<=0)exit(0);
		if(!isExtr(arr[i-1],arr[i],arr[i+1]))fal.pb(i);
	}
	if(fal.size()>4)return mp(-1,-1);
	if(fal.size()==0)return mp(1,1);
	for(auto c: fal){
		vl tries = {c-1, c, c+1};
		for(ll i=1; i<=n; i++){
			for(auto t:tries){
				if(trySwap(i, t, arr, fal))return mp(min(i,t),max(i,t));
			}
		}
	}
	return mp(-1,-1);
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	ll t=1;
	cin>>t;
 	for(ll i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		ll n; cin>>n;
		vl arr(n+2,-1);
		for(ll i=1; i<=n; i++){
			cin>>arr[i];
			if(arr[i]<=0 || arr[i]>(ll)1e9){
				exit(0);
			}
		}
		pl a = solve((ll)-1, Mod, arr, n);
		pl b = solve(Mod, (ll)-1, arr, n);
		if(a.fs!=-1 && b.fs!=-1){
			if(a.fs<b.fs)cout<<a.fs<<" "<<a.sd<<endl;
			else cout<<b.fs<<" "<<b.sd<<endl;
		}
		else if(a.fs!=-1){
			cout<<a.fs<<" "<<a.sd<<endl;
		}else if(b.fs!=-1){
			cout<<b.fs<<" "<<b.sd<<endl;
		}else{
			cout<<"-1 -1"<<endl;
		}
	}
}
