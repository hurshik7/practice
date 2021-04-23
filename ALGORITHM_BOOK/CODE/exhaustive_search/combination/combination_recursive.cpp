#include <iostream>
#include <vector>

using namespace std;

void pick(int n, vector<int>& picked, int toPick);
void printPicked(vector<int> picked);

int main(void)
{
    cout << "0 ~ '    



    return 0;
}

void pick(int n, vector<int>& picked, int toPick)
{
    if (toPick == 0) {
        printfPicked(ar);
        return;
    } 
    int smallest_index = picked.empty() ? 0 : picked.back() + 1;
}

void printPicked(vector<int> picked)
{
    cout << "{ ";
    for (auto i : picked) {
        cout << i << " ";
    }
    cout << "}" << endl;
}
