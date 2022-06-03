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

vector<ll> m[5005];

void solve(){
	int n; cin>>n;
	ll arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	ll x=(1<<(n))-1;
	for(int i=0;i<x;i++){
		int j=0;
		int temp=i;
		ll sum=0;
		while(temp>0){
			if(temp%2){
				sum+=arr[j];
			}
			j++;
			temp/=2;
		}
		m[sum].pb(i);
	}
	for(int i=5000;i>0;i--){
		if(m[i].size()>=2){
			for(int a=0;a<m[i].size();a++){
				for(int b=a+1;b<m[i].size();b++){
					if((m[i][a]&m[i][b])==0){
						cout<<i<<endl;
						return;
					}
				}
			}
		}
	}
	cout<<0<<endl;
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
