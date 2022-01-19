#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fs first
#define sd second
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<pair<ll,ll>,ll> pl;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vll;
typedef vector<pair<ll,pl>> vlll;
typedef priority_queue <pl, vector<pl>, greater<pl>> minh;

const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN=1e3+3;

int l,r,c;
pl a,b; // a=(x,c),y b=(-y,c),x
pl o; // (x,-y),c

void solve(){
	int n; cin>>n;
	minh left;
	minh right;
	minh one;
	for(int i=0;i<n;i++){
		cin>>l>>r>>c;
		a=mp(mp(l,c),r);
		b=mp(mp(-1*r,c),l);
		o=mp(mp(l,-1*r),c);
		left.push(a);
		right.push(b);
		one.push(o);
		//cout<<"--";
		if(one.top().fs.fs<=left.top().fs.fs&&one.top().fs.sd<=right.top().fs.fs&&one.top().sd<=left.top().fs.sd+right.top().fs.sd)cout<<one.top().sd<<endl;
		else if(left.top().fs.fs==right.top().sd){
			if(left.top().sd+right.top().fs.fs>0)cout<<left.top().fs.sd<<endl;
			else if (left.top().sd+right.top().fs.fs<0)cout<<right.top().fs.sd<<endl;
			else cout<<min(left.top().fs.sd,right.top().fs.sd)<<endl;
		}else if(left.top().sd+right.top().fs.fs==0){
			if(left.top().fs.fs<right.top().sd)cout<<left.top().fs.sd<<endl;
			else if(left.top().fs.fs>right.top().sd)cout<<right.top().fs.sd<<endl;
			else cout<<min(left.top().fs.sd,right.top().fs.sd)<<endl;
		}
		else{
			cout<<(left.top().fs.sd+right.top().fs.sd)<<endl;
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
