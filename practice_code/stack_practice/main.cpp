#include <iostream>
#include <stack>
#include <typeinfo>

using namespace std;

int main(void)
{
    stack<int> st;
    st.push(1);
    cout << st.top() << endl;
    if (st.top() == 1) {
        cout << "yes" << endl;
    }
    return 0;
}
