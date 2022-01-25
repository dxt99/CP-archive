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
	string s; cin>>s;
	s="00"+s;
	for(int i=0;i<s.size();i++){
		for(int j=i+1;j<s.size();j++){
			for(int k=j+1;k<s.size();k++){
				int a=s[i]-'0';
				int b=s[j]-'0';
				int c=s[k]-'0';
				if((100*a+10*b+c)%8==0){
					cout<<"YES"<<endl;
					if(a)cout<<a;
					if(b)cout<<b;
					cout<<c<<endl;
					return;
				}
			}
		}
	}
	cout<<"NO"<<endl;
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
