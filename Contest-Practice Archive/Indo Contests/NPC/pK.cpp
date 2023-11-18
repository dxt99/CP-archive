#include<iostream>
#include<vector>
#define pb push_back
using namespace std;
typedef long long ll;
const ll N = 2000000;
vector<ll> primes; // 2, 3 ,5
vector<ll> sumPrimes; //0, 2, 2+3
bool isNotPrime[N];

void preprocess(){
    sumPrimes.pb(0);
    ll l = 1;
    for(int i=2; i<N; i++){
        if (isNotPrime[i]) continue;
        for(int j=i*i; j<N; j+=i) isNotPrime[j] = true;
        primes.pb(i);
        sumPrimes.pb(i);
        sumPrimes[l] += sumPrimes[l-1];
        l += 1;
    }
}

void solve(){
    ll n; cin>>n;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    preprocess();
    cout<<primes.size()<<endl;
    int t; cin>>t;
    for(int i=0; i<t; i++){solve();}
}