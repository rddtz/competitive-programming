// https://cses.fi/problemset/task/1754
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){

  ios::sync_with_stdio(false);

  ll a, b;
  int t;
  int ah, bh;
  cin >> t;

  for(int i = 0; i < t; i++){

    cin >> a >> b;

    ah = a % 3;
    bh = b % 3;

    if(max(a-b,b-a) > min(a,b)){
      cout << "NO\n";
    }
    else if((a == 0 && b == 0) || (ah == 1 && bh == 2) || (bh == 1 && ah == 2) || (ah == 0 && bh == 0 && a != 0 && b != 0)){
      cout << "YES\n";
   } else {
     cout << "NO\n";
   }
  }

  return 0;
}
