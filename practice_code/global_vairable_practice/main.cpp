#include <iostream>
using namespace std;

bool g_arr[10];

int main(void)
{
    fill_n(g_arr, 10, true);
    for (auto i : g_arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
