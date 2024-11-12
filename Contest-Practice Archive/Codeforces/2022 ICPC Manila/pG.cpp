#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fs first
#define sd second
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
typedef vector<pair<ll,ll>> vll;
typedef priority_queue <pl, vector<pl>, greater<pl>> minh;

const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN=1e3+3;


void solve(){
	ll n; cin>> n;
    ll k; cin>>k;
    ll ans = 0;
    minh pq;
    for (int i=0; i<n; i++){
        ll a, b; cin>>a>>b;
        if(b-a >= k){
            ans ++;
            continue;
        }
        a = a % k;
        b = b % k;
        if (b < a) b += k;
        pq.push(mp(a, (ll)1));
        pq.push(mp(b+1, (ll)-1));
        b += k;
        a += k;
        pq.push(mp(a, (ll)1));
        pq.push(mp(b+1, (ll)-1));
    }
    ll maxi = 0;
    ll cur = 0;
    while(!pq.empty()){
        pl pair = pq.top();
        pq.pop();
        ll pos = pair.first;
        cur += pair.second;
        while(!pq.empty() && pq.top().first == pos){
            cur += pq.top().second;
            pq.pop();
        }
        //cout<<start<<" "<<end<<" "<<cur<<endl;
        maxi = max(maxi, cur);
    }
    cout<<ans+maxi<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t = 1;
	//cin>>t;
	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
