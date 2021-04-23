#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bubbleSort(vector<int> &arr);
void printArr(vector<int> arr);

int main(void)
{
    vector<int> arr1 = {7, 4, 5, 1, 3};
    vector<int> arr2 = {7, 4, 5, 1, 3};

    sort(arr1.begin(), arr1.end());

    cout << "arr1 (sorted by std algorithm) : ";
    printArr(arr1);

    cout << "arr2 : ";
    printArr(arr2);

    cout << "bubble sorted : ";
    bubbleSort(arr2);
    printArr(arr2);

    return 0;
}

void bubbleSort(vector<int> &arr)
{
    for (vector<int>::size_type i = arr.size() - 1; i > 0; i--) {
        for (vector<int>::size_type j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        } 
    }
}

void printArr(vector<int> arr)
{
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;
}
