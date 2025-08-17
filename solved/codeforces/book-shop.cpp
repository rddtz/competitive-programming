#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000

using namespace std;



int books[MAX] = {0};

// precos indexam paginas
int pages[MAX] = {0};

int dp[MAX] = {0};

int main(){

  ios::sync_with_stdio(false);

  ll n, dinheiros;
  cin >> n >> dinheiros;


  for(int i = 0; i < n; i++){
    cin >> books[i];
  }

  int aux;
  for(int i = 0; i < n; i++){
    cin >> aux;
    if(pages[books[i]] < aux){
      pages[books[i]] = aux;
    }
  }

  dp[0] = 0;
  for(int i = 1; i <= sum; i++){
    dp[i] = max(dp[i-1], pages[i]);
  }

  return 0;
}
