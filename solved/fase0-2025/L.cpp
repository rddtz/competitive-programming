#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){
  
  ios::sync_with_stdio(false);  

  ll a;
  cin >> a;
  a = a * 8000000;
  cout << ceil(log2(a));
  
  return 0;
}
