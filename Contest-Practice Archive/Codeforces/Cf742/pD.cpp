#include<bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

const int N = 1e6 + 3, Mod = 1e9 + 7;

void solve(){
	ll a,b;
	cin>>a>>b;
	while(b--){
		if(b==0){
			cout<<a;
			break;
		}
		ll i=1;
		while(to_string(i).size()<=to_string(a).size())i*=10;
		i/=10;
		while(a-i<b)i/=10;
		cout<<i<<" ";
		a-=i;
	}
	cout<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
