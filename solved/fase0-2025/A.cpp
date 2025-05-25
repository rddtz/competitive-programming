#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){
  
  ios::sync_with_stdio(false);  

  int c, g;
  cin >> c >> g;
  if(c){
    cout << "vivo e morto";
  } else {
    if(g){
      cout << "vivo";
    } else {
      cout << "morto";
    }
  }
  
  
  return 0;
}
