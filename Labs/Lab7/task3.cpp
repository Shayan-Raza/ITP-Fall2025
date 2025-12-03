#include <iostream> 
using namespace std; 

int main() { 
    int a[9] = {1,2,3,4,5,6,7,8,9},b[9] = {9,8,7,6,5,4,3,2,1},c[9];
    for (int i = 0;i<3;i++) {
        for (int j =0;j<3;j++) {
            int index = i * 3 + j;
            c[index] = a[index] + b[index];
        }
    }
    cout<<"Matrix A (3x3)"<<endl;
    for (int i =0;i<3;i++) { 
        for (int j=0;j<3;j++) { 
            cout << a[i*3 +j]<< " ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Matrix B (3x3)"<<endl;
    for (int i =0;i<3;i++) { 
        for (int j=0;j<3;j++) { 
            cout << b[i*3 +j]<< " ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Resulting Matrix C (3x3)"<<endl;
    for (int i =0;i<3;i++) { 
        for (int j=0;j<3;j++) { 
            cout << c[i*3 +j]<< " ";
        }
        cout<<endl;
    }
    return 0;
}