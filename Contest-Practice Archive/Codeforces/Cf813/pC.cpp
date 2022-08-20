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
	set<int> passed;
	set<int> used;
	passed.insert(arr[0]);
	for(int i=1; i<n; i++){
		int cur = arr[i];
		int bef = arr[i-1];
		if(used.find(cur)!=used.end())cur=0;
		if(used.find(bef)!=used.end())bef=0;
		if(cur>=bef){
			passed.insert(arr[i]);
		}else{
			for(auto a: passed)used.insert(a);
			passed = {};
			passed.insert(arr[i]);
		}
	}
	cout<<used.size()<<endl;
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
