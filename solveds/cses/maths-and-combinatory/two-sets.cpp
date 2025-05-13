#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){

  ll n; cin >> n;
  
  if((n*(n+1))/2 % 2 || n <= 2){ // If sum == odd
    cout << "NO" << '\n';
  } else {
    cout << "YES\n";
    if(n % 2){ // if n == odd

      cout << (n+1)/2 << '\n';
      for(int i = 1; i < n; i += 4){
	printf("%d %d ", i, i+1);
      }
      cout << '\n';

      cout << (n-1)/2 << '\n';
      for(int i = 3; i < n; i += 4){
	printf("%d %d ", i, i+1);
      }
      cout << n << '\n';
      
    } else { // n == par
      cout << n/2 << '\n';
      for(int i = 0; i < (n/2)/2; i++){
	printf("%d %d ", n-(2*i), (2*i)+1);
      }
      cout << '\n';

      cout << n/2 << '\n';
      for(int i = 1; i < (n/2); i+=2){
	printf("%d %d ", n-i, i+1);
      }
      cout << '\n'; 
    }  
  }


  
  return 0;

}
