#include <iostream>

using namespace std;

const int DAYS[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const string DAY_IN_WEEK[] = {"Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday"};

int main() {
    int d, m;
    cin >> d >> m;
    int sum = d;
    for (int i = 0; i < m; i++) {
        sum += DAYS[i];
    }
    int idx = (sum - 1) % 7;
    cout << DAY_IN_WEEK[idx] << '\n';
    return 0;
}