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
	int n; cin>>n;
	vl pos;
	vl neg;
	bool zero = 0;
	vl arr;
	for(int i=0; i<n; i++){
		int x; cin>>x;
		if (x>0) pos.pb(x);
		else if (x<0)neg.pb(x);
		else zero = 1;
		if (x!=0)arr.pb(x);
	}
	if(pos.size()>2||neg.size()>2){
		cout<<"NO"<<endl;
		return;
	}
	
	if (zero)arr.pb(0);
	for(int i=0; i<arr.size(); i++){
		for(int j=i+1; j<arr.size();j++){
			for(int k=j+1; k<arr.size(); k++){
				int l;
				for(l=0; l<arr.size(); l++){
					if(arr[i]+arr[j]+arr[k]==arr[l])break;
				}
				if (l==arr.size()){
					cout<<"NO"<<endl;
					return;
				}
			}
		}
	}
	cout<<"YES"<<endl;
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
