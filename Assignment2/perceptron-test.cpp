#include <iostream>
#include <cmath>
using namespace std; 

int main() { 
    double w = 0.0, b = 0.0,y,error,a=0.01;
    int x,target,count=0;
    
    for (int i = 0;i<10;i++) {
        cout<<"Enter number: ";
        cin>>x;
        for (int i = 1; i<=1000;i++) { 
            target = 2*x*x - 4;
            y = w*x + b;
            error = target - y;
            w = w + a*error*x;
            b = b+a*error;
        }
        cout<<"X: "<<x<<"Perceptrons guess: "<<y<<" target value: "<<target<<"  ";
        if (fabs(y-target)<=1.0) { 
            count = count + 1;
            cout<<"Correct"<<endl;
        } else { 
            cout<<"Incorrect"<<endl;
        }
    }
    cout<<"Accuracy: "<<count/10.00 * 100.00;

    return 0;
}