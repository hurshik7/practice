#include <vector>
#include <iostream>

using namespace std;

//Vector는 자동으로 메모리가 할당되는 '배열'.
//삽입시 끝에 들어감
//삭제도 알아서 해줌

int main(void)
{
    vector<int> v1; //비어있는 vector v를 생성
    vector<int> v2(5); //기본값 0으로 초기화 된 5개의 원소를 가지는 vector v2를 생성
    vector<int> v3(5, 2); //기본값 2로 초기화 된 5개의 원소를 가지는 vector v3를 생성
    vector<int> v4(v3); //v3를 복사해서 생성됨.
    
    vector<int>::size_type i;
    
    v1.assign(5, 2); //2의 값으로 5개의 원소 할당.
    for (i = 0; i < v1.size(); ++i) 
    {
        cout << v1[i] << ", ";
    }
    cout << endl;

    for (i = 0; i < v2.size(); ++i) 
    {
        v2.at(i) = i;
        cout << v2.at(i) << ", ";
    }
    cout << endl;
    cout << "v2[0] : " << v2.front() << endl;
    cout << "v2.back() : " << v2.back() << endl;

    v1.clear(); //모든 원소를 제거, 메모리는 남아있다. size는 0으로, capacity는 그래로
    cout << "after clear v1[0] : " << v1[0] << endl;
    
    v3.push_back(6);
    v3.push_back(9);
    
    for (i = 0; i < v3.size() - 1; ++i) 
    {
        cout << v3[i] << ", ";
    }
    cout << v3[i] << endl;

    v3.pop_back();
    for (i = 0; i < v3.size(); ++i)
    {
        cout << v3[i] << ", "; 
    }
    cout << endl;

    cout << "swap" << endl;
    v3.swap(v1);
    for (i = 0; i < v1.size(); ++i)
    {
        cout << v1[i] << ", "; 
    }
    cout << endl;

    cout << "v4 : " << endl; //vector<int>::size_type 으로 요소 접근;
    for (vector<int>::size_type j = 0; j < v4.size(); ++j) 
    {
        cout << v4[j] << ", ";
    }
    cout << endl;

    // iterator로 접근
    vector<int>::iterator iter;
    for (iter = v4.begin(); iter != v4.end(); iter++) 
    {
        cout << *iter << ", ";
    }
    cout << endl;
 
    return 0;
}
