#include <iostream>
#include <utility>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

#define rng(_v, _s, _e) for (decltype(_e) _v = _s; _v < _e; _v++)
#define rep(_v, _e) rng(_v, 0, _e)
#define endl '\n'

int sums[1002];

static int sod(int n, int d) {
    if (!n || !d) return 0;
    if (d > n) swap(n, d);
    int r = 0;
    for (;;) {
        int digit = n / d;
        n = n % d;
        if (n == d) {
            r += digit + 1;
            break;
        }
        if (digit == 0) break;
        r += digit;
        if (!n) break;
        swap(n, d);
    }
    return r;
}

static int mx(int l, int r) {
    int h = 0;
    for (int i = l; i <= r; i++) if (sums[i] > h) h = sums[i];
    return h;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    for (int i = 0; i <= n; i++) {
        sums[i] = sod(i, n);
    }
    rep (i, q) {
        int l, r;
        cin >> l >> r;
        cout << mx(l, r) << '\n';
    }

    return 0;
}
