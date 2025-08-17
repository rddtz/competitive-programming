// https://cses.fi/problemset/task/1621
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){

  set<ll> ms;

  int k; cin >> k;
  ll a;

  for(int i = 0; i < k; i++){
    cin >> a;
    ms.insert(a);
  }

  cout << ms.size() << "\n";

}
