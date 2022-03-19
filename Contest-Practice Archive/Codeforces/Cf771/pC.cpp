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

void solve(){
	int n; cin>>n;
	int maxi=0;
	int hsh[n+5];
	int arr[n+5];
	dsu d(n);
	for(int i=0;i<n;i++){
		int x; cin>>x;
		arr[i]=x;
		hsh[x]=i;
	}
	maxi=0;
	for(int i=0;i<n;i++){
		if(arr[i]>maxi){
			maxi=arr[i];
			int j=1;
			while(j<maxi){
				if(hsh[j]>i){
					d.unite(hsh[j],i);
				}
				j++;
			}
		}
	}
	cout<<d.totSets()<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
	cin>>t;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
