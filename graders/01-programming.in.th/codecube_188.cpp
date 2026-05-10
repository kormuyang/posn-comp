# include <bits/stdc++.h>

using namespace std;

class Integer {
public:
    int val, pos;
    bool operator<(const Integer &other) const {
        if (val == other.val) {
            return pos < other.pos;
        }
        return val < other.val;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<Integer> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].val;
        a[i].pos = i + 1;
    }
    sort(a.begin(), a.end());
    while (q--) {
        int l, r, c;
        cin >> l >> r >> c;
        Integer tmp_r;
        tmp_r.val = c;
        tmp_r.pos = r;
        Integer tmp_l;
        tmp_l.val = c;
        tmp_l.pos = l;
        cout << upper_bound(a.begin(), a.end(), tmp_r) - lower_bound(a.begin(), a.end(), tmp_l) << '\n';
    }
    return 0;
}