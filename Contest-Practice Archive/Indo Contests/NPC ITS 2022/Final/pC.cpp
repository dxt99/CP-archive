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

const int N = 1e5+3;
const int Mod = 1e9+7;

struct pt{
	int x; int y; ll val;
};

struct info{
	ll bit; ll val;
};

pt tre[N];
info mask[N];
pt cir[20];
ll dp[N][20];

bool inCircle(pt tre, pt cir){
	ll dx = abs(tre.x-cir.x);
	ll dy = abs(tre.y-cir.y);
	return (dx*dx+dy*dy <= cir.val*cir.val)
}

int main(){
	int n, m; cin>>n>>m;
	for(int i=0; i<n; i++){
		pt& temp = tre[i];
		cin>>temp.x>>temp.y>>temp.val;
	}
	for(int i=0; i<m; i++){
		pt& temp = cir[i];
		cin>>temp.x>>temp.y>>temp.val;
	}
	for(int i=0; i<n; i++){
		mask[i].val=tre[i].val;
		for(int j=0; i<m; j++){
			if(inCircle(tre[i], cir[j])){
				mask[i].bit += (1<<j);
			}
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			
		}
	}
	
}
