// vector_ex1.cpp
//
// Shows multiple examples of using lambda expressions.  Refer to the inline
// comments for details.

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

// simply here for an example of the for_each function calling a regular function
// rather than a lambda.
void print(int n) {
    std::cout << n << "  ";
}

int main() {
    using namespace std;

    vector<int> v;

    // vector values for the lambda examples
    v.push_back(3);
    v.push_back(4);
    v.push_back(9);
    v.push_back(11);
    v.push_back(14);

    // for loop using begin and end methods (not a lambda)
    for (auto x = v.begin(); x != v.end(); x++) {
        cout << *x << "  ";
    }
    cout << endl;

    // using the for_each function with a regular function (print) for 
    // displaying output
    for_each(v.begin(), v.end(), print);
    cout << endl;
   
    // same as previous but using a lambda in place of function name 
    // note how it performs as an anonymous function call back
    for_each(v.begin(), v.end(), [] (int n) { cout << n << "  "; } );
    cout << endl;

    // an example of a multiple statement lambda
    for_each(v.begin(), v.end(), [] (int n) {
        if (n % 2 == 0)
            cout << setw(4) << n << "  Even" << endl;  
        else
            cout << setw(4) << n << "  Odd" << endl; } );

    // uses tranform which creates a new vector from the first using the
    // return value (the square of the values) from the lambda.  Note the return
    // value is not explictly provided since the compiler can figure it out.
    // The for_each function then uses another lamda to print the results
    vector<int> retV;
    transform(v.begin(), v.end(), back_inserter(retV), [](int n) { return n * n; } );
    for_each(retV.begin(), retV.end(), [] (int n) { cout << n << "  "; } );
    cout << endl;

    // same as before, but this time explicitly providing the return type of int
    vector<int> retV2;
    transform(v.begin(), v.end(), back_inserter(retV2), [](int n) -> int { return n * n; } );
    for_each(retV2.begin(), retV2.end(), [] (int n) { cout << n << "  "; } );
    cout << endl;

    // using capture values x & y from local scope to use within the lambda
    int x = 5;
    int y = 12;
    for_each(v.begin(), v.end(), [x,y] (int n) { 
        if ( n > x && n < y) 
            cout << n << "  "; } );
    cout << endl;

    // again capture values x & y from local scope to use within the lambda, but
    // because they are changed in the lambda it must be marked as mutable, but
    // because they are passed by value they are not changed outside the lambda.
    // The n value, which is the vector element being processed is returned by
    // reference, so the original vector is update.
    for_each(v.begin(), v.end(), [x,y] (int& n) mutable {
        x *= 2;  // will accumulate through multiple loops
        y *= 2;
        n *= x + y; } );
    cout << "x = " << x << "  y = " << y << endl;
    for_each(v.begin(), v.end(), [] (int n) { cout << n << "  "; } );
    cout << endl;

    // this time x & y are passed by reference so they are changed outside the 
    // lambda and since value local to the lamba itself aren't change the 
    // mutable keyword is not needed.  n continues to be returned by reference
    // so the vector values themselves are further updated.
    for_each(v.begin(), v.end(), [&x,&y] (int& n) {
        x *= 2;  // will accumulate through multiple loops
        y *= 2;
        n *= x + y; } );
    cout << "x = " << x << "  y = " << y << endl;
    for_each(v.begin(), v.end(), [] (int n) { cout << n << "  "; } );
    cout << endl;
}
