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

int n, m;
char arr[100][100];
char ans[100][100];
bool vis[100][100];
bool col[100][100];

int odd = 0;
int even = 0;
void bfs(int i, int j){
	if (arr[i][j]=='#' || vis[i][j])return;
	vis[i][j]=1;
	if ((i+j)%2)odd++;
	else even++;
	bfs(i+1, j);
	bfs(i-1, j);
	bfs(i, j+1);
	bfs(i, j-1);
}

void color(int i, int j){
	if (arr[i][j]=='#' || col[i][j])return;
	col[i][j]=1;
	bool f = odd > even;
	bool g = (i+j) % 2;
	if (f^g || odd==0 || even==0) ans[i][j]='O';
	else ans[i][j]='X';
	
	color(i+1,j);
	color(i-1,j);
	color(i,j+1);
	color(i,j-1);
}

void solve(){
	for(int i=0; i<100; i++){
		for(int j=0; j<100; j++)arr[i][j]='#';
	}
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		string s; cin>>s;
		for(int j=1; j<=m; j++){
			char x = s[j-1];
			arr[i][j]=x;
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if (vis[i][j])continue;
			if (arr[i][j]=='#'){
				ans[i][j]='#';
				continue;
			}
			if (vis[i][j]==0){
				odd = 0;
				even = 0;
				bfs(i, j);
				color(i, j);
			}
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cout<<ans[i][j];
		}
		cout<<endl;
	}
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
