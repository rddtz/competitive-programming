// https://cses.fi/problemset/task/1633
#include <bits/stdc++.h>
#define ll long long int

using namespace std;
using namespace std::chrono;

ll mod = 1e9 + 7;
ll dp[1000001] = {0};

ll dp_rec(int n){

  if(n == 0){
    return 1;
  }
  if(dp[n]){
    return dp[n];
  }

  for(int i = 1; i < 7 && i <= n; i++){
    dp[n] = (dp[n] + dp_rec(n-i)) % mod;
  }

  return dp[n];
}

void dp_for(int n){
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= 6 && j <= i; j++){
      dp[i] = (dp[i] + (dp[i-j])) % mod;
    }
  }
}

int main(){
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  dp[0] = 1;

  cout << dp_rec(n) << '\n';

  return 0;
}
