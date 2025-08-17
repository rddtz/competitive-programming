// https://cses.fi/problemset/task/1635
#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007


using namespace std;
using namespace std::chrono;

int coins[1000001] = {0};

ll dp[1000001] = {0};

ll dpb[1000001] = {0};

ll bt(int v, int size){

  dpb[0] = 1;

  for(int i = 1; i <= v; i++){
    for(int s = 0; s < size; s++){
      if(coins[s] <= i){
	dpb[i] = (dpb[i] + dpb[i-coins[s]]) % MOD;
      }
    }
  }

  return dpb[v];
}

int main(){

  ios::sync_with_stdio(false);

  int n, sum;
  cin >> n >> sum;

  for(int i = 0; i < n; i++){
    cin >> coins[i];
  }

  cout << bt(sum, n) << '\n';

  return 0;
}
