#include <bits/stdc++.h>
#define ll long long int

using namespace std;

#define MAX 1000005

int L[MAX] = {0};
int R[MAX] = {0};

ll mergesort(int l, int r) {

    if (l >= r) {
        return 0;
    }

    int mid = l + (r - l) / 2;

    ll count = mergesort(l, mid) + mergesort(mid + 1, r);

    vector<int> temp_R;
    for (int j = mid + 1; j <= r; ++j) {
        temp_R.push_back(R[j]);
    }

    sort(temp_R.begin(), temp_R.end());

    for (int i = l; i <= mid; ++i) {

        ll smaller_count = distance(temp_R.begin(), lower_bound(temp_R.begin(), temp_R.end(), L[i]));

        count += smaller_count;
    }

    return count;
}

int main() {

    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int a[n+1] = {0};
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    map<int, int> aparicoes;
    for (int i = 0; i < n; ++i) {
        aparicoes[a[i]]++;
        L[i] = aparicoes[a[i]];
    }

    aparicoes.clear();
    for (int i = n - 1; i >= 0; --i) {
        aparicoes[a[i]]++;
        R[i] = aparicoes[a[i]];
    }

    cout << mergesort(0, n - 1);

    return 0;
}
