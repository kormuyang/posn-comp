#include <bits/stdc++.h>

using namespace std;

// unordered_set vs set
// unordered_set -> hashing
// set -> binary search tree (BST)

// Basic Operations
// 1. Insert, 2. Access, 3. Find, 4. Delete

int main() {
    unordered_set<string> students;

    // 1. Insert -> Average: O(1), Worst Case: O(N)
    students.insert("Kavin");
    students.insert("Poom");
    students.insert("John");

    // 2. Access & 3. Find -> Average: O(1), Worst Case: O(N)
    auto Kavin_it = students.find("Kavin");
    cout << *Kavin_it << '\n';

    // 4. Traverse
    for (auto it = students.begin(); it != students.end(); it++) {
        cout << *it << '\n';
    }

    // 5. Delete -> Average: O(1), Worse Case: O(N)
    students.erase("John");
    students.erase(students.find("Poom"));
    students.erase(Kavin_it);

    return 0;
}