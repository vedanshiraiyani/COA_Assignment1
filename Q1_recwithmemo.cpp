#include <iostream>
#include <time.h>

using namespace std;

long long fib(int n) {
    if (n <= 1)
        return n;
    long long x = 0, y = 1, z;
    for (int i = 2; i <= n; i++) {
        z = x + y;
        x = y;
        y = z;
    }
    return y;
}

int main() {
    struct timespec s, e;
    clock_gettime(CLOCK_REALTIME, &s);

    for (int i = 0; i < 50; i++) {
        cout << fib(i) << " ";
    }
    cout << endl;

    clock_gettime(CLOCK_REALTIME, &e);
    double t = (e.tv_sec - s.tv_sec) + (e.tv_nsec - s.tv_nsec) / 1e9;
    cout << "Execution time: " << t << " seconds" << endl;

    return 0;
}
