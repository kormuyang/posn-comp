#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<pair<string, int>> scores;

    scores.push_back({"Poom", 85});
    scores.push_back({"Kavin", 90});
    scores.push_back({"John", 70});

    string name;
    cin >> name;

    for (int i = 0; i < scores.size(); i++) {
        if (scores[i].first == name) {
            cout << scores[i].second << '\n';
        }
    }
    return 0;
}