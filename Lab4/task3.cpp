#include <iostream>
using namespace std;

int main() {
    int num;
    int defaultbit = 0;
    bool valid;
    for (int i = 1; i<=9;i++) { 
        cout<<"Enter number "<<i<<": "<<endl;
        cin>>num;
        if (num>=1 && num<=9) { 
            if (defaultbit &(1<< (num-1))) { 
                valid = false;
                break;
            }
        else { 
            defaultbit |= (1<<(num-1));
        }
        }
    }
    if (valid) { 
        cout<<"Valid";
    }else { 
        cout<<"Invalid "<<num<<" is repeated";
    }
    return 0;
}
