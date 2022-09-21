#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fs first
#define sd second
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vll;

const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN=1e3+3;

vl arr(4);
char op[3];
ll ans=(ll)1e18;

void brute (vector<long long> v, int cur) {
	if (cur == 3)
		ans = min (ans, v[0]);
	else
		for (size_t i=0; i<v.size(); ++i)
			for (size_t j=0; j<i; ++j) {
				vector<long long> to = v;
				long long num = (op[cur]=='+') ? v[i]+v[j] : v[i]*v[j];
				to[j] = num;
				to.erase (to.begin() + i);
				brute (to, cur+1);
			}
}

void solve(){
	for(int i=0;i<4;i++)cin>>arr[i];
	for(int i=0;i<3;i++)cin>>op[i];
	brute(arr,0);
	cout<<ans<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t;
	t=1;
	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
