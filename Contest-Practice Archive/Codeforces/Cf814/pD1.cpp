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
	int n; cin>>n;
	vl arr(n);
	for(int i=0; i<n; i++)cin>>arr[i];
	vl pre(n); pre[0]=arr[0];
	for(int i=1; i<n ;i++)pre[i]=pre[i-1]^arr[i];
	int ans=0;
	for(int i=0; i<n; i++){
		int cur = arr[i];
		if (cur==0)continue;
		int cntCur = 0, cnt=0;
		int rCur, rCnt;
		map<int,int> mp;
		for(int j=i; j<n; j++){
			mp[pre[j]]++;
			if(pre[j]==0)rCnt=j;
		}
		cnt=mp[0];
		// zero wins, jump
		if((cnt!=0)){
			//cout<<ans<<endl;
			ans+=rCnt+1-i-cnt;
			i=rCnt;
		}else{
			// num wins, continue
			ans++;
			for(int j=i; j<n; j++)pre[j]^=cur;
		}
	}
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
