#include <iostream>
#include <cmath>
#include <array>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <cmath>
#define rep(_v, _e) for (int _v = 0; _v < _e; _v++)
using namespace std;

inline void lg() { cout << endl; }
template<class T> inline void lg(T t) { cout << t << endl; }
template<class T, class... S> inline void lg(T t, S... s){ cout << t << ' '; lg(s...); }

struct Edge {
    int r;
    int w;

    bool operator<(const Edge &other) const {
        return w > other.w;
    }
};

unordered_map<int, vector<Edge>> graph;
int result = 0;
unordered_set<int> unvis = {};
priority_queue<Edge> edges;


static void scan(int ix) {
    // lg("Scanning for ", ix);
    unvis.erase(ix);
    for (Edge i : graph[ix]) {
        // lg("Adding", i.r, i.w);
        edges.push(i);
    }
}

static void solve() {
    scan(-1);
    while (!edges.empty()) {
        Edge edge = edges.top();
        edges.pop();
        if (!unvis.count(edge.r)) continue;
        // lg(edge.r, edge.w);
        result += edge.w;
        scan(edge.r);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    rep(i, n) {
        int t;
        cin >> t;
        graph[-1].push_back({i, t});
        unvis.insert(i);
    }

    rep (i, m) {
        int f, t;
        cin >> f >> t;
        graph[f].push_back({t, 0});
        graph[t].push_back({f, 0});
    }

    solve();
    cout << result << '\n';
    return 0;
}
