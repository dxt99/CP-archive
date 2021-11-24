#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<pair<ll,ll>>> vll;

const int N = 1e6 + 3, Mod = 1e9 + 7;
ll arr[N];
ll pre[N];
ll prepre[N];
ll sufpre[N];
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	ll n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>arr[i];
	pre[0]=arr[0];
	for(int i=1;i<n;i++)pre[i]=arr[i]+pre[i-1];
	if(pre[0]==pre[n-1]/3)prepre[0]++;
	for(int i=1;i<n;i++){
		prepre[i]=prepre[i-1];
		if(pre[i]==pre[n-1]/3)prepre[i]++;
	}
	if(pre[n-1]-pre[n-2]==pre[n-1]/3)sufpre[0]++;
	for(int i=1;i<n-1;i++){
		sufpre[i]=sufpre[i-1];
		if(pre[n-1]-pre[n-2-i]==pre[n-1]/3)sufpre[i]++;
	}
	sufpre[n-1]=sufpre[n-2];
	ll ans=0;
	for(int i=1;i<n-1;i++){
		if(pre[i-1]==pre[n-1]/3)ans+=sufpre[n-2-i];
	}
	if(pre[n-1]%3==0)cout<<ans<<endl;
	else cout<<0<<endl;
}
