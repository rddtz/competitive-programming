// https://cses.fi/problemset/task/1618
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin >> n;
    ll f = 0;
    for(int i = 1; i < 18; i++){
      f = f + n/(ll)(pow(5,i) + 1e-9);
    }
    cout << f << '\n';
}
