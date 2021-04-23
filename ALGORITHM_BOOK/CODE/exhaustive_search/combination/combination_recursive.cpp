//완전탐색 중 대표적인 조합을 찾는 알고리즘
//재귀

#include <iostream>
#include <vector>

using namespace std;

// n : 총 개수, picked : 선택한 위치 넣는 곳, toPick : 앞으로 몇개 더 담아야 하는지
void pick(int n, vector<int>& picked, int toPick);
void printPicked(vector<int> picked);

int main(void)
{
    vector<int> p;
    
    pick(10, p, 4);    

    return 0;
}

void pick(int n, vector<int>& picked, int toPick)
{
    if (toPick == 0) {
        printPicked(picked);
        return;
    }
    int smallest = picked.empty() ? 0 : picked.back() + 1;
    for (int i = smallest; i < n; i++) {
        picked.push_back(i);
        pick(n, picked, toPick - 1);
        picked.pop_back();
    }
}

void printPicked(vector<int> picked)
{
    cout << "{ ";
    for (auto i : picked) {
        cout << i << " ";
    }
    cout << "}" << endl;
}
