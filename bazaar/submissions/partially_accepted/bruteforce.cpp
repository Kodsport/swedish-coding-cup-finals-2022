#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(it,x) for(auto& it : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename T> ostream& operator<<(ostream& os, const vector<T> &v) { rep(i,0,sz(v)) { if (i) os << " " << v[i]; else os << v[i]; } os << endl; return os; }
template<typename T> istream& operator>>(istream& is, vector<T> &v) { trav(it, v) is >> it; return is; }
template<typename T> using v = vector<T>; template<typename T> using vv = v<v<T>>; template<typename T> using vvv = v<v<v<T>>>;
template<typename T> std::vector<T> make(T init, std::size_t size) { return std::vector<T>(size, init); }
template<typename T, typename... Args> auto make(T init, std::size_t first, Args... sizes) { auto inner = make<T>(init, sizes...); return std::vector<decltype(inner)>(first, inner); }
template<typename A, typename B> auto smax(A& a, const B& b) { if (b > a) a = b; }
template<typename A, typename B> auto smin(A& a, const B& b) { if (b < a) a = b;}
bool within(int r, int c, int R, int C) { return 0 <= r && r < R && 0 <= c && c < C; }

const int INF = 1'000'000;

int bf(const vector<bool>& inp, vector<bool>& used, bool turn) {
    int res = -INF;
    int bal = 0;

    for (int i = sz(inp) - 1; i >= 0; --i) {
        if (used[i]) continue;

        if (inp[i] == turn) {
            used[i] = true;
            res = max(res, bal - bf(inp, used, !turn));
            used[i] = false;
        }

        bal += (inp[i] == turn) ? 1 : -1;
    }

    return res == -INF ? 0 : res;
}

void solve() {
    int N;
    cin >> N;
    vector<bool> inp(N);
    rep(i,0,N / 2) {
        int x;
        cin >> x;
        inp[N - x] = false;
    }
    rep(i,0,N / 2) {
        int x;
        cin >> x;
        inp[N - x] = true;
    }
    vector<bool> used = make(false, sz(inp));
    cout << bf(inp, used, false) << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    
    int TC = 1;
    if (!TC) cin >> TC;
    rep(i,1,TC+1) {
        // cout << i << " ";
        solve();
    }
}
