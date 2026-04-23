#include <iostream>
using namespace std;
int josephus(int n, int k) {
    if (n == 1)
        return 0;
    return (josephus(n - 1, k) + k) % n;
}
int main() {
    int n = 7, k = 3;
    cout << "Safe position: " << josephus(n, k) + 1 << endl;
    return 0;
}