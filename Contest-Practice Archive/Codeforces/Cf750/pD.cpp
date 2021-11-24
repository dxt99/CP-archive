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

const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN=1e5+3;

ll gcd(ll a,ll b){
	if(a>b)swap(a,b);
	if(a==0)return b;
	return gcd(b%a,a);
}

void solve(){
	ll n; cin>>n;
	ll gc=0;
	ll num=Mod;
	ll idx=0;
	ll arr[n];
	ll ans[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(!i)num=abs(arr[i]);
		gc=gcd(gc,abs(arr[i]));
		if(abs(arr[i])<abs(arr[idx])){
			idx=i;
			num=abs(arr[i]);
		}
	}
	num/=gc;
	ll cur=0;
	for(int i=0;i<n;i++){
		if(i==idx)continue;
		if(cur>=0){
			if(arr[i]>0){
				ans[i]=-1*num;
			}else{
				ans[i]=num;
			}
		}else{
			if(arr[i]>0){
				ans[i]=num;
			}else{
				ans[i]=-1*num;
			}
		}
		cur=cur+(ans[i]*arr[i]);
	}
	if(cur==0){
		ll k=(idx+1)%n;
		if(ans[k]>0){
			ans[k]+=num;
			cur+=num*arr[k];
		}else{
			ans[k]-=num;
			cur-=num*arr[k];
		}
	}
	ans[idx]=-1*(cur/arr[idx]);
	for(auto i:ans)cout<<i<<" ";
	cout<<endl;
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

