#include <vector>
#include <iostream>

using namespace std;

//Vector는 자동으로 메모리가 할당되는 '배열'.
//삽입시 끝에 들어감
//삭제도 알아서 해줌

int main(void)
{
    vector<int> v1 = {1, 2, 3, 4, 5}; //비어있는 vector v를 생성
    for (auto i : v1) {
        cout << i << " ";
    }
    cout << endl;
    
    v1.erase(v1.begin() + 1, v1.begin() + 3);  
    for (auto i : v1) {
        cout << i << " ";
    } 
    cout << endl;
 
    return 0;
}
