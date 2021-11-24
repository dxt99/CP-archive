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

const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN=103;

bool vis[maxN][maxN];
bool f=0;
int dx[]={1,0,0,-1};
int dy[]={0,1,-1,0};
char arr[maxN][maxN];

bool dfs(int x, int y, int px, int py){
	if(arr[x][y]=='*')return 0;
	vis[x][y]=1;
	for(int i=0;i<4;i++){
		int tx=x+dx[i];
		int ty=y+dy[i];
		if(arr[x][y]!=arr[tx][ty])continue;
		if(tx==px&&ty==py)continue;
		if(vis[tx][ty]){
			f=1;
			return 1;
		}
		if(dfs(tx,ty,x,y))return 1;
	}
	return 0;
}

void solve(){
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++){
		string s; cin>>s;
		for(int j=1;j<=m;j++){
			arr[i][j]=s[j-1];
		}
	}
	for(int i=0;i<=n+1;i++){
		arr[i][0]='*';
		arr[i][m+1]='*';
	}
	for(int i=0;i<=m+1;i++){
		arr[0][i]='*';
		arr[n+1][i]='*';
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!vis[i][j])dfs(i,j,-1,-1);
			if(f){
				cout<<"Yes"<<endl;
				return;
			}
		}
	}
	cout<<"No"<<endl;
	return;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}

