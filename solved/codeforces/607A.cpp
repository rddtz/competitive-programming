#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000003

using namespace std;

int dp[MAX] = {0};
int t[MAX] = {0};
int b[MAX] = {0};
//vector<pair<int, int>> b;
int main(){

  ios::sync_with_stdio(false);

  int n;
  cin >> n;


  int aux = 0;
  int p = 0;
  int mp  = 0;
  int menor = INT_MAX;
  for(int i = 0; i < n; i++){
    cin >> aux >> p;
    if(aux > mp) mp = aux;
    if(aux < menor) menor = aux;
    b[aux] = p;
    t[aux] = 1;
    //  b.push_back({aux, p});
  }

  if(n == 1){
    cout << 0;
    return 0 ;
  }

  // sort(d.begin(), d.end());

  // for(auto x : b){
  //   cout << x.first << " ";
  // }

  // for(int i = 0; i <= max; i++){
  //   if(t[i]){
  //     cout << "{" << i << ", " << b[i] << "} ";
  //   }
  // }

  // cout << "\n";

  int m = 0;
  dp[menor] = 1;
  for(int i = 1; i <= mp + 1; i++){

    if(!t[i]){
      dp[i] = dp[i-1];
    } else {
      dp[i] = 1;
      if(i - b[i] >= 0){
	dp[i] += dp[i - 1 - b[i]];
      }
    }

    if(dp[i] > m){
      m = dp[i];
    }

  }

  cout << n - m;

  return 0;
}
