#include <bits/stdc++.h>
#define ll long long int

using namespace std;

#define MAX 10001

int elements[MAX] = {0};

int main(){

  ios::sync_with_stdio(false);

  int cases = 0;
  int n = 0, a = 0, r = 0;
  cin >> cases;

  for(int i = 0; i < cases; i++){
    int elements[MAX] = {0};
    cin >> n;
    for(int j = 0; j < n; j++){
      cin >> a;
      elements[a]++;
    }
    r = 0;
    int par = 0;
    for(int j = 0; j < MAX; j++){
      if(elements[j] != 0){

	if(elements[j] % 2 == 1){
	  r++;
	} else {
	  par++;
	}

      }
    }
    cout << r + par - (par % 2) << "\n";
  }

  return 0;
}
