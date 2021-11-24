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
	int arr[4];
	memset(arr,0,sizeof(arr));
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		arr[--x]++;
	}
	int temp=arr[0]-arr[2]-2*(arr[1]%2);
	cout<<arr[3]+arr[2]+arr[1]/2+max(0,(temp+3)/4)+arr[1]%2<<endl;
}
