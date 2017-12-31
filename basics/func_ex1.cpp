// func_ex1.cpp
//
// Illustrates calling a function by value and by reference

// fuction called with a reference parameter which will be changed on return

#include <iostream>

int funcByRef(int& times2) {
    times2 *= 2;  // change reflected after the function returns
    return times2;
}


// function called with a parmater by value which won't be changed on return
int funcByVal(int times2) {
    times2 *= 2;   // only changed locally
    return times2;
}

int main() {
    using namespace std;

    int x = 2; 
    int result = 0;

    // x passed by value, so unchanged by the function    
    cout << "x before calling funcByVal(): " << x << endl;
    result = funcByVal(x);
    cout << "funcByVal() returns " << result << " and x is still " << x <<endl;
    
    // x pased by reference, so it is changed by the function
    cout << "x before calling funcByRef(): " << x << endl;
    result = funcByRef(x);
    cout << "funcByRef() returns " << result << " and x was changed to " << x <<endl;
}
