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
	int a,b,c,d; cin>>a>>b>>c>>d;
	int mult = a+b;
	if(mult%2==0){
		cout<<"Tidak Tidak ";
		if(b||c)cout<<"Ya ";
		else cout<<"Tidak ";
		if(a||d)cout<<"Ya ";
		else cout<<"Tidak ";
		cout<<endl;
	}else{
		if(a||d)cout<<"Ya ";
		else cout<<"Tidak ";
		if(b||c)cout<<"Ya ";
		else cout<<"Tidak ";
		cout<<"Tidak Tidak ";
		cout<<endl;
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
