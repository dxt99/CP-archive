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
	int arr[n];
	for(int i=0;i<n;i++)cin>>arr[i];
	reverse(arr,arr+n);
	int ans=0;
	int cnt=1;
	int k=arr[0];
	for(int i=1;i<n;){
		while(arr[i]==k&&i<n){
			cnt++;
			i++;
		}
		if(i<n){
			i+=cnt;
			cnt*=2;
			ans++;
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
