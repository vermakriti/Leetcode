/*

Company - Facebook,Adobe,Microsoft,Google,Snapchat,Amazon,Oracle,Wayfair

Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

 

Example 1:

Input: num1 = "11", num2 = "123"
Output: "134"
Example 2:

Input: num1 = "456", num2 = "77"
Output: "533"
Example 3:

Input: num1 = "0", num2 = "0"
Output: "0"
 

Constraints:

1 <= num1.length, num2.length <= 104
num1 and num2 consist of only digits.
num1 and num2 don't have any leading zeros except for the zero itself.

*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        
        string output="";
        int i=num1.size()-1,j=num2.size()-1,carry=0;
        
        while(i>=0 && j>=0){
            int n1=num1[i]-'0';
            int n2=num2[j]-'0';
            int add=(n1+n2+carry)%10;
            carry=(n1+n2+carry)/10;
            output+=to_string(add);
            i--;
            j--;
        }
        while(i>=0){
            int n1=num1[i]-'0';
            int add=(n1+carry)%10;
            carry=(n1+carry)/10;
            output+=to_string(add);
            i--;
        }
        while(j>=0){
            int n2=num2[j]-'0';
            int add=(n2+carry)%10;
            carry=(n2+carry)/10;
            output+=to_string(add);
            j--;
        }
        if(carry)
             output+=to_string(carry);
        reverse(output.begin(),output.end());
        return output;
    }
};

/* 
TC- max(string1.length,string2.length) + O(N)-reversing the output
SC-O(1)

*/