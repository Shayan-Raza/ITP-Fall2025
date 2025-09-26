#include <iostream> 
using namespace std; 

int main() { 
    int num;
    int sum=0;
    cout<<"Enter a positive intger: ";
    cin>>num;

    for(int i=1;i<=(num/2);i++) { 
        if ((num%i) == 0) { 
            sum = sum + i;
        }
    }
    cout<<num;
    if (sum==num) { 
        cout<<" is a perfect number";
    } else { 
        cout<<" is not a perfect number";
    }

    return 0;
}