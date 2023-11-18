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

const int N = 1e6 + 3, Mod = 104206969;
const int maxN=1e3+3;
const ll y=180758;
const ll leap=229;

bool isLeapYear(ll z){
	if (z%400 == 0)return 1;
	if (z%100 == 0)return 0;
	return z%4 == 0;
}


void solve(){
	ll a,b; cin>>a>>b;
	ll c = a;
	ll d = b+1;
	ll add = 0;
	ll red = 0;
	while(c%400 != 0){
		if(isLeapYear(c))add += 1;
		c += 1;
	}
	while(d%400 != 0){
		if(isLeapYear(d))red += 1;
		d += 1;
	}
	ll dif = d-c;
	ll num = (dif/4) - (dif/100) + (dif/400);
	num = num % Mod;
	num = num + add - red;
	num = num % Mod;
	num = (num * leap) % Mod;
	dif = b - a + 1;
	dif = dif % Mod;
	dif = (dif * y) % Mod;
	num = (num + dif) % Mod;
	cout<<num<<endl;
	return;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
	//cin>>t;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
	return 0;
}
