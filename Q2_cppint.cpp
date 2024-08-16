#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

void mult(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C) {
    int N = A.size();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            C[i][j] = 0;
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
        vector<vector<int>> A(N, vector<int>(N));
        vector<vector<int>> B(N, vector<int>(N));
        vector<vector<int>> C(N, vector<int>(N, 0));

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                A[i][j] = rand() % 10;
                B[i][j] = rand() % 10;
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
