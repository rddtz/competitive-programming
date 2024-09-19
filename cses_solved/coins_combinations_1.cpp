#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

#include <chrono>

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

  //for(int i = 0; i <= v; i++){
  // cout << "Indice " << i << " tem " << dpb[i] << '\n';
  //}

  return dpb[v];

}

ll calc(int s, int size){

  if(s == 0){
    return 1;
  }
  
  if(dp[s] != 0){
    return dp[s];
  }

  ll resp = 0;
  for(int i = 0; i < size; i++){
    if(coins[i] <= s){
      resp += (calc(s-coins[i], size) % MOD);
    }
  }

  dp[s] = resp;
  return resp;
  
}

int main(){

  ios::sync_with_stdio(false);

  int n, sum;
  cin >> n >> sum;

  for(int i = 0; i < n; i++){
    cin >> coins[i];
  }

  //auto start_s = high_resolution_clock::now();
  //cout << calc(sum, n) << '\n';
  //auto end_ns = high_resolution_clock::now();
  //auto duration_sync = duration_cast<microseconds>(end_ns - start_s);
  //cout << "Recursao: " << duration_sync.count() << " ms\n";
  
  //start_s = high_resolution_clock::now();
  cout << bt(sum, n) << '\n';
  //end_ns = high_resolution_clock::now();
  //duration_sync = duration_cast<microseconds>(end_ns - start_s);
  //cout << "Loop: " << duration_sync.count() << " ms\n";
  
  return 0;
}
