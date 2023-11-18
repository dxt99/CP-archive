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

int arr[maxN][maxN];
int s,f; 
bool vis[maxN];

void solve(){
	int n; cin>>n;
	cin>>s>>f;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>arr[i][j];
		}
	}
	queue<pl> q;
	q.push(mp(s, 0));
	vis[s]=1;
	while(!q.empty()){
		pl p = q.front();
		q.pop();
		int node = p.fs;
		int dist = p.sd;
		vis[node] = 1;
		if(node==f){
			cout<<dist<<endl;
			return;
		}
		for(int i=0; i<n; i++){
			if(vis[i])continue;
			if(!arr[node][i])continue;
			q.push(mp(i, dist+1));
		}
	}
	cout<<-1<<endl;
	return;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
//	cin>>t;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
