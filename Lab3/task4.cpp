#include <iostream>

using namespace std; 

int main() { 
	int num;
	int shift_amount; 

	cout<<"Enter raw sensor data: ";
	cin>>num;
	
	cout<<"Enter shift amount: ";
	cin>>shift_amount;

	if (num >=100 && num<=500) { 
		cout<<"New value(Right shift): "<< (num>>shift_amount);
	} else { 
		cout<<"Amplified Value (Left shift): "<<(num<<shift_amount);
	}
	return 0;
}