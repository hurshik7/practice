#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool binarySearchIterative(const vector<int> ar, int key);
bool binarySearchRecursive(const vector<int> ar, size_t start, size_t end, int key);
void printArr(vector<int> ar);

int main(void)
{
    vector<int> ar = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    sort(ar.begin(), ar.end());
    
    printArr(ar);
   
    cout << "find : 2 --(Recursive)-- " << binarySearchRecursive(ar, 0, ar.size() - 1, 2)  << endl; 
    cout << "find : 2 --(Iterative)-- " << binarySearchIterative(ar, 2) << endl; 
    cout << "find : 10 --(Recursive)-- " << binarySearchRecursive(ar, 0, ar.size() - 1, 10)  << endl; 
    cout << "find : 10 --(Iterative)-- " << binarySearchIterative(ar, 10) << endl;  
    return 0;
}

bool binarySearchIterative(const vector<int> ar, int key)
{
    size_t start = 0;
    size_t end = ar.size() - 1;
    size_t mid;

    while (start <= end) {
        mid = (start + end) / 2;
        if (ar[mid] == key) {
            return true;
        } else {
            if (ar[mid] < key) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
    return false;
}

bool binarySearchRecursive(const vector<int> ar, size_t start, size_t end, int key)
{
    size_t mid = (start + end) / 2;
    if (start > end) {
        return false;
    }
    if (ar[mid] == key) {
        return true;
    }
    if (ar[mid] < key) {
        return binarySearchRecursive(ar, mid + 1, end, key);
    } else {
        return binarySearchRecursive(ar, start, mid - 1, key);
    }
}

void printArr(vector<int> ar)
{
    vector<int>::iterator iter;
    for (iter = ar.begin(); iter != ar.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}
