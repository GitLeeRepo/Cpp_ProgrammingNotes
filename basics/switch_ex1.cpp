// switch_ex1.cpp
//
// Shows a switch statement example, comparing to to an if / else if / else 
// series of statements.

#include <iostream>

int main() {
    using namespace std;

    int eval;

    cout << "Enter a number between 1 and 4 to be evaluated in a switch and if / else if / else" << endl;
    cin >> eval;

    cout << "Evaluating using a switch" << endl;
    switch (eval) {
        case 1: 
            cout << "You entered one" << endl;
            break;
        case 2:  // 2 falls through to 3.  The equivalent of an or condition
        case 3:
            cout << "You entered either two or three" << endl;
            break;
        case 4: 
            cout << "You entered four" << endl;
            break;
        default:
            cout << "You did not enter one of the requested numbers" << endl;
    }

    cout << "Evaluating using if / elseif / else" << endl;
    if (eval == 1)
        cout << "You entered one" << endl;
    else if (eval == 2 or eval == 3)
        cout << "You entered either two or three" << endl;
    else if (eval == 4)
        cout << "You entered four" << endl;
    else
        cout << "You did not enter one of the requested numbers" << endl;

    return 0;
}
