#include <iostream> 
using namespace std;

int main(){
    int num;
    int sum=0;
    int count = 0;
    
    cout<<"Enter number: ";
    cin>>num;

    while (num!= -1) { 
        if (num>0) { 
            sum = sum + num;
            count++;
        }
        cout<<"Enter number: ";
        cin>>num;
    }

    cout<<"Sum of all positive numbers is: "<<sum<<endl;
    cout<<"Count of all postivie numbers is: "<<count;

    return 0;
}