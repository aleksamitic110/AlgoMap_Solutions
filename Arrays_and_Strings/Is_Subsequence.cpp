/*EXERCISE TEXT
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none)
of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
    Input: s = "abc", t = "ahbgdc"
    Output: true

Example 2:
    Input: s = "axc", t = "ahbgdc"
    Output: false
 

Constraints:
    0 <= s.length <= 100
    0 <= t.length <= 104
    s and t consist only of lowercase English letters.
*/

#include <iostream>
#include <string>

using namespace std;

bool isSubsequence(string subsequence, string testString) {

    int j = 0;

    if (subsequence.length() == testString.length())
        if (subsequence == testString)
            return true;
        else
            return false;

    if (subsequence.length() > testString.length())
        return false;

    for (int i = 0; i < subsequence.length(); i++){
        bool isLetterThere = false;

        for (; j < testString.length(); j++){

            if (subsequence[i] == testString[j]){
                isLetterThere = true;
                j++;
                break;
            }
        }

        if (isLetterThere)
            continue;
        else
            return false;
    }

    return true;
}



int main(){
    string subSequence = "ABCD";
    string testString = "BGCABCEF";
    cout << isSubsequence(subSequence, testString);
}