#include <bits/stdc++.h>

using namespace std;

// unordered_set -> hashing

// Basic Operations
// 1. Insert, 2. Access, 3. Search, 4. Delete

int main() {
    unordered_set<string> students;

    // 1. Insert -> Average: O(1), Worst Case: O(N)
    students.insert("Jane");
    students.insert("Poom");
    students.insert("John");

    // 2. Access & 3. Search -> Average: O(1), Worst Case: O(N)
    auto Jane_it = students.find("Jane");
    cout << *Jane_it << '\n';

    // 4. Traverse
    // Traversing #1
    for (auto it = students.begin(); it != students.end(); it++) {
        cout << *it << '\n';
    }
    // Traversing #2
    for (auto &x : students) {
        cout << x << '\n';
    }

    // 5. Delete -> Average: O(1), Worse Case: O(N)
    students.erase("John");
    students.erase(students.find("Poom"));
    students.erase(Jane_it);

    return 0;
}