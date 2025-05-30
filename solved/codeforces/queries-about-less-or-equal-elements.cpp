#include <bits/stdc++.h>
#define ll long long int
#define MAX 200001

using namespace std;

ll a[MAX];
ll b[MAX];


int main(){

  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;


  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  for(int i = 0; i < m; i++){
    cin >> b[i];
  }

  sort(a, a + n);
  //  sort(b, b + m);

  for(int i = 0; i < m; i++){
    int r = lower_bound(a, a+n, b[i] + 1) - a;
    // while(b[i] == a[r]){
    //   r++;
    // }
    cout << r << " ";
  }



  return 0;
}
