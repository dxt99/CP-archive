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

vl arr(N);
vl l(N);
vl r(N);
bool dead[N];

void solve(){
	ll n; cin>> n;
    ll sum = 0;
    priority_queue<pl> pq;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        sum += arr[i];
        l[i] = i-1;
        r[i] = i+1;
        pq.push(mp(arr[i], -1ll*i));
    }
    // non hegemony
    while(!pq.empty()){
        pl pair = pq.top();
        ll val = pair.first;
        ll idx = pair.second * -1;
        // if dead
        if (dead[idx] || arr[idx] != val) {
            pq.pop();
            continue;
        }
        // if hegemony
        if (val * 2 > sum) break;
        // else
        // kill this country
        pq.pop();
        ll half = val / 2;
        sum -= val;
        dead[idx] = 1;
        cout<<idx + 1<<" "<<val<<endl;
        // update neighbours
        if (r[idx] != n){
            int i = r[idx];
            l[r[idx]] = l[idx];
            sum += half;
            arr[i] += half;
            pq.push(mp(arr[i], -1ll*(i)));
        }
        if (l[idx] != -1){
            int i = l[idx];
            r[l[idx]] = r[idx];
            sum += half;
            arr[i] += half;
            pq.push(mp(arr[i], -1ll*(i)));
        }
    }

    // start hegemony
    minh mpq;
    for(int i=0; i<n; i++){
        if (!dead[i])mpq.push(mp(arr[i], i));
    }

    // run hegemony
    while(!mpq.empty()){
        pl pair = mpq.top();
        ll val = pair.first;
        ll idx = pair.second;
        // if dead
        if (dead[idx] || arr[idx] != val) {
            mpq.pop();
            continue;
        }
        // else, kill this country
        mpq.pop();
        ll half = val / 2;
        sum -= val;
        dead[idx] = 1;
        //cout<<"!";
        cout<<idx + 1<<" "<<val<<endl;
        // update neighbours
        if (r[idx] != n){
            int i = r[idx];
            l[r[idx]] = l[idx];
            sum += half;
            arr[i] += half;
            mpq.push(mp(arr[i], i));
        }
        if (l[idx] != -1){
            int i = l[idx];
            r[l[idx]] = r[idx];
            sum += half;
            arr[i] += half;
            mpq.push(mp(arr[i], i));
        }
    }
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
