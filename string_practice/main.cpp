#include <string>
#include <iostream>

using namespace std;

int main(void)
{
    string s = "Hurshik";
    string::reverse_iterator iter;
    for (iter = s.rbegin(); iter != s.rend(); iter++) {
        cout << *iter << endl;
    } 
    return 0;
}
