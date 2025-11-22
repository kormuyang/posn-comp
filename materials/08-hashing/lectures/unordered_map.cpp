#include <bits/stdc++.h>

using namespace std;

// unordered_map -> hashing

// Basic Operations
// 1. Insert, 2. Access, 3. Search, 4. Delete

int main() {
    // key -> string, value -> int
    unordered_map<string, int> scores;

    // 1. Insert -> Average: O(1), Worst Case: O(N)
    scores["Aom"] = 90;
    scores["Poom"] = 80;
    scores.insert({"John", 70});
    scores.insert({"Kavin", 75});

    // 2. Access -> Average: O(1), Worse Case: O(N)
    cout << scores["Aom"] << '\n';
    int score = scores["Poom"];
    cout << scores["Jane"] << '\n';

    // 3. Search -> Average: O(1), Worse Case: O(N)
    auto Kavin_it = scores.find("Kavin");
    if (scores.find("Jane") != scores.end()) {
        cout << "FOUND!\n";
    } else {
        cout << "NOT FOUND!\n";
    }

    // 4. Traverse
    // Traversing #1
    for (auto it = scores.begin(); it != scores.end(); it++) {
        cout << it->first << ' ' << it->second << '\n';
    }
    // Traversing #2
    for (auto &[key, val] : scores) {
        cout << key << ' ' << val << '\n';
    }

    // 5. Delete -> Average: O(1), Worse Case: O(N)
    scores.erase("Jane");
    scores.erase(Kavin_it);
    scores.erase(scores.find("Aom"));

    return 0;
}