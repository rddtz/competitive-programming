#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000001

using namespace std;


int m[MAX] = {0};

int main(){

  ios::sync_with_stdio(false);

  int n, q, d;

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> q;
    m[i] = q;
  }

  sort(m, m + n);

  //  for(int i = 0; i < n; i++){
  // cout << m[i] << " ";
  //  }
  cin >> d;
  for(int i = 0; i < d; i++){
     cin >> q;
     cout << lower_bound(m, m+n, q + 1) - m << "\n";
  }

  return 0;
}
