// S = stack{}

// while (cin(s)) {
//  If (s == “+” || s == “*” || s == “-) {
//   Int a = s.back()
//   s.pop()
//   Int b = s.back()
//   s.pop()
//  If ( s == “+) {
//   s.back(a+b)
//  } else if (s == “*) {
//   s.back(a*b)
//  } else if (s == “-”) {
//   s.back(b-a)
//  }

//  } else {
//   s.push(atoi(s))
//  }
// }
// Cout << s.back(

#include <bits/stdc++.h>

using namespace std;

int main(){
    char str [256];
    stack <int> st;
    while(cin(str)){
        if(str == '+' || str == '*' || str == '-'){
            int right = st.top();
            st.pop();
            int left = st.top();
            st.pop();
            if(str == '+')
                st.push(left + right);
            else if(str == '*')
                st.push(left * right);
            else if(str == '-')
                st.push(left - right);
        }
        else
            st.push(atoi(str));
    }
    cout << st.top();
    return 0;
}