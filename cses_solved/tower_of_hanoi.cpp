#include <bits/stdc++.h>
#define ll long long

using namespace std;

void moves(int n, int from, int to){

  if(n > 0){
      int livre = 0;
      if((from == 1 && to == 3) || (to == 1 && from == 3)){
	livre = 2;
      } else
      if((from == 2 && to == 3) || (from == 3 && to == 2)){
	livre = 1;
      } else
	if((from == 1 && to == 2) || (to == 1 && from == 2)) {
	livre = 3;
      }

      moves(n-1,from,livre);
      cout << from << " " << to << '\n';
      moves(n-1,livre,to);
  }
}


int main(){

  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  cout << pow(2,n) - 1 << '\n';
  moves(n,1,3);
  

  return 0;
}
