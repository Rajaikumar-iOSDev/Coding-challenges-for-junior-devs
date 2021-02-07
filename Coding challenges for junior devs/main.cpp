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

// MARK:- Maximum sum of hour glass in matrix
///Declare properties
int array2D[5][5]={{1, 2, 3, 0, 0},
    {0, 0, 0, 0, 0},
    {2, 1, 4, 0, 0},
    {0, 0, 0, 0, 0},
    {1, 1, 0, 1, 0}};
int rows = 5;
int columns = 5;
///Find max sum of the hour glass
int maxSumOfHourGlassfor(int array[5][5])
{

    int maxSum = INT_MIN;
    for(int i=0;i<rows-2;i++){
        for (int j=0; j<columns-2; j++) {
            int sum = array[i][j]+array[i][j+1]+array[i][j+2]+array[i+1][j+2]+array[i+2][j]+array[i+2][j+1]+array[i+2][j+2];
            maxSum = max(maxSum,sum);
        }
    }

    return maxSum;
}

static void handleMaxSumOfHourGlass(){

    cout<<"Maximum sum of the hour glass : "<<maxSumOfHourGlassfor(array2D)<<"\n";
    handleChoice();
}

// MARK:- Find the biggest and smallest number in the array
///Find the smallest number
int findSmallest(int *array,long length){

    int smallestElement = array[0];
    for (int i=0;i<length;i++){
        if(array[i]<smallestElement){
            smallestElement=array[i];
        }
    }
    return smallestElement;
}
///Find the biggest number
int findBiggest(int *array, long length){
    int biggestElement = array[0];
    for(int i=0;i<length;i++){
        if (array[i]>biggestElement){
            biggestElement = array[i];
        }
    }
    return biggestElement;
}
///Handle input and output
static void handleFindtheBiggestAndSmallestNumber(){

    int array[5];

    cout<<"Enter integer numbers to create an array: ";
    for(int i=0;i<5;i++){
        cin>>array[i];
    }

    int length = *(&array+1) - array;

    cout<<"Biggest number in the given array is : "<<findBiggest(array, length)<<"\n";
    cout<<"Smallest number in the given array is : "<<findSmallest(array, length)<<"\n";
}
// MARK:- Driver functions
static void handleChoice() {
    int choice;
    cout<<"Welcome to the 'Junior dev - Coding interview Questions & Answers - Part 1' \n\n Please choose an option to proceed:\n\n Press '1' for Factorial \n Press '2' for Palindrome\n Press '3' for Max Sum Of Hour Glass\n Press '4' for Find the biggest and smallest number\n Press any other number to exit\n";
    cin>>choice;

    switch (choice) {
        case 1:
            handleFactorial();
            break;
        case 2:
            handlePalindrome();
            break;
        case 3:
            handleMaxSumOfHourGlass();
            break;
        case 4:
            handleFindtheBiggestAndSmallestNumber();
            break;
        default:
            break;
    }
}
int main() {
    handleChoice();
    return 0;
}
