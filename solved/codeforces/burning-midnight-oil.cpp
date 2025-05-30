#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n, k;

int count_r(ll v){

  ll aux = v;

  ll t = 0;

  while(aux != 0){
    t += aux;
    aux = aux / k;
  }

  return (t >= n);
}

ll lower_bs(ll r, ll l, ll menor){


  ll aux = menor;

  while (l <= r){
      ll mid = (l+r)/2;

      if(count_r(mid)){
	menor = mid;
	r = mid - 1;
      } else {
	l = mid + 1;
      }
  }

  return menor;

}

int main(){

  ios::sync_with_stdio(false);

  cin >> n >> k;
  cout << lower_bs(n, 0, n);

  return 0;
}
