#include <bits/stdc++.h>
#define ll long long int
#define MAX 1001

using namespace std;

void flood_fill(char graph[MAX][MAX], int l, int c){

  graph[l][c] = '#';
  
  if(graph[l][c+1] == '.'){
    flood_fill(graph, l, c+1);
  }
  if(graph[l+1][c] == '.'){
    flood_fill(graph, l+1, c);
  }
  if(graph[l-1][c] == '.'){
    flood_fill(graph, l-1, c);
  }
  if(graph[l][c-1] == '.'){
    flood_fill(graph, l, c-1);
  }
 
}

int main(){

  ios::sync_with_stdio(false);  

  int l, c;
  int salas = 0;

  char graph[MAX][MAX];
  
  cin >> l >> c;
  
  for(int i = 0; i < l; i++){
    for(int j = 0; j < c; j++){
      cin >> graph[i][j];
    }
  }

  for(int i = 0; i < l; i++){
    for(int j = 0; j < c; j++){
      if(graph[i][j] == '.'){
	salas++;
	flood_fill(graph, i, j);
      }
    }
  }

  cout << salas << '\n';
  
  return 0;
}
