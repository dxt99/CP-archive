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

void solve(){
	int l,r,k;
	cin>>l>>r>>k;
	if(l==r&&r==1){
		cout<<"NO"<<endl;
		return;
	}else if(l==r){
		cout<<"YES"<<endl;
		return;
	}
	if(l%2==0)l++;
	if(r%2==0)r--;
	r-=l;
	r/=2;
	r++;
	if(k>=r)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
	cin>>t;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
