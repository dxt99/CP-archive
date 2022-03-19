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

struct ans{
	int x1,y1,x2,y2;
};

void solve(){
	int n,m; cin>>n>>m;
	int arr[n][m];
	for(int i=0;i<n;i++){
		string s; cin>>s;
		for(int j=0;j<m;j++)arr[i][j]=(s[j]-'0');
	}
	if(arr[0][0]==1){
		cout<<"-1"<<endl;
		return;
	}
	vector<ans> ret;
	for(int i=n-1;i>-1;i--){
		for(int j=m-1;j>0;j--){
			if(arr[i][j])ret.pb({i,j-1,i,j});
		}
		if(arr[i][0])ret.pb({i-1,0,i,0});
	}
	cout<<ret.size()<<endl;
	for(auto i:ret){
		cout<<i.x1+1<<" "<<i.y1+1<<" "<<i.x2+1<<" "<<i.y2+1<<endl;
	}
	return;
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
