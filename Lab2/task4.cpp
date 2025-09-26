#include <iostream>

using namespace std; 

int main() {
	int current_perm;
	int toggle_mask;

	cout<<"Enter current permissions (0-7): ";
	cin>>current_perm;
	
	cout<<"Current permissions"<<endl;	
	cout<<"Read: "<<((current_perm & 4) ? "True":"False") <<endl;
	cout<< "Write: "<< ((current_perm & 2) ? "True" : "False")<< endl;
	cout<< "Execute: "<< ((current_perm & 1) ? "True" : "False")<< endl;

	cout<<"Enter toggle mask (0-7): ";
	cin>>toggle_mask;
	
	current_perm ^= toggle_mask;
	
	cout<< "New permissions" <<endl;
	cout<< "Read: "<<((current_perm & 4) ? "True" : "False")<< endl;
	cout<< "Write: "<<((current_perm & 2) ? "True" : "False")<<endl;
	cout<< "Execute: "<<((current_perm & 1) ? "True" : "False")<<endl;
		
	return 0; 
}