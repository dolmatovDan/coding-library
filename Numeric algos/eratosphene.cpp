#include <iostream>
#include <vector>
using namespace std;


void print_vector_int(vector<int> &A) {
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << '\t';
    }
}

int main()
{
    const int64_t N = 100000000000000;
    vector<bool> is_prime(N + 1);
    for (int64_t i = 0; i < N + 1; i ++) {
        is_prime[i] = true;
    }

    for (int64_t  x = 2; x * x <= N; x++) { //��������� �� �����
        if (is_prime[x]) { //��������� ������ ��� �������
            for (int64_t y = x * x; y <= N; y += x) { // ��������� ������� � �������� x
                is_prime[y] = false;
            }
        }
    }
    int res = 0;
    for (int64_t i = 1000000000000; i <= N; i++) {
        if (is_prime[i]) {
            cout << i << ", ";
            res++;
        }
    }
    cout << res << endl;
    return 0;
}
