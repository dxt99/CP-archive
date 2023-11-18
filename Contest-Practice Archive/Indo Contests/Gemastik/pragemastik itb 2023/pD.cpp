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
	string a, b;
	cin>>a>>b;
	
	
	if(n>2){
		if(a[0] > b[0]){
			cout<<"YES\n";
			cout<<"2 3\n";
			return;
		}
		for(int i=1; i<n; i++){
			if (a[i]>b[i]){
				cout<<"YES\n";
				cout<<"1 "<<i+1<<endl;
				return;
			}
		}
		cout<<"NO\n";
	}else{
		if (a[1]<b[1]){
			cout<<"NO\n";
		}else if (a[1] == b[1] && a[0] <= b[0]){
			cout<<"NO\n";
		}else{
			cout<<"YES\n";
			cout<<"1 2\n";
		}
	}
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
//	cin>>t;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
