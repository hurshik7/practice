#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    string s = "Hurshik";
    string::reverse_iterator iter;
    for (iter = s.rbegin(); iter != s.rend(); iter++) {
        cout << *iter << endl;
    }

    vector<string> strings = {"Hurshik", "mooo", "hello"};
    string temp;
    temp = strings[0];
    strings[0] = strings[1];
    strings[1] = temp;
    
    for (auto i : strings) {
        cout << i << ", ";
    }
    cout << endl;

    cout << "--------------------" << endl;
    string a = "Hurshik";
    cout << a.find('s') << endl;
    if (a.find('S') == string::npos) {
        cout << "npos!!" << endl;
    } 
    return 0;
}
