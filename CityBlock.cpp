#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

#define rng(_v, _s, _e) for (decltype(_e) _v = _s; _v < _e; _v++)
#define rep(_v, _e) rng(_v, 0, _e)
#define endl '\n'

char bd[102][102];
int comp[102][102];
int lc = 0;
int h, w;


inline void lg() { cout << endl; }
template<class T> inline void lg(T t) { cout << t << endl; }
template<class T, class... S> inline void lg(T t, S... s){ cout << t << ' '; lg(s...); }

void flood(int y, int x) {
    // lg(y, x);
    if (y < 0 || x < 0 || y >= h || x >= w || bd[y][x] != ' ' || comp[y][x] > 0) return;
    comp[y][x] = lc;
    flood(y + 1, x);
    flood(y - 1, x);
    flood(y, x + 1);
    flood(y, x - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> h >> w;
    cin.ignore(5, '\n');
    rep (i, h) {
        cin.getline(bd[i], 102);
    }

    rng (y, 1, h - 1) {
        rng (x, 1, w - 1) {
            if (bd[y][x] == ' ' && comp[y][x] == 0) {
                lc++;
                flood(y, x);
            }
        }
    }
    cout << lc << '\n';
    return 0;
}
