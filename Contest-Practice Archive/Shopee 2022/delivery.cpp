#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fs first
#define sd second
using namespace std;

struct point{
	int x;
	int y;
};

bool operator < (point p, point q){
	return p.x>q.x; 
}

bool operator > (point p, point q){
	return p.x<q.x;
}


typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pl;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vll;
typedef vector<pair<ll,pl>> vlll;
typedef priority_queue <pair<int,point>, vector<pair<int,point>>, greater<pair<int,point>>> minh;

const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN=1e3+3;


int n,m;
int arr[maxN][maxN];
bool vst[maxN][maxN];
vector<point> adj[300];

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};


bool valid(int x, int y){
	return (x>=0)&&(x<n)&&(y>=0)&&(y<m);
}

void solve(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
			if(arr[i][j]){
				int temp = arr[i][j];
				point t = {i,j};
				adj[temp].pb(t);
			}
		}
	}
	int ans=0;
	minh q;
	point o = {0,0};
	vst[0][0]=1;
	q.push(mp(0,o));
	while(!q.empty()){
		point p = q.top().sd;
		int d = q.top().fs;
		q.pop();
		if(p.x==n-1 && p.y==m-1){
			ans=d;
			break;
		}
		if(arr[p.x][p.y]){
			point r = {0,0};
			vector<point> s = adj[arr[p.x][p.y]];
			for(int i=0;i<(int)s.size();i++)if(s[i].x!=p.x || s[i].y!=p.y){
				r=s[i];
				if(valid(r.x,r.y)&&!vst[r.x][r.y]){
					q.push(mp(d,r));
					vst[r.x][r.y]=1;
				}
			}	
		}
		for(int i=0;i<4;i++){
			o = {p.x+dx[i],p.y+dy[i]};
			if(valid(p.x+dx[i],p.y+dy[i]))if(vst[p.x+dx[i]][p.y+dy[i]]==0){
				q.push(mp(d+1,o));
				vst[p.x+dx[i]][p.y+dy[i]]=1;
			}
		}
		
	}
	cout<<ans<<endl;
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
	
	return 0;
}
