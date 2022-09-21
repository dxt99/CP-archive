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
const int maxN=1e3+3;

void solve(){
	int ans=INT_MAX;
	int n,k;
	cin>>n>>k;
	string arr[n];
	for(int i=0;i<n;i++)cin>>arr[i];
	int p[k];
	for(int i=0;i<k;i++)p[i]=i;
	do{
		int mini=INT_MAX;
		int maxi=0;
		for(int i=0;i<n;i++){
			string s="";
			for(int j=0;j<k;j++){
				s+=(arr[i][p[j]]);
			}
			mini=min(mini,stoi(s));
			maxi=max(maxi,stoi(s));
		}
		ans=min(ans,maxi-mini);
	}while(next_permutation(p,p+k));
	cout<<ans<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t;
	t=1;
	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
