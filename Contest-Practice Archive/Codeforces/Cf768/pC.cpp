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
	ll n; cin>>n;
	ll k; cin>>k;
	ll key=n-k-1;
	if(k==n-1&&n<8)cout<<-1<<endl;
	else if(k==n-1){
		cout<<n-1<<" "<<n-2<<endl;
		cout<<1<<" "<<3<<endl;
		cout<<n-3<<" "<<0<<endl;
		cout<<n-4<<" "<<2<<endl;
		for(int i=4;i*2<n;i++){
			cout<<i<<" "<<n-1-i<<endl;
		}
	}
	else{
		for(int i=0;i*2<n;i+=1){
			if(i==0){
				cout<<0<<" "<<key<<endl;
			}else if(i==k||i==key){
				cout<<n-1<<" "<<k<<endl;
			}else{
				cout<<i<<" "<<n-i-1<<endl;
			}
		}
	}
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
