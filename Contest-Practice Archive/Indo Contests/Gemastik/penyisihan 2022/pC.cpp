#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fs first
#define sc second
#define sz(x) (int)(x.size())
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
typedef priority_queue <ll, vector<ll>, greater<ll>> pqmin;
const int INF = 2e9;
const int MOD = 1e9+7;

pll fib (ll n) {
    if (n == 0)
        return {0, 1};

    pll p = fib(n >> 1);
    ll c = (p.first * (2 * p.second - p.first))%MOD;
    ll d = ((p.first * p.first)%MOD + (p.second * p.second)%MOD)%MOD;;
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}


void solve(){
    ll n;
    cin>>n;
    ll ans=0;
    if(n==1){
        ans=1;
    }else{
        ans=fib(n+1).fs;
        ans=(ans*ans)%MOD;
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;

    while(t--){
        solve();
    }

    cin.get();
    return 0;
}
