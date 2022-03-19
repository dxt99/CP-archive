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

void solve(int n,int plus){
	ll st[5];
	ll maxi=0;
	ll nsame=-1;
	for(ll i=1;i<5;i++){
		cout<<"? ";
		for(int j=1;j<5;j++){
			if(j==i)continue;
			cout<<j+plus<<" ";
		}
		cout.flush();
		cout<<endl;
		cout.flush();
		cin>>st[i];
		maxi=max(maxi,st[i]);
	}
	if(st[1]==st[2]&&st[1]==st[3]&&st[1]==st[4]){
		if(n>=8)solve(n-4,plus+4);
		else if(n==5)cout<<"! "<<5+plus<<" "<<5+plus<<endl;
		else if(n==6)cout<<"! "<<5+plus<<" "<<6+plus<<endl;
		else if(n==7)solve(n-3,plus+3);
		return;
	}
	vl g;
	ll tst=0;
	for(int i=1;i<5&&tst==0;i++){
		for(int j=i+1;j<5;j++){
			if(st[i]==maxi&&st[j]==maxi){
				for(int k=1;k<5;k++){
					if(k!=i&&k!=j)g.pb(k);
				}
				if(st[g[0]]!=0&&st[g[1]]!=0)tst=i;
				else if(maxi==0)tst=-2;
				else if(st[g[0]]==0){
					tst=-1;
					nsame=g[0];
				}else{
					tst=-1;
					nsame=g[1];
				}
				break;
			}
		}
	}
	for(int i=5;i<=n;i++){
		cout<<"? "<<g[0]+plus<<" "<<g[1]+plus<<" "<<i+plus<<endl;
		cout.flush();
		ll val; cin>>val;
		if(val<=maxi)continue;
		if(maxi==0){
			maxi=val;
			g[1]=i;
			tst=-1;
			nsame=i;
			continue;
		}
		maxi=val;
		if(tst>0){
			ll a;
			cout<<"? "<<g[0]+plus<<" "<<tst+plus<<" "<<i+plus<<endl;
			cout.flush(); cin>>a;
			
			if(a==maxi){
				g[1]=i;
			}else{
				g[0]=i;
			}
		}else{
			ll tmp=1;
			ll ask=g[0];
			if(nsame==ask)ask=g[1];
			while(tmp==g[0]||tmp==g[1])tmp++;
			cout<<"? "<<tmp+plus<<" "<<ask+plus<<" "<<i+plus<<endl;
			ll a; cin>>a;
			if(a==maxi){
				tst=nsame;
				g[0]=tmp;
				g[1]=i;
			}else{
				g[0]=nsame;
				tst=tmp;
				g[1]=i;
			}
		}
	}
	cout<<"! "<<g[0]+plus<<" "<<g[1]+plus<<endl;
	cout.flush();
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
	cin>>t;
 	for(int i=0;i<t;i++){
 		ll n; cin>>n;
		//cout<<"Case #"<<i+1<<": ";
		solve(n,0);
	}
}
