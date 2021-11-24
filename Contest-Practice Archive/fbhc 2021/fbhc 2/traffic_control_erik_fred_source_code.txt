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
		out<<"Case #"<<time+1<<": ";
		int n,m,a,b;
		inn>>n>>m>>a>>b;
		if(n+m-1>min(a,b))out<<"Impossible"<<endl;
		else{
			out<<"Possible"<<endl;
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					if(i==n-1&&j==0)out<<b-n-m+2<<" ";
					else if(i==n-1&&j==m-1)out<<a-n-m+2<<" ";
					else out<<"1 ";
				}
				out<<endl;
			}
		}
	}
}
