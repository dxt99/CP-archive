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



void solve(){
    ll n;
    scanf("%d",&n);
    if(n==2){
        printf("2\n");
    }else{
        ll k=1ll*(n-1)*(n-1)+1;
        k%=MOD;
        printf("%d\n",k);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while(t--){
        solve();
    }

    cin.get();
    return 0;
}
