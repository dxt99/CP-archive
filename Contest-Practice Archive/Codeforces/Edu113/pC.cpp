#include<bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

const int N = 1e6 + 3, Mod = 998244353;

long long fact[N], invf[N], inv[N];
long long modpow(long long x, long long y) {
    long long ret = 1;
    while (y > 0) {
        if (y & 1) ret = (ret * x) % Mod;
        y >>= 1;
        x = (x * x) % Mod;
    }
    return ret;
}

long long C(int a, int b) {
    if (a < b) return 0;
    long long ret = (fact[a] * invf[a - b]) % Mod;
    ret = (ret * invf[b]) % Mod;
    return ret;
}

void preprocess() {
    fact[0] = invf[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % Mod;
        invf[i] = modpow(fact[i], Mod - 2);
        inv[i]=modpow(i,Mod-2);
    }
}

void solve(){
	int n;
	cin>>n;
	int arr[n];
	int maxi=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		maxi=max(maxi,arr[i]);
	}
	int mx=0,mx1=0;
	for(int i=0;i<n;i++){
		if(arr[i]==maxi)mx++;
		if(arr[i]==maxi-1)mx1++;
	}
	if(mx>1)cout<<fact[n]<<endl;
	else cout<<(((fact[n]*mx1)%Mod)*inv[mx1+1])%Mod<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	preprocess();
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
