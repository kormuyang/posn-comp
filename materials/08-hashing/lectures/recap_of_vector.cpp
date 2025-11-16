// STL -> Standard Template Library

#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<pair<string, int>> scores;
    scores.push_back({"Aom", 90});
    scores.push_back({"Poom", 85});
    scores.push_back({"John", 80});

    // string name;
    // cin >> name;
    // for (int i = 0; i < scores.size(); i++) {
    //     if (scores[i].first == name) {
    //         cout << scores[i].second << '\n';
    //     }
    // }

    // using iterator
    for (auto it = scores.begin(); it != scores.end(); it++) {
        cout << it->first << ' ' << it->second << '\n';
    }

    // pass by reference
    for (auto &x : scores) {
        cout << x.first << ' ' << x.second << '\n';
    }

    // pass by reference
    for (auto &[f, s] : scores) {
        cout << f << ' ' << s << '\n';
    }

    // pass by value
    for (auto [f, s] : scores) {
        cout << f << ' ' << s << '\n';
    }
    return 0;
}