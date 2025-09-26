#include <iostream> 

using namespace std; 

int main(){
	int num;
	
	cout<<"Enter an integer: ";
	cin>>num;

    	if ((num & 1)==1) {
        	cout << num << " is odd." << endl;
    	} else {
        	cout << num << " is even." << endl;
    	}

    return 0;
}
