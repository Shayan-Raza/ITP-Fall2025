#include <iostream> 
#include <vector>
using namespace std; 

bool valid_submission(int labNumber, int erp, const vector <string>& files, bool verbose = false) { 
    string expected_lab = "lab"+to_string(labNumber)+"_"+to_string(erp)+".zip";
    int pass=0;
    if (verbose) { 
        cout<<"Verbose Mode: "<<endl;
        cout<<"Validating Submission: "<<files[0]<<endl;
        cout<<" - "<<files[0];
        if (expected_lab == files[0]) { 
            cout<<" pass"<<endl;
            pass = pass + 1;
        } else { 
            cout<<" fail"<<endl;
        }
        for (int i = 1;i<files.size();i++) { 
            cout<<" - "<<files[i];
            if (files[i] == ("task"+to_string(i)+".cpp")) { 
                cout<<"  pass"<<endl;
                pass = pass + 1;
            } else { 
                cout<< "  fail"<<endl;
            }
        } cout<<"Summary for "<<files[0]<<".zip: "<<pass<<"/"<<files.size()<<" passed"<<endl;
    } else { 
        cout<<"Non-Verbose Mode: "<<endl;
        cout<<"Valid Zip name: ";
        if (expected_lab == files[0]) { 
            cout<<"Pass"<<endl;
        } else { 
            cout<<"Fail"<<endl;
        }
        bool flag = false;
        cout<<"Valid task name: ";
        for (int i = 1;i<files.size();i++) { 
            if (!(files[i] == ("task"+to_string(i)+".cpp"))) { 
                cout<< "  Failed"<<endl;
                flag = true;
                break;
            }
        } 
        if (!flag) { 
            cout<<"  Pass";
        }
        string specialstr;
        cout<<"Special character in task name: ";
        flag = true;
        for (int i = 0; i <files.size(); i++) { 
            for(int j = 0;j<files[i].length();j++) { 
                specialstr = files[i];
                if (specialstr[j] == '?' || specialstr[j] == '!' || specialstr[j] == '@') { //TO-DO Add all special characters
                    cout<<"   Failed"<<endl;
                    flag = false;
                }
            }
        }
        if (flag) { 
            cout<<"    Pass"<<endl;
        }
    }
    if (files.size() == pass) { 
        return true;
    } else { 
        return false;
    }
}

int main() { 
    vector<string> case1 = {"lab8_12345.zip","task1.cpp","task2.cpp","task3.cpp"};
    vector<string> case2 = {"lab08_12345.zip","task1.cpp","task2.cpp"};
    vector<string> case3 = {"lab8_12345.zip","task01.cpp","task2.cpp"};
    vector<string> case4 = {"lab8_12345.zip","task1!.cpp","task2.cpp"};
    
    valid_submission(8,12345,case1,true);
    valid_submission(8,12345,case2,true);
    valid_submission(8,12345,case3,true);
    valid_submission(8,12345,case4,true);
    valid_submission(8,12345,case4,false);
    return 0;
}