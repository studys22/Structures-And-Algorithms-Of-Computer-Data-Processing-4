#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct classTime {
    int h1, m1, h2, m2;
    classTime() { h1 = m1 = h2 = m2 = 0; }
    bool operator<(const classTime& other) {
        return h2 == other.h2 ? m2 < other.m2 : h2 < other.h2;
    }
};

bool cmp(const classTime& prev, const classTime& next) {
    return prev.h2 == next.h1 ? prev.m2 <= next.m1 : prev.h2 < next.h1;
}

int main() {
    bool fileinput = true;
    string filename = "input4.txt";
    if (fileinput) {
        cout << "The input will be done from the file \"" << filename << "\"" << endl;
        freopen(filename.c_str(), "r", stdin);
    }

    if (!fileinput)
        cout << "Enter the number of classes: ";
    int n;
    cin >> n;
    vector<classTime> times(n);
    if (!fileinput)
        cout << "Enter the start time of all classes one at a time in a row. Input format: hh:mm - hh:mm, for example 09:50 - 13:00:" << endl;
    for (int i = 0; i < n; i++) {
        string s;
        while (s == "")
            getline(cin, s);

        int firstColon = s.find(':');
        times[i].h1 = stoi(s.substr(firstColon - 2, 2));
        times[i].m1 = stoi(s.substr(firstColon + 1, 2));
        int secondColon = s.find(':', firstColon + 1);
        times[i].h2 = stoi(s.substr(secondColon - 2, 2));
        times[i].m2 = stoi(s.substr(secondColon + 1, 2));
    }

    sort(times.begin(), times.end());

    classTime last;
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (cmp(last, times[i])) {
            res++;
            last = times[i];
        }
    }

    cout << "The maximum number of classes attended: " << res << endl;
    return 0;
}