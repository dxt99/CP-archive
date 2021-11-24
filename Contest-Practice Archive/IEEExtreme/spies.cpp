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

const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN=1e5+3;

void solve(){
	ll n,m,q;
	cin>>n>>m>>q;
	ll p[n+m+3]; //null, r1,r2,r3,null (n+1),b1
	for(int i=1;i<n;i++){
		string s; cin>>s;
		string z=s; z.erase(0,1);
		p[i+1]=stoi(z);
		if(s[0]=='B')p[i+1]+=n;
	}
	for(int i=1;i<m;i++){
		string s; cin>>s;
		string z=s; z.erase(0,1);
		p[i+n+1]=stoi(z)+n;
		if(s[0]=='R')p[i+n+1]-=n;
	}
	for(int i=0;i<q;i++){
		char c; cin>>c;
		if(c=='w'){
			string sa, sb;
			cin>>sa>>sb;
			string z=sa;
			z.erase(0,1);
			int a=stoi(z);
			if(sa[0]=='B')a+=n;
			z=sb; z.erase(0,1);
			int b=stoi(z);
			if(sb[0]=='B')b+=n;
			ll cnt=0;
			while(a!=1&&a!=n+1&&b!=1&&b!=n+1&&cnt<n+m+10){
				a=p[a];
				b=p[b];
				cnt++;
			}
			if((a==1&&b==n+1)||(a==n+1&&b==1))cout<<"TIE "<<cnt<<endl;
			else if(a==1||b==1)cout<<"RED "<<cnt<<endl;
			else if(a==n+1||b==n+1)cout<<"BLUE "<<cnt<<endl;
			else cout<<"NONE"<<endl;
		}else{
			string sa, sb;
			cin>>sa>>sb;
			string z=sa;
			z.erase(0,1);
			int a=stoi(z);
			if(sa[0]=='B')a+=n;
			z=sb; z.erase(0,1);
			int b=stoi(z);
			if(sb[0]=='B')b+=n;
			p[a]=b;
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

