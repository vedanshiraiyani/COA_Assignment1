#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

long long fib(int n, vector<long long>& m) {
    if (n <= 1)
        return n;
    if (m[n] != -1)
        return m[n];
    return m[n] = fib(n - 1, m) + fib(n - 2, m);
}

int main() {
    vector<long long> m(50, -1);
    struct timespec s, e;
    clock_gettime(CLOCK_REALTIME, &s);

    for (int i = 0; i < 50; i++) {
        cout << fib(i, m) << " ";
    }
    cout << endl;

    clock_gettime(CLOCK_REALTIME, &e);
    double t = (e.tv_sec - s.tv_sec) + (e.tv_nsec - s.tv_nsec) / 1e9;
    cout << "Memoized recursion time: " << t << " seconds" << endl;

    return 0;
}
