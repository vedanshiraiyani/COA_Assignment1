#include <iostream>
#include <time.h>

using namespace std;

long long fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
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
