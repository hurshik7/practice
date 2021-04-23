#include <iostream>
#include <vector>
#include <random>
#include <time.h>

using namespace std;

#define MAX (20)

void printArr(const vector<int> ar);
void bubbleSort(vector<int>& ar);

int main(void) 
{
    srand(time(NULL));
    vector<int> ar(MAX);

    for (vector<int>::size_type i = 0; i < MAX; i++) {
        ar[i] = 1 + rand() % 20;
    }

    printArr(ar); 

    bubbleSort(ar);

    printArr(ar);
    
    return 0;
}

void printArr(const vector<int> ar)
{
    cout << "ar : ";
    for (int i = 0; i < (int)ar.size(); i++) {
        cout << ar[i] << " ";
    }   
    cout << endl;
}

void bubbleSort(vector<int>& ar)
{
    int temp;
    for (int i = ar.size() - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (ar[j] > ar[j + 1]) {
                temp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = temp;
            }
        }
    }    
}
