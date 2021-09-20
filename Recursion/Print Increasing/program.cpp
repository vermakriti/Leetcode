/*

1. You are given a positive number n. 
2. You are required to print the counting from 1 to n.
3. You are required to not use any loops. Complete the body of print Increasing function to achieve it. Don't change the signature of the function.

*/

#include<iostream>
using namespace std;

void printIncreasing(int n){
    if(n==0)
        return;
    printIncreasing(n-1);
    cout<<n<<"\n";
}


int main(){
    int n; 
    cin>>n;
    printIncreasing(n);
}
