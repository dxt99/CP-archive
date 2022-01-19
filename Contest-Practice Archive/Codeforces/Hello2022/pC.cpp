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
	int arr[n+1];
	for(int i=0;i<=n;i++)arr[i]=-1;
	vl cur;
	ll x;
	for(int i=1;i<=n;i++){
		if(arr[i]!=-1)continue;
		cur.clear();
		cout<<"? "<<i<<endl;
		cin>>x;
		cur.pb(x);
		while(true){
			cout<<"? "<<i<<endl;
			cin>>x;
			if(x==cur[0])break;
			cur.pb(x);
		}
		for(int j=0;j<cur.size()-1;j++)arr[cur[j]]=cur[j+1];
		arr[cur[(ll)cur.size()-1]]=cur[0];
	}
	cout<<"! ";
	for(int i=1;i<=n;i++){
		cout<<arr[i];
		if(i!=n)cout<<" ";
	}
	cout<<endl;
	cout.flush();
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
