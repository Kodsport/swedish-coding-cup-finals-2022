/* @EXPECTED_GRADES@ RTE RTE RTE AC RTE RTE */
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

int W, H;
int xs1, ys1, xd1, yd1;
int xs2, ys2, xd2, yd2;

bool within(int l, int m, int r) {
    return l <= m && m <= r ||
           r <= m && m <= l;
}

void solve() {
    cin >> W >> H;
    cin >> xs1 >> ys1 >> xd1 >> yd1;
    cin >> xs2 >> ys2 >> xd2 >> yd2;

    if (xs1 == xd1 || ys1 == yd1) {
        cout << "CRISIS AVERTED" << endl;
        return;
    }
    if ((xs1 + ys1) % 2 == (xs2 + ys2) % 2) {
        cout << "MAYHEM POSSIBLE" << endl;
    } else {
        cout << "CRISIS AVERTED" << endl;
    }

}

int main(int argc, char** argv) {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    
    int TC = argc == 1 ? 1 : 0;
    if (!TC) cin >> TC;
    rep(i,1,TC+1) {
        // cout << i << " ";
        solve();
    }
}