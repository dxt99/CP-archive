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
	int l=1;
	int r=n;
	while(l<r){
		int mid = (l+r)/2;
		int cnt = 0;
		cout<<"? "<<l<<" "<<mid<<endl;
		for(int i=0; i<mid-l+1; i++){
			int x; cin>>x;
			if(l<=x&&x<=mid)cnt++;
		}
		if (cnt%2) r=mid;
		else l=mid+1;
	}
	cout<<"! "<<l<<endl;
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
