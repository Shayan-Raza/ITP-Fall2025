#include <iostream>
#include <iomanip>
using namespace std; 

int main() { 
    double w = 0.0, b = 0.0,y,error,a=0.01,target;
    int x = 3;
    target  = 2*x*x -4;
    
    cout << fixed << setprecision(2);

    for (int i = 1; i<=1000;i++) { 
        y = w*x + b;
        error = target - y;
        w = w + a*error*x;
        b = b+a*error;
        if ((i%100)==0) { 
            cout<<"Step "<<i<<": prediction = "<<y<<", error = "<<error<<endl;
        } else if (i==1) { 
            cout<<"Step 0"<<": prediction = "<<y<<", error = "<<error<<endl;
        }
    } 
    
    cout<<"..."<<endl;
    cout<<"Final prediction at x = "<<x<<" : "<<y<<endl;
    cout<<"Target Value: "<<target<<endl;
    cout<<"Final w = "<<w<<" , b = "<<b;
    
    return 0;
}