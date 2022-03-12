#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<bool> lowerOrUpper;
vector<vector<bool> > combination;

void makeCombinationsRecursive(int current) {
    if (lowerOrUpper.size() == 8) {
        combination.push_back(lowerOrUpper);
        return;
    }
    
    for (int i = current; i < 8; i++) {
        lowerOrUpper.push_back(false);
        makeCombinationsRecursive(current + 1);
        lowerOrUpper.pop_back();
        lowerOrUpper.push_back(true);
        makeCombinationsRecursive(current + 1);
        lowerOrUpper.pop_back();
    }
}

void printCombination() {
    for (int i = 0; i < combination.size(); i++) {
        for (int j = 0; j < combination[i].size(); j++) {
            cout << combination[i][j] << " ";
        }
        cout << endl;
    }
}

void makeCombinations() {
    makeCombinationsRecursive(0); 
    printCombination();
}

int main(void)
{
    cout << "Start" << endl;
    makeCombinations();
    return 0;
}
