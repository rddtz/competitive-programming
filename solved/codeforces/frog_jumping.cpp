#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){

  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  ll a, b, k;
  for(int i = 0; i < n; i++){
    cin >> a >> b >> k;

    cout << (a* (k/2 + k%2)) - (b * (k/2)) << "\n";

  }

  return 0;
}
