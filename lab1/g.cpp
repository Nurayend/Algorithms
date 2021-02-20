#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>

using namespace std;
int main(){
    string s;
    stack <int> st;
    getline(cin, s);
    
    for (int i = 0; i < s.size(); i++){
        int right;
        int left;
        if (s[i] == ' ')
            continue;
        else if (s[i] != '+' && s[i] != '-' && s[i] != '*') 
            st.push(atoi(s[i]));
        else {
            right = st.top();
            st.pop();
            left = st.top(); //to change to int
            st.pop();
            if (s[i] == '+')
                st.push(left + right);
            else if (s[i] == '-')
                st.push(left - right);
            else if (s[i] == '*')
                st.push(left * right);
        }
        //cout << right << " " << left << endl;
    }
    cout << st.top() << endl;
    return 0;
}