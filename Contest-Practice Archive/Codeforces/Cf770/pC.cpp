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
	int n,m; cin>>n>>m;
	if(m==1){
		cout<<"YES"<<endl;
		for(int i=1;i<=n;i++)cout<<i<<endl;
		return;
	}
	if(n%2==1){
		cout<<"NO"<<endl;
		return;
	}
	cout<<"YES"<<endl;
	for(int i=0;i<n;i+=2){
		for(int j=1;j<3;j++){
			int cur=i*m+j;
			for(int k=0;k<m;k++){
				cout<<cur<<" ";
				cur+=2;
			}
			cout<<endl;
		}
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
