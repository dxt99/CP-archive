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

// 1. + -> x, - -> /
// 2. x -> +, : -> -
void solve(){
	string s; cin>>s;
	vl nums;
	vector<char> ops;
	// negative sign at first char
	int st = 1;
	if(s[0] == ':'){
		st = 2;
		nums.pb(-1 * (s[1] - '0'));
	}else{
		nums.pb(s[0] - '0');
	}
	// parse
	for(int i=0; i+st<s.size(); i++){
		if(i%2)nums.pb(s[i+st] - '0');
		else ops.pb(s[i+st]);
	}
	// multiplication and division
	vl nums2;
	vector<char> ops2;
	for(int i=0; i<ops.size(); i++){
		if(ops[i] == '+')nums[i+1] *= nums[i];
		else if(ops[i] == '-')nums[i+1] = nums[i]/nums[i+1];
		else{
			nums2.pb(nums[i]);
			ops2.pb(ops[i]);
		}
	}
	nums2.pb(nums[nums.size()-1]);
	// addition and substraction
	ll res = nums2[0];
	for(int i=0; i<ops2.size(); i++){
		if(ops2[i] == 'x')res += nums2[i+1];
		if(ops2[i] == ':')res -= nums2[i+1];
	}
	cout<<res<<endl;
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
