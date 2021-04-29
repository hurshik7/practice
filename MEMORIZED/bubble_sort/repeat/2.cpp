#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void b_sort(vector<int>& arr);

int main(void)
{
    vector<int> arr = {3434, 21, 34, -1132, 3, 2, 4435, 21, 1, 33, 2, 4, 5, 6};
    vector<int> arr2(arr);
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;

    b_sort(arr);
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    cout << "sorted by algorithm header" << endl;
    sort(arr2.begin(), arr2.end());
    for (auto i : arr2) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

void b_sort(vector<int>& arr)
{
    for (int i = arr.size() - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j + 1] < arr[j]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    } 
}
