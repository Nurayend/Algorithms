#include <iostream>
#include <cmath>

using namespace std;

bool IsPrime(int n) {
    int a = 1;
    int b = sqrt((double)n);
    for (int i = 2; i <= b; i++){
        if (n % i == 0){
            a = i;
            break;
        }
    }
    if (a == 1)
        return true;
    else
        return false;
}
int main() {
    int n;
    cin >> n;
    if (IsPrime(n)) 
        cout<<"prime";
    else cout<<"composite";
    return 0;
}