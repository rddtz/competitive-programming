#include <bits/stdc++.h>
#define ll long long
#define M 8

using namespace std;

char board[M][M] = {'\0'};

void print(char map[M][M]){

  for(int i = 0; i < M; i++){
    for(int j = 0; j < M; j++){
      cout << map[i][j];
    }
    cout << '\n';
  }

  
}

int count(char map[M][M], int c){


  int r = 0;
  if(c == M - 1){
    for(int i = 0; i < M; i++){
      if(map[i][c] != '*') r++;
    }
    return r;
  }

  char new_map[M][M] = {'\0'};
  for(int l = 0; l < M; l++){

    if(map[l][c] != '*'){
      
      for(int i = 0; i < M; i++){
	for(int j = 0; j < M; j++){
	  if(i == l || j == c){
	    new_map[i][j] = '*';
	  } else {
	    new_map[i][j] = map[i][j];
	  }
	}
      }
  
      for(int i = 1; i < M - l; i++){
	new_map[l + i][c + i] = '*';
      }

      for(int i = l; i >= 0; i--){
	new_map[l - i][c + i] = '*';
      }
      
      r += count(new_map, c+1);
      
    }
  }
    
  return r;
  
}

int main(){

  ios::sync_with_stdio(false);
  
  for(int i = 0; i < M; i++){
    for(int j = 0; j < M; j++){
      cin >> board[i][j];
    }
  }

  cout << count(board, 0) << '\n';
  
  return 0;
}
