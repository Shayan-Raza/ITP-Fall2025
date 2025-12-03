#include <iostream> 
#include <vector>
#include <string>
using namespace std; 

void helper() { 
    cout<<"Usage: \n";
    cout<<"\t<operator> <num1> <num2>\n";
    cout<<"Description\n";
    cout<<"\tPerform basic operations or run utility commands.\n";
    cout<<"Operators: \n";
    cout<<"\t+,-,*,/\n";
    cout<<"Commands\n";
    cout<<"\tHelp\t\tDisplay this help message\n";
    cout<<"\tHistory\t\tShow history of all the previous operations\n";
    cout<<"\tQuit\t\tExit the program\n";
};
float calculator(char op, int a,int b){ 
    switch(op) { 
        case '+': return a+b;
        case '-': return a-b;
        case '/': return a/b;
        case '*': return a*b;
    }
    return 0;
};
int main() {
    vector<vector<int>> history;
    int num1,num2,index=0,result;
    while (true) { 
        string userinput;
        cout<<">";
        getline(cin,userinput);
        if (userinput == "quit") { 
            break;
        } else if (userinput == "help") { 
            helper();
        } else if (userinput == "history") { 
            for (int i = 0;i<index;i++) { 
                cout<<history[i][0]<<" "<<static_cast<char>(history[i][1])<<" "<<history[i][2]<<" = "<<history[i][3]<<endl;
            }
        } else { 
            char op = userinput[0];
            int p1,p2;
            p1 = userinput.find(' ');
            p2 = userinput.find(' ',p1+1);
            num1 = stoi(userinput.substr(p1+1,p2-(p1+1)));
            num2 = stoi(userinput.substr(p2+1));
            if (op == '/' && num2 == 0) { 
                cout<<"Error: Divison by zero\n";
            } else { 
                result = calculator(op,num1,num2);
                cout<<result<<endl;
                history.push_back({num1,op,num2,result});
                index++;                
            }
        }
    } 
    return 0;
}