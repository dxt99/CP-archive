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
	priority_queue<ll> pq;
	ll f=1;
	ll bef=0;
	ll sum=0;
	for(int i=0; i<n ;i++){
		ll x; cin>>x;
		sum+=x;
		pq.push(x);
	}
	while(sum>0){
		sum-=f;
		if(sum==0)break;
		ll temp = f;
		f+=bef;
		bef=temp;
	}
	if(sum<0){
		cout<<"NO\n";
		return;
	}
	ll temp = 0;
	while(bef>0){
		ll top = pq.top();
		pq.pop();
		if(top<f){
			cout<<"NO"<<endl;
			return;
		}
		top-=f;
		if(temp>0)pq.push(temp);
		temp = top;
		ll x = bef;
		bef = f - bef;
		f = x;
	}
	if(pq.top()==1 && temp==0 && pq.size()==1)cout<<"YES\n";
	else cout<<"NO\n";
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
