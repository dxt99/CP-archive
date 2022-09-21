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

ll findXorSum(ll* arr, int n)
{
    // variable to store
    // the final sum
    ll sum = 0;
 
    // multiplier
    ll mul = 1;
 
    for (ll i = 0; i < 26; i++) {
 
        // variable to store number of
        // sub-arrays with odd number of elements
        // with ith bits starting from the first
        // element to the end of the array
        ll c_odd = 0;
 
        // variable to check the status
        // of the odd-even count while
        // calculating c_odd
        bool odd = 0;
 
        // loop to calculate initial
        // value of c_odd
        for (ll j = 0; j < n; j++) {
            if ((arr[j] & (1 << i)) > 0)
                odd = (!odd);
            if (odd)
                c_odd++;
        }
 
        // loop to iterate through
        // all the elements of the
        // array and update sum
        for (ll j = 0; j < n; j++) {
            sum += (mul * c_odd);
 
            if ((arr[j] & (1 << i)) > 0)
                c_odd = (n - j - c_odd);
        }
 
        // updating the multiplier
        mul *= 2;
    }
 
    // returning the sum
    return sum;
}

vl bin(26);

void solve(){
	ll n; cin>>n;
	ll arr[n];
	for(int i=0; i<n ;i++)cin>>arr[i];
	for(int i=0; i<25; i++){
		ll cnt=0;
		for(int j=0; j<n; j++){
			if((arr[j]&(1<<i)) > 0)cnt++;
		}
		bin[i]=cnt;
	}
	ll maxi = -1;
	ll maxidx = 0;
	ll maxval = 0;
	for(int i=0; i<n; i++){
		ll val = 0;
		for(int j=0; j<25; j++){
			ll cur = 0;
			if((arr[i]&(1<<j)) > 0){
				cur++;
			}
			cur = bin[j]-cur;
			if(cur<0)cur+=2;
			//cout<<cur<<endl;
			if(cur==0){
				val += (1<<j);
			}
		}
		ll temp = arr[i];
		arr[i]=val;
		//cout<<val<<endl;
		ll s = findXorSum(arr, n);
		if (s>maxi){
			maxi = s;
			maxidx = i+1;
			maxval=val;
		}
		arr[i]=temp;
	}
	cout<<maxidx<<" "<<maxval<<endl;
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
}
