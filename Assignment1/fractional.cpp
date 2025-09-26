#include <iostream>
using namespace std; 

int main() { 
    int frac11,frac12,frac21,frac22;
    int temp;
    int result1,result2;
    char operation;
    
    cout<<"Enter numerator and denominator of the first fraction: ";
    cin>>frac11;
    cin>>frac12;

    cout<<"Enter numerator and denominator of the second fraction: ";
    cin>>frac21;
    cin>>frac22;

    cout<<"Enter operation (+,-,*,/): ";
    cin>>operation;

    cout<<"Result: ";

    if (operation == '+') { 
        if (frac12==frac22) { 
            result1 = frac11 + frac21;
            cout<<result1<<"/"<<frac12;
        } else { 
            temp = frac12;
            frac11 = frac11 * frac22;
            frac21 = frac21*temp;
            frac12 = frac12 * frac22;
            frac22 = frac22 * temp;

            result1 = frac11 + frac21;
            result2 = frac12;

            cout<<result1<<"/"<<result2;
        }
    } else if(operation == '-') { 
        if (frac12==frac22) { 
            result1 = frac11 - frac21;
            cout<<result1<<"/"<<frac12;
        } else { 
            temp = frac12;
            frac11 = frac11 * frac22;
            frac21 = frac21*temp;
            frac12 = frac12 * frac22;
            frac22 = frac22 * temp;

            result1 = frac11 - frac21;
            result2 = frac12;

            cout<<result1<<"/"<<result2;
        }
    } else if(operation == '*') { 
        result1 = frac11 * frac21;
        result2 = frac12 * frac22;

        cout<<result1<<"/"<<result2;
    } else if(operation == '/') { 
        temp = frac21;
        frac21 = frac22;
        frac22 = temp;

        result1 = frac11 * frac21;
        result2 = frac12 * frac22;

        cout<<result1<<"/"<<result2;

    }
    return 0; 
}