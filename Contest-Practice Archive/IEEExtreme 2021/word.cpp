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
const int maxN=1e3+3;

ll r,c,q; 
char arr[maxN][maxN];
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
pl ans1;
pl ans2;

void search(string s){
	ans1=mp(-1,-1);
	ans2=mp(-1,-1);
	ll idx=0;
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			for(int k=0;k<8;k++){
				ll a=i; ll b=j;
				while(idx<s.size()&&s[idx]==arr[a][b]){
					a+=dx[k]; b+=dy[k];
					idx++;
				}
				if(idx==s.size()){
					ans1=mp(i-1,j-1);
					ans2=mp(a-1-dx[k],b-1-dy[k]);
					return;
				}
				idx=0;
			}
		}
	}
}

void solve(){
	cin>>r>>c>>q;
	for(int i=1;i<=r;i++){
		string s; cin>>s;
		for(int j=1;j<=c;j++){
			arr[i][j]=s[j-1];
		}
	}
	for(int i=0;i<q;i++){
		string s; cin>>s;
		search(s);
		if(ans1.fs==-1)cout<<-1<<endl;
		else{
			cout<<ans1.fs<<" "<<ans1.sd<<endl;
			cout<<ans2.fs<<" "<<ans2.sd<<endl;
		}
	}
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	for(int i=0;i<maxN;i++){
		for(int j=0;j<maxN;j++)arr[i][j]='#';
	}
	int t=1;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}

