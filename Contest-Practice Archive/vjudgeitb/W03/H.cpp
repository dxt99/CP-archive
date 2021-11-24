#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fs first
#define sd second
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vll;

const int N = 1e6 + 3, Mod = 1e9 + 7;

ll a,b,c;
bool yesa;
bool yesb;

long long modpow(long long x, long long y){
	if(x==0&&y==0&&yesa==0&&yesb==0)return 1;
	else if(x==0)return 0;
    long long ret = 1;
    while (y > 0) {
        if (y & 1) ret = (ret * x) % Mod;
        y >>= 1;
        x = (x * x) % Mod;
    }
    return ret;
}

long long modpow2(long long x, long long y) {
	if(x==0&&y==0&&yesb==0)return 1;
	else if(x==0)return 0;
    long long ret = 1;
    while (y > 0) {
        if (y & 1) ret = (ret * x) % (Mod-1);
        y >>= 1;
        x = (x * x) % (Mod-1);
    }
    return ret;
}

void solve(){
	if(a>=Mod)yesa=1;
	if(b>=Mod-1)yesb=1;
	a%=Mod;
	b%=(Mod-1);
	cout<<modpow(a,modpow2(b,c))<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
	cin>>a>>b>>c;
	while(a!=-1){
		yesa=0; yesb=0;
		solve();
		cin>>a>>b>>c;
	}
}
