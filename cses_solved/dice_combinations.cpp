#include <bits/stdc++.h>
#include <chrono>
#define ll long long int

using namespace std;
using namespace std::chrono;

ll mod = 1e9 + 7;
ll dp[1000001] = {0};
//ll dpf[1000001] = {0};

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
  //dpf[0] = 1;

  //auto start_s = high_resolution_clock::now();
  //dp_for(n);
  //cout << dpf[n] << '\n';
  //auto end_ns = high_resolution_clock::now();
  //auto duration_sync = duration_cast<microseconds>(end_ns - start_s);
  //cout << "Runtime of the for loop resolution: " << duration_sync.count() << " ms\n";

  //start_s = high_resolution_clock::now();
  cout << dp_rec(n) << '\n';
  //end_ns = high_resolution_clock::now();
  //duration_sync = duration_cast<microseconds>(end_ns - start_s);
  //cout << "Runtime of the recursive resolution: " << duration_sync.count() << " ms\n"; 
  
  return 0;
}
