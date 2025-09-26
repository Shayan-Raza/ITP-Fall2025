#include <iostream>

using namespace std;

int main(){
	string name;
	int age; 
	
	cout<<"Enter your full name: ";
	getline(cin,name);
	cout<<"Enter your age: ";
	cin>>age;
	
	cout<<"Hello "<<name<<" you are " <<age<<" years old";
	
	return 0;
}