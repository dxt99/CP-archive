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
typedef pair<ll,pii> st;
typedef priority_queue <st, vector<st>, greater<st>> pqmin;
const int INF = 2e9;
const int MOD = 1e9+7;

const int p=1e5+5;
ll dist[p][2];

struct edges{
    int v,w;
};

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<edges>>adj1(n);
    vector<vector<edges>>adj2(n);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--;v--;
        adj1[u].pb({v,w});
        adj2[v].pb({u,w});
    }
    for(int i=1;i<n;i++){
        dist[i][0]=INF;
        dist[i][1]=INF;
    }
    pqmin pq;
    pq.push({0,{0,0}});
    while(!pq.empty()){
        st x=pq.top();
        pq.pop();
        int u=x.sc.fs;
        int state=x.sc.sc;
        ll d=x.fs;
        if(d>dist[u][state])continue;
        if(state==0){
            // keluar simpul
            for(edges v:adj1[u]){
                if(dist[u][state]+v.w<dist[v.v][0]){
                    dist[v.v][0]=dist[u][state]+v.w;
                    pq.push({dist[v.v][0],{v.v,0}});
                }
            }
            // masuk simpul
            for(edges v:adj2[u]){
                if(dist[u][state]+v.w<dist[v.v][1]){
                    dist[v.v][1]=dist[u][state]+v.w;
                    pq.push({dist[v.v][1],{v.v,1}});
                }
            }
        }else{
            // masuk simpul
            for(edges v:adj2[u]){
                if(dist[u][state]+v.w<dist[v.v][1]){
                    dist[v.v][1]=dist[u][state]+v.w;
                    pq.push({dist[v.v][1],{v.v,1}});
                }
            }
        }
    }
    for(int i=1;i<n;i++){
        ll ans=min(dist[i][0],dist[i][1]);
        if(ans==INF){
            cout<<-1<<" ";
        }else{
            cout<<ans<<" ";
        }
    }
    cout<<endl;
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
