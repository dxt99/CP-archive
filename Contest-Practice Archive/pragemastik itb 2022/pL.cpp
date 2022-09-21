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
const int MAX = 1e6;
vl arr(maxN);
vl adj[maxN+1];
vl srt(maxN);
bool vs[maxN];
void solve(){
	int n; cin>>n;
	
	for(int i=0; i<n; i++)cin>>arr[i];
	for(int i=0; i<n-1; i++){
		int x,y; cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	int leaf = -1;
	for(int i=1; i<=n; i++){
		if(adj[i].size()>2){
			cout<<-1<<endl;
			return;
		}
		if(adj[i].size()==1)leaf=i;
	}
	srt[0]=arr[leaf-1];
	vs[leaf]=1;
	for(int i=1; i<n; i++){
		if(vs[adj[leaf][0]])leaf = adj[leaf][1];
		else leaf =adj[leaf][0];
		vs[leaf]=1;
		srt[i]=arr[leaf-1];
	}
	bool f1 = 1;
	bool f2 = 1;
	int prev = -1;
	for(int i=0; i<n; i++){
		if(srt[i]==-1)continue;
		if(prev==-1){
			prev=i;
			if(MAX + 1 - srt[prev]<prev+1)f2=0;
			if(srt[prev]<prev+1)f1=0;
			//cout<<f1<<" "<<f2;
			continue;
		}
		if(srt[i]-srt[prev]<i-prev)f1=0;
		if(srt[prev]-srt[i]<i-prev)f2=0;
		prev=i;
	}
	//cout<<f1<<" "<<f2;
	if(prev!=-1){
		if(MAX-srt[prev]<n-prev)f1=0;
		if(srt[prev]-0<n-prev)f2=0;
	}
	if((!f2)&&(!f1)){
		cout<<-1<<endl;
		return;
	}
	if(f1){
		int cur=1;
		for(int i=0; i<n; i++){
			if(srt[i]!=-1){
				cur=srt[i]+1;
				continue;
			}
			srt[i]=cur;
			cur++;
		}
	}
	if(f2){
		int cur = MAX;
		for(int i=0; i<n; i++){
			if(srt[i]!=-1){
				cur=srt[i]-1;
				continue;
			}
			srt[i]=cur;
			cur--;
		}
	}
	arr[leaf-1] = srt[0];
	vs[leaf]=0;
	for(int i=1; i<n; i++){
		if(!vs[adj[leaf][0]])leaf = adj[leaf][1];
		else leaf =adj[leaf][0];
		vs[leaf]=0;
		arr[leaf-1]=srt[i];
	}
	reverse(arr.begin(), arr.begin()+n);
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
	//cin>>t;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
