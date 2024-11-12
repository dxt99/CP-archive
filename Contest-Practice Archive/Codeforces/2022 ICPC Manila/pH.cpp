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
const ll inf = LONG_LONG_MAX;


vl b(N);
vl ans(N);
bool used[N];
void solve(){
    ll n, x; cin>>n>>x;
    vll a;
    for(int i=0; i<n; i++){
        ll temp; cin >> temp;
        a.pb(mp(temp, i));
    }
    for(int i=0; i<n; i++)cin>>b[i];
    sort(a.begin(), a.end());
    minh mincur; mincur.push(mp(inf, -1)); // put inf so this will never be empty
    minh minnon; minnon.push(mp(inf, -1));
    ll cur = -1;
    // take minimums
    for(int i=0; i<n; i++){
        pl pair = a[i];
        ll val = pair.first;
        ll idx = pair.second;
        if (val > x){
            minnon.push(mp(b[idx], idx));
        }else{
            cur = i;
            x -= val;
            ans[idx] = 1;
            mincur.push(mp(b[idx]-val, idx));
        }
    };
    // we try to take more
    while(cur >= 0){
        while(mincur.top().second != -1 && used[mincur.top().second])mincur.pop();
        pl pcur = mincur.top();
        pl pnon = minnon.top();
        ll costcur = pcur.first;
        ll costnon = pnon.first - a[cur].first;
        //cout<<costcur<<" "<<costnon<<" "<<x<<endl;
        // bob is ded
        if (min(costcur, costnon) > x) {
            break;
        };
        // we take from the same
        if (costcur <= costnon){
            used[pcur.second] = 1;
            ans[pcur.second] = 2;
            x -= costcur;
            mincur.pop();
        }
        // we take from another 
        else{
            used[a[cur].second] = 1;
            ans[a[cur].second] = 0;
            ans[pnon.second] = 2;
            x -= costnon;
            minnon.pop();
            minnon.push(mp(b[a[cur].second], a[cur].second));
        }
        while (cur >= 0 && used[a[cur].second]) cur--;
    }
    // ans
    for(int i=0; i<n; i++){
        cout<<ans[i];
    }
    cout<<endl;
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
