#include <cstdio>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

int Mod=1e9+7;
const int big=1e6+3;
int N = 5, V, coinValue[103], memo[103][big];
// N and coinValue are fixed for this problem, max V is 7489

int ways(int type, int value) {
  if (value == 0)              return 1;
  if (value < 0 || type == N)  return 0;
  if (memo[type][value] != -1) return memo[type][value];
  return memo[type][value] = (ways(type + 1, value)%Mod + ways(type, value - coinValue[type])%Mod)%Mod;
}

int main() {
  memset(memo, -1, sizeof memo); // we only need to initialize this once
  cin>>N>>V;
  for(int i=0;i<N;i++)cin>>coinValue[i];
  cout<<ways(0,V)<<endl;
  return 0;
}
