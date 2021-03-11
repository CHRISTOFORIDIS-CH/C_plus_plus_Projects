#include <iostream>
#include <string>
#include <string.h>
using namespace std;
string User_Input;

int main() {
    cout << "Give the Expression(consits only of x and y) \n";
    cin >> User_Input;
    std::string str(User_Input);
    std::string stack;
    std::string status;
    int count = 0;
    bool wrongInput = false;
    bool runloop = true;
  while(runloop){
               
        if (count == 0) {
            stack.append("$");
            status.append("q1");
        }
        else if (count > 0) {           
            if (status.back() == '1') {
                if (stack.back() == 'A' && str[0] == 'x') {
                    status.append("q1");
                    stack.append("A");
                    str.erase(str.begin());
                }
                else if (stack.back() == 'A' && str[0] == 'y') {
                    status.append("q1");
                    stack.pop_back();
                    str.erase(str.begin());
                }
                else if (stack.back() == '$' && str[0] == 'x') {
                    status.append("q1");
                    stack.append("A");
                    str.erase(str.begin());
                }
                else if (stack.back() == '$' && str[0] == 'y') {
                    wrongInput = true;
                    break;
                } 
                else if (stack.back() == '$' && str.empty() == true) {
                    runloop = false;
                    status.append("q2");                   
                }
            }
            else {
                break;
            }
            if (stack.back()!= '$' && str.empty() == true) {
                wrongInput = true;
                break;
            }           
         }
        count++;
        cout << "Current Stack : " << stack << "\n";
        cout << "Current Status: " << status[status.length()]<<"q"<< status[status.length() - 1] << "\n";
        cout << "\n";
    }
    if (wrongInput == false) {
        cout << "The Expression " << User_Input << " is Recognized" << "\n";    
        cout << "Status Sequence: " << status << "\n";
        //loop is always +1 for example for xy is 4 loop becaues of last check for while loop to end thats why count - 1 for loops cout
        // i count as loop the first one too (count = 0)
        cout << "Number of Loops: " << count - 1 << "\n";
    }
    else {
        cout << "The Expression " << User_Input << " is not Recognized";
    }
    return 0;
}
/*
*q1 = starting status
*q2 = final status
*/
