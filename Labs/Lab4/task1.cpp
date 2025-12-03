#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter the number of terms: ";
    cin >> N;

    int a = 0, b = 1;

    cout << "Fibonacci Series: "<<endl;

    for (int i = 1; i <= N; ++i) {
        cout << a << " ";
        int next = a + b;
        a = b;
        b = next;
    }

    cout << endl;
    return 0;
}
