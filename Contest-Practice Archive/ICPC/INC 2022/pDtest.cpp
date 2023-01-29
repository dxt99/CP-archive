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

struct tri{
	int a;
	int b;
	int c;
};
bool operator < (tri a, tri b) {
	if(a.a<b.a)return 1;
	if(a.a>b.a)return 0;
	if(a.b<b.b)return 1;
	if(a.b<b.b)return 0;
	if(a.c<b.c)return 1;
	return 0;
	
} //merging two datas (ans)

void solve(){
	set<tri> s;
	int arr[5] = {0,1,0,0,1};
	for(int i=0; i<6; i++){
		for(int j=0; j<3; j++){
			s.insert(tri{i,j,0});
			s.insert(tri{j,i,0});
			s.insert(tri{0,j,i});
			s.insert(tri{0,i,j});
			s.insert(tri{i,0,j});
			s.insert(tri{j,0,i});
		}
	}
	cout<<s.size()<<endl;
	ll cnt=0;
	for(auto t: s){
		if(t.a!=t.b && t.a!=t.c && t.b!=t.c){
			cnt++;
			cout<<"! ";
		}
		cout<<t.a<<" "<<t.b<<" "<<t.c<<endl;
	}
	cout<<cnt<<endl;
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
