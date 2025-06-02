#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){

  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  char d[n][m];

  int t[n][m] = {0};

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> d[i][j];
      t[i][j] = 0;
    }
  }


  int to = 0;
  int x, y, r;

  vector<pair<pair<int,int>, int>> resp;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(d[i][j] == '*'){
	x = i + 1;
	y = j + 1;
	r = 0;
	int valido = 1;
	while(valido){
	  valido = 0;
	  if(i + r + 1 < n && j + r + 1 < m && i - r - 1 >=0 && j - r - 1 >=0 &&
	     d[i + r + 1][j] == '*' && d[i - r - 1][j] == '*' &&
	     d[i][j + r + 1] == '*' && d[i][j - r - 1] == '*'){

	    r++;
	    valido = 1;
	    t[i][j] = 1;
	    t[i + r    ][j] = 1;
	    t[i - r][j] = 1;
	    t[i][j + r] = 1;
	    t[i][j - r] = 1;
	  }

	}
	if(r > 0){
	  to++;
	  resp.push_back({{x, y}, r});
	}
      }
    }
  }

  int c = 1;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      // cout << t[i][j];
      if(d[i][j] == '*' && !t[i][j]){
	c = 0;
	break;
      }
    }
    // cout << "\n";
    if(c == 0) break;
  }

  if(c){
    cout << to << "\n";
    for(auto x : resp){
      cout << x.first.first << " " << x.first.second << " " << x.second << "\n";
    }
  } else {
    cout << -1;
  }


  return 0;
}
