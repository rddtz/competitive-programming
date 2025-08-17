#include <bits/stdc++.h>
#define ll long long int
#define MAX 100001
using namespace std;

int d[MAX] = {0};
int v[MAX] = {0};
int p[MAX] = {0};
vector<vector<pair<int, int>>> g(MAX);

int main(){

  ios::sync_with_stdio(false);

  int m, n;

  cin >> n >> m;

  int a, b, w;

   for(int wtf = 1; wtf <= m; wtf++){
     cin >> a >> b >> w;
     g[a].push_back({b, w});
     g[b].push_back({a, w});
   }

   for (int i = 1; i <= n; ++i) {
    d[i] = INT_MAX;
    p[i] = -1;
   }

  // for(int i = 1; i <= n; i ++){
  //   cout << i << " = ";
  //   for(auto x : g[i]){
  //     cout << "{" << x.first << ", " << x.second << "} ";
  //   }
  //   cout << "\n";
  // }

  priority_queue<pair<int, int>> pq;

  d[1] = 0;
  pq.push({-d[1], 1});

  pair<int, int> atual;
  while(!pq.empty()){

    atual = pq.top();
    pq.pop();

    int index = atual.second;
    v[index] = 1;

    if(index == n) break;

    for(auto x : g[index]){
      if(!v[x.first]){
	d[x.first] = min(d[x.first], d[index] + x.second);
	if(d[x.first] == d[index] + x.second){
	  p[x.first] = index;
	}
	pq.push({-d[x.first], x.first});
      }
    }
  }

  // for(int i = 1; i <= n; i++){
  //    cout << "d[" << i << "] = " << d[i] << "\n";
  // }

  if(d[n] == INT_MAX){
    cout << "-1";
  } else {

    int h = n;
    stack<int> r;
    while(p[h] != -1){
      r.push(h);
      h = p[h];
    }
    r.push(h);
    while(!r.empty()){
      cout << r.top() << " ";
      r.pop();
    }

  }


  return 0;
}
