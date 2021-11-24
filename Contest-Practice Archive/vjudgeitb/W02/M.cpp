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
const int maxN=1e3+3;

void solve(){
	ll n;
	cin>>n;
	ll arr[n],cnt[n],ans[n];
	for(int i=0;i<n;i++)cin>>arr[i];
	memset(ans,0,sizeof(ans));
	for(int i=0;i<n;i++){
		memset(cnt,0,sizeof(cnt));
		ll maxi=i;
		for(int j=i;j<n;j++){
			cnt[arr[j]-1]++;
			if(cnt[arr[maxi]-1]<cnt[arr[j]-1])maxi=j;
			if(cnt[arr[maxi]-1]==cnt[arr[j]-1]&&arr[j]<arr[maxi])maxi=j;
			ans[arr[maxi]-1]++;
		}
	}
	for(int i=0;i<n;i++){
		cout<<ans[i];
		if(i!=n-1)cout<<" ";
	}
		
	cout<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t;
	t=1;
	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
