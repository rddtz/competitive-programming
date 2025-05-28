#include <bits/stdc++.h>
#define ll long long int
#define MAX 300001

using namespace std;

vector<vector<pair<int,int>>> c(MAX);
int visitados[MAX];
int p[MAX];
set<int> resp;

int main(){

  ios::sync_with_stdio(false);

  int n, k, d;
  cin >> n >> k >> d;

  int aux;
  queue<pair<int, int>> pol;
  for(int i = 0; i < k; i++){
    cin >> aux;
    p[aux] = 1;
    //    visitados[aux] = 1;
    pol.push({aux, -1});
  }

  int c1 = 0, c2 = 0;
  for(int i = 0; i < n - 1; i++){
    cin >> c1 >> c2;
    c[c2].push_back({c1, i+1});
    c[c1].push_back({c2, i+1});
  }

  while(!pol.empty()){

    int atual = pol.front().first;
    int last = pol.front().second;
    pol.pop();
    cout << "Here " << atual << " from " << last << "\n";

    if(visitados[atual]){
      continue;
    }
    visitados[atual] = 1;

    for(int i = 0; i < c[atual].size(); i++){
      //	visitados[c[atual][i].first] = 1;
      if(c[atual][i].first != last){
	if(!visitados[c[atual][i].first]){
	  pol.push({c[atual][i].first, atual});
	} else {
	resp.insert(c[atual][i].second);
	}
      }
    }
  }

  cout << resp.size() << "\n";
  for(auto r: resp){
    cout << r << " ";
  }


  return 0;
}
