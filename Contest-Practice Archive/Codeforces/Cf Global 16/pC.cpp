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

void solve(){
	int n;
	cin>>n;
	string a,b;
	cin>>a;
	cin>>b;
	ll ans=0;
	bool nol=0;
	bool one=0;
	for(int i=0;i<n;i++){
		if(a[i]=='0')nol=1;
		else one=1;
		if(b[i]=='0')nol=1;
		else one=1;
		if(nol&&one){
			ans+=2;
			nol=0;
			one=0;
		}else if(i<n-1&&nol){
			if(!(a[i+1]=='1'&&b[i+1]=='1')){
				ans++;
				nol=0;
			}
		}
	}
	if(nol)ans++;
	cout<<ans<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
