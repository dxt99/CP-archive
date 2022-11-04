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

int a[15][26];

void solve(){
    int n=7647;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<sz(s);j++){
            a[j][s[j]-'a']++;
        }
    }
    vector<vector<pii>>cnt(15);
    for(int i=0;i<8;i++){
        for(int j=0;j<26;j++){
            cnt[i].pb({a[i][j],j});
        }
        sort(cnt[i].begin(),cnt[i].end());
        reverse(cnt[i].begin(),cnt[i].end());
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<10-(i==7?1:0);j++){
            char c='a'+cnt[i][j].sc;
            cout<<c;
        }
        cout<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;

    freopen("input.txt", "r", stdin);

    while(t--){
        solve();
    }

    cin.get();
    return 0;
}
