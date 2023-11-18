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
const int maxNum = 1e6;

bool vis[N];

void solve(){
	int s, t; cin>>s>>t;
	queue<pl> q;
	q.push(mp(s, 0));
	vis[s]=1;
	while(!q.empty()){
		pl p = q.front();
		q.pop();
		int num = p.fs;
		int dist = p.sd;
		vis[num] = 1;
		if(num == t){
			cout<<dist<<endl;
			return;
		}
		int arr[] = {num + 1, num - 1, num*2, num*3, num/2, num/3};
		for(auto c: arr){
			if(c<0 || c>maxNum)continue;
			if(vis[c])continue;
			q.push(mp(c, dist+1));
		}
	}
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
//	cin>>t;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
