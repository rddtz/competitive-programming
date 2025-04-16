#include <bits/stdc++.h>
#define ll long long int

#define MAX 200001

using namespace std;

int dp[MAX] = {0};
vector<int> adj[MAX];

int c(int n){

  if(dp[n]){
    return dp[n];
  }

  int t = adj[n].size();
  for(int j = 0; (unsigned)j < adj[n].size(); j++){
    t += c(adj[n][j]);
  }

  dp[n] = t;
  return dp[n];

}

int main(){

  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int a;
  for(int i = 2; i <= n; i++){
    cin >> a;
    adj[a].push_back(i);
  }

  for(int i = 1; i <= n; i++){
    cout << c(i) << " ";
  }

  cout << '\n';

  return 0;
}
