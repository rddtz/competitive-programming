#include <bits/stdc++.h>
#define ll long long int

#define MAX 200001

using namespace std;

int main(){

  ios::sync_with_stdio(false);

  int n,m;
  ll k;
  int results = 0;

  cin >> n >> m >> k;

  ll aps[MAX] = {0};
  ll clients[MAX] = {0};

  for(int i = 0; i < n; i++){
    cin >> clients[i];
  }
  for(int i = 0; i < m; i++){
    cin >> aps[i];
  }

  sort(aps, &aps[m]);
  sort(clients, &clients[n]);

  int j = 0;
  int starter = 0;
  bool achou = false;

  for(int i = 0; i < n && j < m; i++){

    j = starter;

    achou = false;
    
    while(aps[j] <= clients[i] + k && j < m && !achou){
      starter = j;
      if(aps[j] <= clients[i] + k && aps[j] >= clients[i] - k){
	results++;
	starter = j+1;
	achou = true;
      }
      j++;
    }
  }

  cout << results << '\n';
  
  return 0;
}
