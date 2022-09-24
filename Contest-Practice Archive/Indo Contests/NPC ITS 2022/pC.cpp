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

ll b[maxN][maxN];

void f(int seedx, int seedy){
	for(int i=seedx; i<maxN; i++)b[i][seedy]=1;
	for(int i=seedy; i<maxN; i++)b[seedx][i]=1;
	for(int i=0; max(seedx+i,seedy+i)<maxN; i++)b[seedx+i][seedy+i]=1;
	b[seedx][seedy]=2;
}

void start(){
	int seedx = 0;
	int seedy = 0;
	f(seedx, seedy);
	while(seedx<maxN){
		seedx++;
		if(seedx == maxN)break;
		for(int i=0; i<maxN; i++){
			if(b[seedx][i]==0){
				seedy=i;
				f(seedx,seedy);
				break;
			}
		}
	}
}

void solve(){
	ll n,m,x,y;
	n--;
	m--;
	scanf("%lld %lld %lld %lld", &n, &m, &x, &y);
	if(x==0 && y==0){
		printf("Draw\n");
	}else if(x>n||y>m){
		printf("Draw\n");
	}else if(b[x][y]==1)printf("Pisi\n");
	else printf("Eva\n");
}
 
int main(){
	start();
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
	scanf("%d",&t);
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
