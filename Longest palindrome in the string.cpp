#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;
/*
to find the longest palindrome in the entered string
the longestPalindrome function gets the line and sends the sub string to isPalindrome function
to check whether the string is a palindrome or not
The longest palindrome string stores the palindrome string which has the maximum length
the longestPalindrome function returns the longestPalindrome
If the returned string is of length is greater than 1 it is printed else there is no palindrome in the entered string
*/

int isPalindrome(string);

string longestPalindrome(string palindrome)
{
    string longest_Palindrome;
    int i,j;

    for(i = 0; i < palindrome.length(); i++)
    {
        for(j = i+1; j <= palindrome.length(); j++)
        {
            string sub_str = palindrome.substr(i,j-i);

            longest_Palindrome = isPalindrome(sub_str) && sub_str.length() > longest_Palindrome.length() ? sub_str : longest_Palindrome;
        }
    }

    return longest_Palindrome;
}

int isPalindrome(string str)
{
    int n = str.length();

    int i;
    for(i = 0; i < n/2; i++)
    {
        if(str[i] != str[n-i-1])
            return 0;
    }
    return 1;
}



int main()
{
    string str_palindrome;

    cout<<"Enter the string: ";
    getline(cin , str_palindrome);

    string longest_Palindrome = longestPalindrome(str_palindrome);

    if(longest_Palindrome.length() > 1)
        cout<<"The longest Palindrome in the entered string is "<<longest_Palindrome<<endl;
    else
        cout<<"There is no palindromes present in the entered string."<<endl;

    return 0;
}
