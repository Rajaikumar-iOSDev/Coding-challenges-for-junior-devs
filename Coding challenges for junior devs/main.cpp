//
//  main.cpp
//  Junior dev - Coding interview Questions & Answers
//
//  Created by Rajai kumar on 04/02/21.
//

#include <iostream>

using namespace::std;
// MARK:- Declare Methods
static void handleChoice();
// MARK:- Factorial using recursion

int factorial(int n)
{
    if (n>1){
        return n*(n-1);
    }else{
        return 1;
    }
}

static void handleFactorial() {
    int n;
    cout<<"Enter a positive integer: ";
    cin>>n;
    cout << "Factorial of "<<n<<" is "<<factorial(n)<<"\n";
    handleChoice();
}

// MARK:- Palindrome
bool isPalindrome(const string &input, int start, long end){
    if (start>=end)
        return true;
    if (input[end]!=input[start])
        return false;
    return isPalindrome(input, ++start, --end);

}



static void handlePalindrome() {
    string input;
    cout<<"Enter a string to check whether its palindrome or not: ";
    cin>>input;
    cout<<"Is "<<input<<" a Palindrome, say 1 for true and 0 for false: \n Answer is "<<isPalindrome(input, 0, input.length()-1)<<"\n";
    handleChoice();
}



// MARK:- Driver functions
static void handleChoice() {
    int choice;
    cout<<"Welcome to the 'Junior dev - Coding interview Questions & Answers - Part 1' \n\n Please choose an option to proceed:\n\n Press '1' for Factorial \n Press '2' for Palindrome\n Press any other number to exit\n";
    cin>>choice;

    switch (choice) {
        case 1:
            handleFactorial();
            break;
        case 2:
            handlePalindrome();
            break;
        default:
            break;
    }
}
int main(int argc, const char * argv[]) {
    handleChoice();
    return 0;
}
