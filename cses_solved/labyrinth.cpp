#include <bits/stdc++.h>
#define ll long long int
#define MAX 1001

using namespace std;

void print_path(char graph[MAX][MAX], char visitados[MAX][MAX], int row, int col){

    char path[MAX*MAX] = {0};
    int t = 0;
    
    while(graph[row][col] != 'A'){

	path[t] = visitados[row][col];
	t++;
	
	if(visitados[row][col] == 'U'){
	    row++;
	} else
	if(visitados[row][col] == 'D'){
	    row--;
	} else
	if(visitados[row][col] == 'L'){
	    col++;
	} else
	if(visitados[row][col] == 'R'){
	    col--;
	}
    }

    cout << t << '\n';
    for(int i = t-1; i >= 0; i--){
	cout << path[i];
    }
    cout << '\n';
    
}

void bfs(char graph[MAX][MAX], int l, int c, int L, int C){

    //          l   c
    queue<pair<int,int>> fila;
    fila.push(make_pair(l,c));

    char visitados[MAX][MAX] = {0};
    
    visitados[l][c] = 'A';

    pair<int, int> atual;
    int row, col;
  
    while(!fila.empty()){
    
	atual = fila.front();
	fila.pop();

	row = atual.first;
	col = atual.second;

	if(graph[row][col] == 'B'){
	    cout << "YES\n";
	    print_path(graph, visitados, row, col);
	    return;
	}
  
	if(col+1 < C && !visitados[row][col+1] && graph[row][col+1] != '#'){
	    fila.push(make_pair(row,col+1));
	    visitados[row][col+1] = 'R';
	}

	if(col-1 >= 0 && !visitados[row][col-1] && graph[row][col-1] != '#'){
	    fila.push(make_pair(row,col-1));      
	    visitados[row][col-1] = 'L';
	}

	if(row+1 < L && !visitados[row+1][col] && graph[row+1][col] != '#'){
	    fila.push(make_pair(row+1,col));     
	    visitados[row+1][col] = 'D';
	}

	if(row-1 >= 0 && !visitados[row-1][col] && graph[row-1][col] != '#'){
	    fila.push(make_pair(row-1,col));      
	    visitados[row-1][col] = 'U';
	}
    }

    cout << "NO\n";
    return;
 
}

int main(){
  
    ios::sync_with_stdio(false);  
    
    int l = 0, c = 0;
  
    char graph[MAX][MAX];
    int x = 0, y = 0;

    cin >> l >> c;
    int i, j;
    for(i = 0; i < l; i++){
	for(j = 0; j < c; j++){
	    cin >> graph[i][j];
	    if(graph[i][j] == 'A'){
	        x = i;
		y = j;
	    }
	}
    }
    
    bfs(graph, x, y, l, c);
  
    return 0;
}
