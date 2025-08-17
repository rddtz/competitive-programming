#include <bits/stdc++.h>
#define ll long long int
#define MAX 1001

using namespace std;

priority_queue<pair<int, pair<int, int>>> orders;
vector<pair<int, int>> tables;

int mesas[MAX] = {0};

bool comp (pair<int, int> a, pair<int, int> b) {
  return a.first < b.first;
}

int main(){

  ios::sync_with_stdio(false);

  int p = 0;
  cin >> p;

  int pessoas, dinheiro;
  for(int i = 0; i < p; i++){
    cin >> pessoas >> dinheiro;
    orders.push({dinheiro, {pessoas, i+1}});
  }

  int t;
  cin >> t;

  int aux;
  for(int i = 0; i < t; i++){
    cin >> aux;
    tables.push_back({aux, i+1});
  }

  sort(tables.begin(), tables.end(), comp);

  int ps, pre, ind;
  int total = 0, tot = 0;

  queue<pair<int, int>> resp;

  while(!orders.empty()){

    pre = orders.top().first;
    ps = orders.top().second.first;
    ind = orders.top().second.second;
    orders.pop();

    for(int i = 0; i < t; i++){
      if(!mesas[i] && tables[i].first >= ps){
	mesas[i] = 1;
	total += pre;
	tot++;
	resp.push({ind, tables[i].second});
	break;
      }
    }

  }

  cout << tot << " " << total;

  while(!resp.empty()){
    cout << "\n";
    cout << resp.front().first << " " << resp.front().second;
    resp.pop();
  }

  return 0;
}
