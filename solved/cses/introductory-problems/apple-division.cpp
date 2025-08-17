// https://cses.fi/problemset/task/1623
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll l[20] = {};

ll fm(int index, int size, ll a, ll b){

  if(index >= size){
      if(a >= b){
      return a - b;
    }
    return b - a;
  }

  ll ga = fm(index + 1, size, a + l[index], b);
  ll gb = fm(index + 1, size, a, b + l[index]);

  return min(ga, gb);

}

int main(){

  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> l[i];
  }

  cout << fm(0, n, 0, 0) << '\n';

  return 0;
}
