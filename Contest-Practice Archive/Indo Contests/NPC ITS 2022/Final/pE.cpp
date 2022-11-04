#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fs first
#define sd second
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
typedef vector<pair<ll,pl>> vll;

const int N = 1e6;
vl val(N);
vll ed;

class dsu{
	private:
		vl p, rank, setSize;
		vl sum;
		vl minSet;
		int numSets;
		ll maxSum;
	public:
		dsu(int n){
			setSize.assign(n,1);
			numSets = n;
			rank.assign(n,0);
			p.assign(n,0);
			sum.assign(n,0);
			minSet.assign(n,0);
			for(int i=0;i<n;i++)minSet[i]=i;
			maxSum = 0;
			for(int i=0;i<n;i++)p[i]=i;
		}
		void assignSum(vl arr, int n){
			for(int i=0; i<n; i++){
				sum[i]=arr[i];
				if(sum[maxSum]<sum[i])maxSum=i;
			}
		}
		int findP(int i){
			return(p[i]==i)?i:findP(p[i]);
		}
		bool isSameP(int a, int b){
			return findP(a)==findP(b);
		}
		void unite(int a, int b){
			if(!isSameP(a,b)){
				numSets--;
				int x=findP(a);
				int y=findP(b);
				if (rank[x]>rank[y]){
					p[y]=x;
					setSize[x]+=setSize[y];
					sum[x]+=sum[y];
					minSet[x]=min(minSet[x],minSet[y]);
					if(sum[maxSum]<sum[x])maxSum=x;
					if(sum[maxSum]==sum[x] && minSet[maxSum]>minSet[x])maxSum=x;
				}else{
					p[x]=y;
					setSize[y]+=setSize[x];
					sum[y]+=sum[x];
					minSet[y]=min(minSet[x],minSet[y]);
					if(sum[maxSum]<sum[y])maxSum=y;
					if(sum[maxSum]==sum[y] && minSet[maxSum]>minSet[y])maxSum=y;
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
		ll getSum(){
			return sum[maxSum];
		}
		ll getPoint(){
			return minSet[maxSum];
		}
};

int main(){
	int n,m; cin>>n>>m;
	for(int i=0; i<n; i++)cin>>val[i];
	for(int i=0; i<m; i++){
		ll x,y; cin>>x>>y;
		ll cost; cin>>cost;
		ed.pb(mp(cost, mp(x,y)));
	}
	sort(ed.begin(), ed.end());
	reverse(ed.begin(), ed.end());

	int t; cin>>t;
	vector<pl> lot; // (no, idx)
	for(int i=0; i<t; i++){
		ll x; cin>>x;
		lot.pb(mp(x, i));
	}
	sort(lot.begin(), lot.end());
	reverse(lot.begin(), lot.end());
	
	dsu mem(n);
	mem.assignSum(val, n);
	int idx = 0;
	vl ans(t);
	for(auto p: lot){
		while(idx<m && ed[idx].fs>=p.fs){
			int x=ed[idx].sd.fs;
			int y=ed[idx].sd.sd;
			mem.unite(x,y);
			idx++;
		}
	
		ans[p.sd]=mem.getPoint();
	}
	for(auto k: ans){
		cout<<k<<endl;
	}
}


