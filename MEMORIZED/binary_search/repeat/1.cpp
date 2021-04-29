#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool b_search_iter(const vector<int> arr, int value);
bool b_search_recur(const vector<int> arr, int value, int start, int end);

int main(void)
{
    vector<int> arr = {213, 3, 23, 44, 112, 0, 1, 2, -1, 3, -44234};
    sort(arr.begin(), arr.end());
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;
    cout << "213 : iter : " << b_search_iter(arr, 213) << endl;
    cout << "213 : recur : " << b_search_recur(arr, 213, 0, arr.size() - 1) << endl; 
    cout << "4 : iter : " << b_search_iter(arr, 4) << endl;
    cout << "4 : recur : " << b_search_recur(arr, 4, 0, arr.size() - 1) << endl;
    return 0;
}

bool b_search_iter(const vector<int> arr, int value)
{
    int mid;   
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end) {
        mid = (start + end) / 2;
        if (arr[mid] == value) {
            return true;
        } else if (arr[mid] < value) {
            start = mid + 1; 
        } else {
            end = mid - 1;
        }
    }
    return false;
}

bool b_search_recur(const vector<int> arr, int value, int start, int end)
{
    if (start > end) {
        return false;
    }    
    int mid = (start + end) / 2;
    if (arr[mid] == value) {
        return true;
    } else if (arr[mid] > value) {
        return b_search_recur(arr, value, start, mid - 1);
    } else {
        return b_search_recur(arr, value, mid + 1, end);
    }
}
