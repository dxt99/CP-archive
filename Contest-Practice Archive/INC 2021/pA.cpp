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
const int maxN=1e5+3;
bool arr[maxN];

void solve(){
	int n; cin>>n;
	int ans=0;
	while(n--){
		int x; cin>>x;
		
		if(x>0){
			if(arr[x])ans++;
			arr[x]=1;
		}
		else{
			x*=-1;
			if(!arr[x])ans++;
			if(arr[x])arr[x]=0;
			
		}
	}
	cout<<ans<<endl;
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

