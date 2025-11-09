#include <bits/stdc++.h>

using namespace std;

// unordered_map vs map
// unordered_map -> hashing
// map -> binary search tree (BST)

// Basic Operations
// 1. Insert, 2. Access, 3. Find, 4. Delete

int main() {
    // string -> key, int -> value
    unordered_map<string, int> scores;

    // 1. Insert -> Average: O(1), Worst Case: O(N)
    scores["Kavin"] = 90;
    scores["Poom"] = 80;
    scores.insert({"John", 70});
    scores.insert({"Jane", 75});

    // 2. Access -> Average: O(1), Worst Case: O(N)
    cout << scores["Kavin"] << '\n';
    int score = scores["Poom"];
    cout << scores["Aom"] << '\n';

    // 3. Find -> Average: O(1), Worst Case: O(N)
    auto Kavin_it = scores.find("Kavin");
    if (scores.find("Aom") != scores.end()) {
        cout << "FOUND!\n";
    } else {
        cout << "NOT FOUND!\n";
    }

    // 4. Traverse
    for (auto it = scores.begin(); it != scores.end(); it++) {
        cout << it->first << ' ' << it->second << '\n';
    }

    // 5. Delete -> Average: O(1), Worse Case: O(N)
    scores.erase("Jane");
    scores.erase(scores.find("Jane"));
    scores.erase(Kavin_it);

    return 0;
}