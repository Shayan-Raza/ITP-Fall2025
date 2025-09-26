#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() { 
    float n,a,b,mid,f_mid,f_a;
    
    cout<<"Enter number: ";
    cin>>n;

    if(n<1) { 
        b=1;
    } else { 
        b = n;
    }
    while ((fabs(b-a))>=0.01) { 
        mid = (a+b)/2;
        f_mid = mid*mid -n;

        if (fabs(b-a)<0.01) {
            break;
        }
        f_a = a*a -n;
        if ((f_mid > 0 && f_a > 0) || (f_mid < 0 && f_a < 0)) { 
            a = mid;
        } else { 
            b = mid;
        }  
    }
    cout<<setprecision(3)<<"The root is approximately: "<<(a+b)/2; 
    return 0;
}