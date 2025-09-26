#include <iostream> 
using namespace std; 

int main(){
	int num1;
	int num2;
	
	cout<<"Enter first number: "; 
	cin>>num1;
	
	cout<<"\nEnter the second number: ";
	cin>>num2;
	
	num1 = num1 + num2; 
	num2 = num1 - num2;
	num1 = num1-num2;
	
	cout<<"After Swapping first number is: "<<num1<<endl<<"The second number is "<<num2;
	
	return 0;
}