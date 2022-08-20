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
	ll n,m; cin>>n>>m;
	vll val; // -length, idx
	for(int i=0; i<m; i++){
		cout<<"? ";
		for(int j=0; j<m; j++){
			if(i==j)cout<<"1";
			else cout<<"0";
		}
		cout<<endl;
		ll temp; cin>>temp;
		val.pb(mp(-1*temp,i));
	}
	string s = "";
	for(int j=0; j<m; j++) s+="1";
	cout<<"? "<<s<<endl;
	ll init; cin>>init;
	
	sort(val.begin(), val.end()); //sort
	for(int i=0; i<m-1; i++){
		s[val[i].sd] = '0';
		cout<<"? "<<s<<endl;
		ll temp; cin>>temp;
		if(temp-init == val[i].fs){
			s[val[i].sd] = '1';
		}else{
			init = temp;
		}
	}
	cout<<"! "<<init<<endl;
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
