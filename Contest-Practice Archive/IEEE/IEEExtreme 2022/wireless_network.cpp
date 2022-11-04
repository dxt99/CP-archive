#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fs first
#define sd second
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<string, string> pl;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vll;
typedef vector<pair<ll,pl>> vlll;
typedef priority_queue <pair<ll, pl>, vlll, greater<pair<ll,pl>>> minh;

const ll N = 1e6 + 3, Mod = 1e12 + 7;
const int maxN=1e3+3;

class dsu{
	private:
		vl p, rank, setSize;
		int numSets;
	public:
		dsu(int n){
			setSize.assign(n,1);
			numSets=n;
			rank.assign(n,0);
			p.assign(n,0);
			for(int i=0;i<n;i++)p[i]=i;
		}
		int findP(int i){
			return (p[i]==i)?i:findP(p[i]);
		}
		bool isSameP(int a, int b){
			return findP(a)==findP(b);
		}
		void unite(int a, int b){
			if(!isSameP(a,b)){
				numSets--;
				int x=findP(a);
				int y=findP(b);
				if(rank[x]>rank[y]){
					p[y]=x;
					setSize[x]+=setSize[y];
				}else{
					p[x]=y;
					setSize[y]+=setSize[x];
					if(rank[x]==rank[y])rank[y]++;
				}
			}
		}
		int totSets(){
			return numSets;
		}
		int sizeOfSet(int i){
			return setSize[findP(i)];
		}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	ll n; cin>>n;
	vlll e;
	vlll r; //red links
	ll ans = Mod;
	set<string> names;
	set<string> redNames;
	for(int i=0; i<n; i++){
		string a,b; cin>>a>>b;
		ll c, f; cin>>c>>f;
		if(f)r.pb(mp(c,mp(a,b)));
		else e.pb(mp(c,mp(a,b)));
		names.insert(a);
		names.insert(b);
		if(f){
			redNames.insert(a);
			redNames.insert(b);
		}
	}
	vector<string> nodes;
	vector<string> redNodes;
	for(auto c: names)nodes.pb(c);
	for(auto c: redNames)redNodes.pb(c);
	n = nodes.size();
	ll m = redNodes.size();
	map<string, ll> nodesIdx;
	for(ll i=0; i<n; i++)nodesIdx[nodes[i]]=i;
	ll temp = (1<<m);
	for(ll i=0; i<temp; i++){
		map<string, int> up;
		ll cst = 0;
		for(ll idx=0; idx<m; idx++){
			up[redNodes[idx]]=0;
			ll tmp = 1<<idx;
			if((i&(tmp))){
				up[redNodes[idx]]=1;
				cst += 10000;
			}
		}
		dsu vs(n);
		ll cntEdge = 0;
		minh pq;
		for(auto edge: e){
			pq.push(edge);
		}
		for(auto edge: r){
			if(up[edge.sd.fs]||up[edge.sd.sd])pq.push(edge);
		}
		if(pq.size()<n-1)continue;
		while(!pq.empty()){
			auto edge = pq.top(); pq.pop();
			ll a=nodesIdx[edge.sd.fs];
			ll b=nodesIdx[edge.sd.sd];
			if(vs.isSameP(a,b))continue;
			cst += edge.fs;
			vs.unite(a,b);
			cntEdge ++;
			if(cntEdge == n-1) break;
			if(cst>ans)break;
		}

		if(vs.totSets()==1 && cntEdge == n-1)ans = min(ans, cst);
	}
	cout<<ans<<endl;
}
 
