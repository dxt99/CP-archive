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

const int N = 1e6 + 3, Mod = 1e9 ;
const int maxN=1e3+3;

void solve(){
	ll x, n; cin>>x>>n;
	string op; cin>>op;
	if(op == "AND" || op == "OR"){
		for(int i=0; i<n; i++){
			cout<<x<<" ";
		}
		cout<<endl;
	}else{
		if(n==1)cout<<x;
		else if(n==2){
			if(x==1)cout<<"3 2";
			else{
				ll t = (x-1)^x;
				cout<<x-1<<" "<<t;
			}
		}else{
			if(n%2){
				for(int i=0;i<n-1;i++){
					cout<<1<<" ";
				}
				cout<<x;
			}else{
				cout<<"1 2 3 ";
				for(int i=0; i<n-4; i++){
					cout<<1<<" ";
				}
				cout<<x;
			}
		}
		cout<<endl;
	}
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
