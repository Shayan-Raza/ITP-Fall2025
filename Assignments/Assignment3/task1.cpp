#include <iostream> 
using namespace std; 

string sort_string(string &str, int n = -1) { 
    string result = str;
    if (n == -1) { 
        n = result.length(); //setting the default value
    } 
    for (int i = 0;i<n-1;i++) { 
        int min = i;
        for (int j = i+1;j<n;j++) { 
            if (tolower(result[j])<tolower(result[min])) { 
                min = j;
            }
        }
        char t = result[i];
        result[i] = result[min];
        result[min] = t;
    }
    return result;
}

void sort_string_inplace(string &str,int n = -1) { 
    if (n == -1) { 
        n = str.length();
    }
    for (int i = 0;i<n-1;i++) { 
        int min = i;
        for (int j = i+1;j<n;j++) { 
            if (tolower(str[j])<tolower(str[min])) { 
                min = j;
            }
        }
        char t = str[i];
        str[i] = str[min];
        str[min] = t;
    }
}


int main() { 
    string strinput;
    int numinput = -1;
    cout<<"Enter the string you want to sort: ";
    getline(cin,strinput);
    cout<<"How many positions do you want to sort (any invalid input such as negative numbers or a string will sort all): ";
    cin>>numinput;
    // if numinput is invalid set it to use the full length of the string which is the default value
    // INVALID if a datatype other than int is entered
    if (cin.fail()) {
        cin.clear(); 
        cin.ignore(10000, '\n');
        cout << "Invalid input. Please enter a number.\n"; 
        numinput = strinput.length();
    }
    // INVALID if a N value is out of bounds
    if (numinput>strinput.length() || numinput < 0) { 
        numinput = strinput.length();
    }

    cout<<"Sorted string (new): "<<sort_string(strinput,numinput)<<endl;
    sort_string_inplace(strinput,numinput);
    cout<<"Sorted string (inplace): "<<strinput;
    return 0;
}