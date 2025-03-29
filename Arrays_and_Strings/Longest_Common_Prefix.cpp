
/* EXERCISE TEXT
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
    Input: strs = ["flower","flow","flight"]
    Output: "fl"

Example 2:
    Input: strs = ["dog","racecar","car"]
    Output: ""
    Explanation: There is no common prefix among the input strings.
 

Constraints:
    1 <= strs.length <= 200
    0 <= strs[i].length <= 200
    strs[i] consists of only lowercase English letters if it is non-empty.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& words) {
    
    string out = "";
    string minSizedWord = words[0];

    for (int i = 1; i < words.size(); i++){
        if (words[i].length() < minSizedWord.length())
            minSizedWord = words[i];
    }

    for (int i = 0; i < minSizedWord.length(); i++){
        bool isPrefix = true;
        for (int j = 0; j < words.size(); j++){
            
            if (minSizedWord[i] != words[j][i]){
                isPrefix = false;
                break;
            }
        }
        if (isPrefix)
            out += minSizedWord[i];
        else
            break;
    }
    return out;
}

int main(){
    vector<string> words = {"flower","flow","flight"};
    cout << longestCommonPrefix(words);
}