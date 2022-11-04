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
	vl ans;
	int msb = 0;
	while((1<<msb)<=n)msb++;
	msb = 1<<(msb-1);
	for(int i=1; i<=n; i++){
		if(i<msb)cout<<"? "<<msb-1<<" "<<(i-(i^(msb-1)))<<endl;
		else cout<<"? "<<msb<<" "<<(i+(msb^i))<<endl;
		int x; cin>>x;
		if(x)ans.pb(i);
	}
	cout<<"! "<<ans.size()<<" ";
	for(auto c:ans)cout<<c<<" ";
	cout<<endl;
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
