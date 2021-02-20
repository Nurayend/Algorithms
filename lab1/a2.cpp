#include <iostream>
 
template <class T>
class Stack
{
private:
        T * arr;
        int size, len;
        void new_size(int s)
        {
                if (s<=0) return;
                T * new_arr = new T[s];
                int min_s = s<len?s:len;
                for (int i = 0; i<min_s; i++) new_arr[i] = arr[i];
                delete[] arr;
                size = s;
                arr = new_arr;
        }
 
public:
        Stack()
        {
                len = 0;
                arr = new T[size = 5];
        }
 
        Stack(Stack & st)
        {
                arr = new T[size = st.size];
                len = st.len;
                for (int i = 0; i < len; i++) arr[i] = st.arr[i];
        }
 
        ~Stack()
        {
                delete[] arr;
        }
 
        int Size()
        {
                return len;
        }
 
        void Push(T x)
        {
                if (len == size) new_size(size<<1);
                arr[len++] = x;
        }
        T Pop()
        {
                if (size > 10 && len < size>>2) new_size(size>>1);
                if (len == 0) return arr[len];
                return arr[--len];
        }
        T Top()
        {
                return arr[len];
        }
        void Clear()
        {
                delete arr;
                len = 0;
                arr = new T[size = 5];
        }
 
        bool IsEmpty()
        {
                return len == 0;
        }
 
        Stack<T> operator + (Stack<T> & st)
        {
                Stack<T> S;
                S.new_size(len + st.len + 10);
                for (int i = 0; i<len; i++) S.arr[S.len++] = arr[i];
                for (int i = 0; i<st.len; i++) S.arr[S.len++] = st.arr[i];
                return S;
        }
        Stack<T> operator + (T x)
        {
                Stack<T> S;
                S.new_size(len + 10);
                for (int i = 0; i<len; i++) S.arr[S.len++] = arr[i];
                S.arr[S.len++] = x;
                return S;
        }
 
        Stack<T> & operator += (Stack<T> & st)
        {
                if (len + st.len > size) new_size(len + st.len + 10);
                for (int i = 0; i<st.len; i++) arr[len++] = st.arr[i];
                return *this;
        }
 
        inline Stack<T> & operator += (T x)
        {
                Push(x);
                return *this;
        }
 
        Stack<T> & operator = (Stack<T> & st)
        {
                delete[] arr;
                arr = new T[size = st.size];
                len = st.len;
                for (int i = 0; i < len; i++) arr[i] = st.arr[i];
                return *this;
        }
        bool operator == (Stack<T> & st)
        {
                if (len != st.len) return false;
                for (int i = 0; i<len; i++) if (arr[i]!=st.arr[i]) return false;
                return true;
        }
 
        inline bool operator != (Stack<T> & st)
        {
                this->operator == (st);
        }
        inline Stack<T> & operator >> (T & x)    // = pop
        {
                x = Pop();
                return *this;
        }
        inline Stack<T> & operator << (T x)    // = push
        {
                Push(x);
                return *this;
        }
};
 
 
using namespace std;
int main(int argc, char* argv[])
{
    Stack<int> S;
    int x;
    S<<33;
    S>>x;
    cout<<x<<endl;
 
    S<<1<<2<<10;
    while (!S.IsEmpty()) cout<<S.Pop()<<" ";
    cout<<endl;
 
    S<<1<<2<<10;
    Stack<int> S1;
    S1.Push(78);
    S += S1 + S + 20;
    while (!S.IsEmpty()) cout<<S.Pop()<<" ";
    cout<<endl;
 
    Stack<char*> S_str;
    S_str<<"qwer"<<"asdf"<<"zxcv";
    while (!S_str.IsEmpty()) cout<<S_str.Pop()<<" ";
    cout<<endl;
 
    cin>>x;
    return 0;
}