#include<bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

const int N = 1e6 + 3, Mod = 1e9 + 7;

 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int n;
	cin>>n;
	int temp=n;
	char ans='a';
	while(n--){
		cout<<char(ans+(n%3));
	}
	cout<<endl;
}
