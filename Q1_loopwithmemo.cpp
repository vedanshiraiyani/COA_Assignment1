#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

void fib(vector<long long>& m) {
    m[0] = 0;
    m[1] = 1;
    for (int i = 2; i < 50; i++) {
        m[i] = m[i - 1] + m[i - 2];
    }
}

int main() {
    vector<long long> m(50);
    struct timespec s, e;
    clock_gettime(CLOCK_REALTIME, &s);

    fib(m);
    for (int i = 0; i < 50; i++) {
        cout << m[i] << " ";
    }
    cout << endl;

    clock_gettime(CLOCK_REALTIME, &e);
    double t = (e.tv_sec - s.tv_sec) + (e.tv_nsec - s.tv_nsec) / 1e9;
    cout << "Memoized loop time: " << t << " seconds" << endl;

    return 0;
}
