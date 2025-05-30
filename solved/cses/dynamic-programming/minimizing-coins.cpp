#include <bits/stdc++.h>
#define ll long long int

#define MAX 1000001

using namespace std;

int dp[MAX] = {0};
int coins[MAX] = {0};

int dpf(int v, int size){

  if(v < 0){
    return MAX;
  }

  if(v == 0){
    return 0;
  }
  
  if(dp[v]){
    return dp[v];
  }

  int menor = MAX + 1;
  int act = 0;
  for(int i = 0; i < size; i++){

    act = 1 + dpf(v - coins[i], size);
    if(act <= menor){
      menor = act;
    }
    
  }

  dp[v] = menor;
  return dp[v];

  
}

int main(){

  ios::sync_with_stdio(false);

  int n, sum;

  cin >> n >> sum;

  for(int i = 0; i < n; i++){
    cin >> coins[i];
  }

  int r = dpf(sum, n);

  if(r >= MAX){
    cout << -1 << '\n';
  } else {
    cout << r << '\n';
  }

  
  return 0;
}
