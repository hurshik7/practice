//완전탐색 중 대표적인 조합을 찾는 알고리즘
//재귀

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int is_stop;
int tmp;

// n : 총 개수, picked : 선택한 위치 넣는 곳, toPick : 앞으로 몇개 더 담아야 하는지
void pick(int n, vector<int>& picked, vector<int> prices, int toPick);
void printPicked(vector<int> picked);

int main(void)
{
    vector<int> p;
    vector<int> prices = {21, 34, 55, 32, 24, 25, 54};
    sort(prices.begin(), prices.end());
    printPicked(prices);
    
    pick(prices.size(), p, prices, 2);
    cout << "tmp : " << tmp << endl;

    cout << "average price : " << tmp / 2 << endl; 

    return 0;
}

void pick(int n, vector<int>& picked, vector<int> prices, int toPick)
{
    if (toPick == 0) {
        if (prices[picked[picked.size() - 1]] - prices[picked[0]] <= 2) {            
            is_stop = 1;
            printPicked(picked);
            for (int j = 0; j < (int)picked.size(); j++) {
                tmp += prices[picked[j]];
            }
        }
        return;
    }
    int smallest = picked.empty() ? 0 : picked.back() + 1;
    for (int i = smallest; i < n; i++) {
        picked.push_back(i);
        if (!is_stop) {
            pick(n, picked, prices, toPick - 1);
        }
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
