#include <iostream>

using namespace std; 

int main() {
	int temperature; 

	cout<<"Enter the temperature: ";
	cin>>temperature;
	
	string result = (temperature<15) ? "Cold" : (temperature>=15 && temperature<=25) ? "Moderate" : "Hot";
	cout<<result;
	
	return 0; 
}