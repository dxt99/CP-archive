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
	
	//filing
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
		int i=0;
		int ans=0;
		char prev='F';
		while(s[i]=='F'&&i<n)i++;
		prev=s[i];
		while(i<n){
			if(s[i]!='F'&&s[i]!=prev){
				ans++;
				prev=s[i];
			}
			i++;
		}
		out<<"Case #"<<time+1<<": ";
		out<<ans<<endl;
	}
	inn.close();
	out.close();
}
