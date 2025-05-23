#include <bits/stdc++.h>
#define ll long long int
#define MAX 1001
#define L 100

using namespace std;

int visitados[MAX] = {0};
int graph[MAX][MAX];
int emp = 0;
int langs = 0;
int e_langs = 0;


int bfs(int graph[MAX][MAX], int node){

    queue<int> fila;

    if(visitados[node]){
      return 0;
    }

    visitados[node] = 1;
    fila.push(node);

    int atual;
    int row, col;

    int type = 0; // 0 is emp, 1 is lang
    while(!fila.empty()){

	atual = fila.front();
	fila.pop();

	if(atual < 101){
	  for(int i = 1; i <= langs; i++){
	    if(graph[atual][L + i] && !visitados[L + i]){
	      fila.push(L + i);
	      visitados[L + i] = 1;
	    }
	  }
	} else {
	  for(int i = 0; i < emp; i++){
	    if(graph[atual][i] && !visitados[i]){
	      fila.push(i);
	      visitados[i] = 1;
	    }
	  }
	}
    }

    // cout << "\n";

    return 1;
}

int main(){

    ios::sync_with_stdio(false);


    int v = 0;

    int entrou = 0;

    cin >> emp;
    cin >> langs;
    for(int i = 0; i < emp; i++){
      cin >> e_langs;
      for(int j = 0; j < e_langs; j++){
	entrou = 1;
	cin >> v;
	graph[i][L + v] = 1;
	graph[L + v][i] = 1;
      }
    }


    // for(int i = 1; i <= emp; i++){
    //   for(int j = 1; j <= langs; j++){
    // 	cout << graph[i][j + L] << " ";
    //   }
    //   cout << "\n";
    // }


    int total = 0;
    for(int node = 0; node < emp; node++){
      total += bfs(graph, node);
    }

    if(entrou){
      cout << total - 1;
    } else {
      cout << total;
    }

    return 0;
}
