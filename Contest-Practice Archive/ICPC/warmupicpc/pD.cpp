#include<bits/stdc++.h>
using namespace std;

const int N=1e5+3;
typedef long long ll;
typedef vector<ll> vl;

int p[N];
vl c[N];

int main(){
	int n,q; cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>p[i+1];
		c[p[i+1]].pb(i+1);
	}
	for(int i=0;i<q;i++){
		int m; cin>>m;
		if(m==1){
			ll x,y,k; cin>>x>>y>>k;	
		}else{
			ll x; cin>>x;
		}
	}
}
