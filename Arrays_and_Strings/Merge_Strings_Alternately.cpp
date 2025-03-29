/* EXERCISE TEXT
You are given two strings word1 and word2. 
Merge the strings by adding letters in alternating order, starting with word1. 
If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.


Example 1:
    Input: word1 = "abc", word2 = "pqr"
    Output: "apbqcr"
    Explanation: The merged string will be merged as so:
    word1:  a   b   c
    word2:    p   q   r
    merged: a p b q c r

Example 2:
    Input: word1 = "ab", word2 = "pqrs"
    Output: "apbqrs"
    Explanation: Notice that as word2 is longer, "rs" is appended to the end.
    word1:  a   b 
    word2:    p   q   r   s
    merged: a p b q   r   s

Example 3:
    Input: word1 = "abcd", word2 = "pq"
    Output: "apbqcd"
    Explanation: Notice that as word1 is longer, "cd" is appended to the end.
    word1:  a   b   c   d
    word2:    p   q 
    merged: a p b q c   d
 
Constraints:
    1 <= word1.length, word2.length <= 100
    word1 and word2 consist of lowercase English letters.
*/

#include <iostream>
#include <string>

using namespace std;

string mergeAlternately(string& word1, string& word2) {
    string merged;
    int len1 = word1.size();
    int len2 = word2.size();
    
    // Reserve enough space for the merged string upfront
    merged.reserve(len1 + len2);
    
    int i = 0, j = 0;
    
    // Merge characters from both strings alternately
    while (i < len1 && j < len2) {
        merged.push_back(word1[i++]);
        merged.push_back(word2[j++]);
    }

    // Append remaining characters from word1 if any
    if (i < len1) {
        merged.append(word1.substr(i));
    }

    // Append remaining characters from word2 if any
    if (j < len2) {
        merged.append(word2.substr(j));
    }

    return merged;
}

int main(){
    string word1 = "abc", word2 = "pqr";
    cout << mergeAlternately(word1, word2);
}