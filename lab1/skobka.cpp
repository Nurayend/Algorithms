#include <iostream>
#include <stack>

using namespace std;
bool skobki(string s){
    stack <char> st;

    for (int i = 0; i < s.size(); i++){
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else{
            if (st.empty())
                return false;
            if (s[i] == ')' && st.top() != '(')
                return false;
            if (s[i] == '}' && st.top() != '{')
                return false;
            if (s[i] == ']' && st.top() != '[')
                return false;
            else
                st.pop();
        }
    }

    // if (st.empty)
    //     return true;
    // return false;
    return (st.empty());
}

int main() {
    string s;
    cin >> s;
    if (skobki(s))
        cout << "yes";
    else
        cout << "no";
    return 0;
}