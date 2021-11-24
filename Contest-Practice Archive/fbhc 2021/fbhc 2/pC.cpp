#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<pair<ll,ll>>> vll;
const int N = 1e6 + 3, Mod = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	//filing
	ifstream inn;
	string filename;
	cin>>filename;
	inn.open(filename);
	int t;
	inn>>t;
	ofstream out;
	out.open("out.txt");
	
	for(int time=0;time<t;time++){
		ll n;
		inn>>n;
		vll adj;
		for(int i=2;i<n;i++){
			int x,y,z;
			inn>>x>>y>>z;
			adj[--x].pb(mp(--y,z));
			adj[y].pb(mp(x,z));
		}
		out<<"Case #"<<time+1<<": ";
	}
	inn.close();
	out.close();
}
