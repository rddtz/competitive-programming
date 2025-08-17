#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){

  ios::sync_with_stdio(false);

  ll p;
  cin >> p;

  ll vida = 0;

  ll aux = 0;
  ll tomadas = 0;

  priority_queue<ll> pq;
  for(ll i = 0; i < p; i++){

    cin >> aux;

    // cout << vida << " S2\n";
    if(aux >= 0){ // Se é positivo, toma sem reclamar
      tomadas++;
      vida += aux;
    } else { // Se é negativa
      if(vida + aux >= 0){ // Se eu não morro ao tomar, tomo
	pq.push(-aux); // adding - (-v) to be on top
	vida += aux;
      } else { // se eu morrer ao tomar
	//	cout << aux << "\n";
	if(!pq.empty() && -aux <= pq.top()){ // vejo se posso "destomar" alguma e tomar essa
	  vida += pq.top();
	  vida += aux;
	  pq.pop();
	  pq.push(-aux);
	}
      }
    }
  }

  // while(!pq.empty()){
  //   cout << -pq.top() << " ";
  //   pq.pop();
  // }
  //  cout << "\n";
  cout << tomadas + pq.size();

  return 0;
}
