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
	vl neg;
	vl pos;
	ll z = 0;
	vl x(n), y(n); 
	for(int i=0; i<n ;i++)cin>>x[i];
	for(int i=0; i<n ;i++)cin>>y[i];
	for(int i=0; i<n ;i++){
		ll temp = y[i]-x[i];
		if(temp>0)pos.pb(temp);
		if(temp<0)neg.pb(temp);
		if(temp==0)z++;
	}
	ll ans = z/2;
	if(z%2)neg.pb(0);
	sort(pos.begin(),pos.end());
	sort(neg.begin(),neg.end());
	reverse(neg.begin(),neg.end());
	ll rem = 0;
	int i=0;
	int j=0;
	while(i<pos.size()&&j<neg.size()){
		if(pos[i]+neg[j]>=0){
			ans++;
			j++;
		}else{
			rem++;
		}
		i++;
	}
	rem += (pos.size()-i);
	ans+=rem/2;
	cout<<ans<<endl;
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
