// https://cses.fi/problemset/task/1646
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){

  ios::sync_with_stdio(false);

  int n, q;
  int a, b;
  cin >> n;
  cin >> q;

  ll sums[n+1] = {0};

  ll aux;
  ll sum = 0;
  for(int i = 1; i <= n; i++){
    cin >> aux;
    sum += aux;
    sums[i] = sum;
  }

  for(int i = 0; i < q; i++){

    cin >> a >> b;
    cout << sums[b] - sums[a-1] << '\n';
  }
  return 0;
}
