#include<iostream>
#include<vector>
#include <algorithm>
#include<queue>
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
typedef priority_queue <pl> maxh;

const ll max_ll = 9223372036854775806;
vector<ll> arr;

ll calc(ll val){
    // (2n-1) * arr <= val
    // (2n-1) <= val // arr
    ll sum = 0;
    for(auto c: arr){
        sum += ((val / c) + 1) / 2;
    }
    return sum;
}

//Binary Search
ll binser(ll l,ll r,ll val){
	if(l>=r)return l;
	ll mid=(l+r)/2;
	//printf(".%d",mid);
    ll pred = calc(mid);
	if(pred>=val) return binser(l,mid,val);
	else return binser(mid+1,r,val);
}

void solve(){
    ll n, tar; cin>>n>>tar;
    arr.clear();
    for(int i=0; i<n; i++){
        ll x; cin>>x;
        arr.pb(x);
    }
    ll upper = binser(0, max_ll, tar);
    ll got = calc(upper);
    ll sum = 0;
    maxh last;
    for(ll c: arr){
        ll n = ((upper / c) + 1) / 2;
        sum += (n*n*c);
        last.push(mp((2*n-1)*c, c));
    }
    got -= tar;
    while(got > 0){
        pl p = last.top();
        last.pop();
        ll val = p.fs;
        ll c = p.sd;
        ll n = ((val / c) + 1) / 2;
        sum -= val;
        last.push(mp((2*n-3)*c, c));
        got --;
    }
    cout<<sum<<endl;
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
