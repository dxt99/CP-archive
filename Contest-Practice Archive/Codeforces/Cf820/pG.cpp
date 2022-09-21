#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fs first
#define sd second
#define MAX_N 100010
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


string T, P; // T = text, P = pattern
int b[MAX_N], n, m; // b = back table, n = length of T, m = length of P

vl ps;

void kmpPreprocess() { // call this before calling kmpSearch()
ps.clear();
int i = 0, j = -1; b[0] = -1; // starting values
while (i < m) { // pre-process the pattern string P
while (j >= 0 && P[i] != P[j]) j = b[j]; // different, reset j using b
i++; j++; // if same, advance both pointers
b[i] = j; // observe i = 8, 9, 10, 11, 12, 13 with j = 0, 1, 2, 3, 4, 5

} } // in the example of P = "SEVENTY SEVEN" above
void kmpSearch() { // this is similar as kmpPreprocess(), but on string T
int i = 0, j = 0; // starting values
while (i < n) { // search through string T
while (j >= 0 && T[i] != P[j]) j = b[j]; // different, reset j using b
i++; j++; // if same, advance both pointers
if (j == m) { // a match found when j == m
ps.pb(i-j);
j = b[j]; // prepare j for the next possible match
}}}

void solve(){
	cin>>T; cin>>P;
	n = T.size();
	m = P.size();
	kmpPreprocess();
	kmpSearch();
	ll ans=0;
	ll tot=1;
	for(int i=0; i<ps.size();){
		ans++;
		ll cnt = 1;
		int j = lower_bound(ps.begin(), ps.end(), ps[i]+m)-ps.begin()-1;
		int k = lower_bound(ps.begin(), ps.end(), ps[j]+m)-ps.begin();
		for(int it=i; it<j; it++){
			if(lower_bound(ps.begin(), ps.end(), ps[it]+m)-ps.begin() == k)cnt++;
		}
		tot*=cnt;
		tot%=Mod;
		i=k;
	}
	cout<<ans<<" "<<tot<<endl;
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
