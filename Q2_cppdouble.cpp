#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

void mult(const vector<vector<double>>& A, const vector<vector<double>>& B, vector<vector<double>>& C) {
    int N = A.size();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            C[i][j] = 0.0;
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    vector<int> sizes = {64, 128, 256, 512, 1024};
    srand(time(0));

    for (int N : sizes) {
        vector<vector<double>> A(N, vector<double>(N));
        vector<vector<double>> B(N, vector<double>(N));
        vector<vector<double>> C(N, vector<double>(N, 0.0));

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                A[i][j] = static_cast<double>(rand()) / RAND_MAX * 10.0;
                B[i][j] = static_cast<double>(rand()) / RAND_MAX * 10.0;
            }
        }

        clock_t s = clock();
        mult(A, B, C);
        clock_t e = clock();

        double t = double(e - s) / CLOCKS_PER_SEC;
        cout << "N = " << N << ": Time = " << t << " seconds" << endl;
    }

    return 0;
}
