#include <iostream>

using namespace std;

void solution(int N) 
{
    cout << N << " | ";
    int enable_print = N % 10;
    while (N > 0) {
        if (enable_print == 0 && N % 10 != 0) {
            enable_print = 1;
            continue;
        }
        else if (enable_print != 0) {
            cout << N % 10;
        }
        N = N / 10;
    }
    cout << endl;
}

int main(void) 
{
    solution(1001);
    solution(5);
    solution(50);
    solution(12345000);
    solution(9997);
    solution(1234);
    solution(1000000000);
    solution(102030405);
    solution(100000007);
    return 0;
}
