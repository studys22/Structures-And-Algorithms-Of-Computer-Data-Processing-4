#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct coin {
    int nominal, quantity;
    coin() { nominal = quantity = 0; };
};

struct status {
    int sum, step;
    status(int _sum, int _step) : sum(_sum), step(_step) {};
    status() { sum = step = 0; };
};

vector<int> result(const vector<int> &nominals, const vector<int> &quantity, int sum, int n) {
    map<vector<int>, int> res;
    res[quantity] = sum;
    queue<vector<int> > q;
    q.push(quantity);

    while (!q.empty()) {
        vector<int> curQuantity = q.front();
        q.pop();

        int curSum = res[curQuantity];

        for (int i = 0; i < n; i++) {
            int newSum = curSum - nominals[i];
            if (curQuantity[i] != 0 && newSum >= 0) {
                vector<int> newQuantity;
                newQuantity.assign(curQuantity.begin(), curQuantity.end());
                newQuantity[i]--;

                if (newSum == 0) {
                    return newQuantity;
                }

                if (res.find(newQuantity) == res.end()) {
                    res[newQuantity] = newSum;
                    q.push(newQuantity);
                }
            }
        }
    }
    vector<int> empty;
    return empty;
}

int main() {
    bool fileinput = true;
    string filename = "input3.txt";
    if (fileinput) {
        cout << "The input will be done from the file \"" << filename << "\"" << endl;
        freopen(filename.c_str(), "r", stdin);
    }

    if (!fileinput)
        cout << "The amount of coins to collect: ";
    int sum;
    cin >> sum;
    if (!fileinput)
        cout << "Number of coin denominations: ";
    int n;
    cin >> n;
    vector<int> nominals(n), quantity(n);
    if (!fileinput)
        cout << "The denomination of the coin and the number of coins of this denomination separated by a space:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> nominals[i] >> quantity[i];
    }

    vector<int> res = result(nominals, quantity, sum, n);
    if (res.empty())
        cout << "It's impossible" << endl;
    else {
        int count = 0;
        for (int i = 0; i < n; i++)
            count += quantity[i] - res[i];

        cout << "Minimum number of coins: " << count << ":" << endl;
        for (int i = 0; i < n; i++) {
            int c = quantity[i] - res[i];
            if (c != 0)
                cout << nominals[i] << " - " << c << endl;
        }
    }
    return 0;
}
