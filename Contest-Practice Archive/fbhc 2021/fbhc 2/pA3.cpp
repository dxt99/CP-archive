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
	
	//file
	ifstream inn;
	string filename;
	cin>>filename;
	inn.open(filename);
	int t;
	inn>>t;
	ofstream out;
	out.open("out.txt");
	
	for(int time=0;time<t;time++){
		int n;
		inn>>n;
		string s;
		inn>>s;
		ll i=0;
		ll ans=0;
		ll prev=0;
		while((s[i]=='F')&&i<n)i++;
		prev=i;
		for(;i<n;i++){
			if(s[i]==(s[prev]^'O'^'F')){
				ans+=((prev+1)*(n-i));
				prev=i;
				ans=ans%Mod;
			}else if(s[i]!='F'){
				prev=i;
			}
			cout<<ans<<endl;
		}
		out<<"Case #"<<time+1<<": ";
		out<<ans<<endl;
	}
	inn.close();
	out.close();
}
