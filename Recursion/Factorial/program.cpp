/*

1. You are given a number n.
2. You are required to calculate the factorial of the number. Don't change the signature of factorial function.

Note -> The online judge can't force you to write the function recursively but that is what the spirit of question is.Write recursive and not iterative logic. The purpose of the question is to aid learning recursion and not test you.


*/

#include<iostream>
using namespace std;

int factorial(int n){
    if(n<=1)
        return 1;
    return n*factorial(n-1);    
    
}

int main(){
    int n; cin>>n;
    cout<<factorial(n);
}
