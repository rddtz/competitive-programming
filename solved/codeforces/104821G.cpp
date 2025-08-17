#include <bits/stdc++.h>
#define ll long long int

#define MAXN 100005
#define MAXM 200005

using namespace std;


pair<int, int> A[MAXN + 10];
int n, m, K;
ll ans;

ll f[MAXM + 10];
ll g[MAXN + 10];

int main() {

  cin >> n >> m >> K;

  for (int i = 1; i <= n; i++){
    cin >> A[i].first >> A[i].second;
  }

  sort(A + 1, A + n + 1);

  ll sum = 0;
  g[n + 1] = 0;

  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = n; i > 0; i--) {
    pq.push(A[i].second);
    sum += A[i].second;

    if (pq.size() > K) {
      sum -= pq.top();
      pq.pop();
    }

    g[i] = sum;
  }

  for (int i = 0; i <= m; i++){
    f[i] = -1;
  }
  f[0] = 0;

  ans = g[1];

  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= A[i].first; j--) {
      f[j] = max(f[j], f[j - A[i].first] + A[i].second);
      ans = max(ans, f[j] + g[i + 1]);
    }
  }

  printf("%lld\n", ans);

  return 0;
}
