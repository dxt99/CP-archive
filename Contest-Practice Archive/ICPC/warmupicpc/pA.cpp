#include<bits/stdc++.h>
using namespace std;

const int N=1e6+3;

double maxi,mini,sum;

int main(){
	mini=INT_MAX;
	int n; cin>>n;
	while(n--){
		double a,b;
		cin>>a>>b;
		a/=b;
		maxi=max(maxi,a);
		mini=min(mini,a);
		sum+=a;
	}
	printf("%.12f %.12f %.12f\n",mini,maxi,sum);
}
