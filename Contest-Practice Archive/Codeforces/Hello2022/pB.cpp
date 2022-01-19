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

void solve(){
	int n; cin>>n;
	int l=0;
	int lc=0;
	int r=0;
	int rc=0;
	cin>>l>>r>>lc;
	cout<<lc+rc<<endl;
	for(int i=0;i<n-1;i++){
		int x,y,c;
		cin>>x>>y>>c;
		if(x<=l&&y>=r&&c<=lc+rc){
			l=x; r=y;
			lc=c;
			rc=0;
			//cout<<lc<<"--"<<rc<<"--";
		}else if(x<l){
			l=x;
			lc=c;
			if(y>=r){
				r=y;
				rc=0;
			}
		}else if(y>r){
			r=y;
			rc=c;
			if(x<=l){
				l=x;
				lc=0;
			}
		}else if(x==l&&lc>c){
			lc=c;
		}else if(y==r&&rc>c){
			rc=c;
		}
		cout<<rc+lc<<endl;
	}
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
