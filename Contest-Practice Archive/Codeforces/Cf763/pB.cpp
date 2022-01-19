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
typedef priority_queue <pl, vector<pl>, greater<pl>> minh;

const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN=1e3+3;

void solve(){
	int n; cin>>n;
	vll q;
	for(int i=0;i<n;i++){
		int x,y; cin>>x>>y;
		q.pb(mp(x,y));
	}
	sort(q.begin(),q.end());
	int it=0;
	minh pq;
	for(int i=0;i<n;i++){
		while(it<q.size()&&q[it].fs<=i+1){
			pq.push(mp(q[it].sd,q[it].fs));
			it++;
		}
		cout<<pq.top().sd<<" "<<pq.top().fs<<" "<<i+1<<endl;
		pq.pop();
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

