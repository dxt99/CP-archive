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

bool fits(int l, int r, int x, int y){ //l,r fits in x,y (x l r y)
	return (l>x && r<y) || (l<x && r>y);
}

bool fitsin(int l, int r, int x, int y){ //l,r fits in x,y (x l r y)
	return (l>x && r<y);
}

bool out(int l, int r, int x, int y){ // x,y is to the right of l,r (l r x y)
	return x>r || l>y;
}

void solve(){
	int n; cin>>n;
	map<string, int> hsh; // kanan, kiri
	vll pairs;
	for(int i=1; i<=2*n; i++){
		string s; cin>>s;
		if(!hsh[s])hsh[s]=i;
		else{
			pairs.pb(mp(i,hsh[s]));
		}
	}
	vll up, down;
	sort(pairs.begin(), pairs.end());
	for(int i=0; i<pairs.size(); i++){
		pair<ll,ll> p = pairs[i];
		bool f = 1;
		for(int j=0; j<up.size()&&f; j++){
			if(!fits(p.sd,p.fs,up[j].fs,up[j].sd) && !out(p.sd,p.fs,up[j].fs,up[j].sd))f=0;
		}
		if(f){
			up.pb(mp(p.sd,p.fs));
			continue;
		}
		f = 1;
		for(int j=0; j<down.size()&&f; j++){
			if(!fits(p.sd,p.fs,down[j].fs,down[j].sd) && !out(p.sd,p.fs,down[j].fs,down[j].sd))f=0;
		}
		if(f) down.pb(mp(p.sd,p.fs));
		if(!f) {
			cout<<-1<<endl;
			return;
		}
	}
	
	vl todel;
	for(int i=0; i<up.size(); i++){
		pair<ll,ll>p = up[i];
		bool f=1;
		for(pair<ll,ll>q :down){
			if(!out(p.fs,p.sd,q.fs,q.sd))f=0;
		}
		if(f){
			todel.pb(i);
			down.pb(p);
		}
	}
	
	for(int i: todel)up.erase(up.begin()+i);
	
	int mxa = 0;
	int mxb = 0;
	for(pair<ll,ll>p: up){
		int cnt=1;
		//cout<<p.fs<<p.sd<<endl;
		for(pair<ll,ll>q :up){
			if(fitsin(p.fs,p.sd,q.fs,q.sd))cnt++;
		}
		mxa = max(cnt,mxa);
	}
	for(pair<ll,ll>p: down){
		int cnt=1;
		//cout<<"[]";
		//cout<<p.fs<<p.sd<<endl;
		for(pair<ll,ll>q :down){
			if(fitsin(p.fs,p.sd,q.fs,q.sd))cnt++;
		}
		mxb = max(cnt,mxb);
	}
	
	cout<<mxa+mxb<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
	cin>>t;
 	for(int i=0;i<t;i++){
		cout<<"Rencana#"<<i+1<<"=";
		solve();
	}
}
