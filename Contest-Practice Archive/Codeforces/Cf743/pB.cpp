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
const int maxN=1e5+3;

ll a[N],b[N];
ll ha[maxN],hb[maxN];
//ha idx minimum <=i
//hb idx minimum >=i

void solve(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		a[i]=(a[i]+1)/2;
		ha[a[i]]=i;
	}
	for(int i=2;i<=n;i++)ha[i]=min(ha[i],ha[i-1]);
	for(int i=0;i<n;i++){
		cin>>b[i];
		b[i]/=2;
		hb[b[i]]=i;
	}
	for(int i=n-1;i>=1;i--)hb[i]=min(hb[i],hb[i+1]);
	ll ans=Mod;
	for(int i=1;i<=n;i++)ans=min(ans,ha[i]+hb[i]);
	cout<<ans<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
