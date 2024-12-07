#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cout << "Enter the quantity of numbers and the length of the sequence: ";
    cin >> n >> k;
    vector<int> a(n);
    cout << "Enter the numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int maxp = 1;
    for (int i = 0; i < k; i++) {
        maxp *= a[i];
    }
    int curp = maxp;
    for (int i = k; i < n; i++) {
        curp = curp / a[i - k] * a[i];
        if (curp > maxp)
            maxp = curp;
    }

    cout << "The maximum product of length 'k': " << maxp;
}