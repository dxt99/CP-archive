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
	string a,b; cin>>a>>b;
	int arr[n+2];
	arr[0]=0;
	arr[n+1]=0;
	for(int i=0; i<n; i++){
		if(a[i]-'a'>b[i]-'a')arr[i+1]=1;
		else if(a[i]-'a'==b[i]-'a'){
			if(arr[i]==1)arr[i+1]=1;
			else arr[i+1]=0;
		}
		else arr[i+1]=0;
	}
	ll cnt = 0;
	for(int i=0; i<=n; i++){
		if(arr[i]==0 && arr[i+1]==1)cnt++;
	}
	cout<<cnt<<endl;
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
