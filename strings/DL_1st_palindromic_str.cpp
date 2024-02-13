class Solution {
// return first palindromic string in the array - reverse of char in the str is same
public:
/* A1: 2 pointer approach
TC: O(NM), N= no of strings in word, M = max length of str, worst case scenario - Max len str is in lastof word
SC: O(1); no recursion stack space bcz no recursion, iterative appraoch, calls check() for every str

Although the check function contains a return true or return false statement, it doesn't involve recursive calls. It's a simple iterative function that compares characters from both ends of the string to check if it's a palindrome. There is no recursion involved in this process.
*/

    bool check(string s){  // pass the string in word
    // checks if the word[i] - str is palindrome(return true) or not(return false)
        int i=0, j= s.size()-1;
        while(i<=j){
            if(s[i]==s[j]) i++, j--;    // if first & last char matches, then keep inc
            else return false;          // curr str not a palindrome
        }
        return true;                    // curr str is a palindrome
    }

// A1
    /*
    string firstPalindrome(vector<string>& words) {
        // loop for evry string in the vector word, i-> string
        for(int i=0; i<words.size();i++){
            if(check(words[i]))      // passing every string of word to check if palindrome or not
                return words[i];    // if ret true, then return the string
        }
        return "";
        }
    */


/* A2 - using REVERSE function
TC: O(NM), N= no of strings in word, M = max length of str, worst case scenario - Max len str is in lastof word
SC: O(1);
*/
    string firstPalindrome(vector<string>& words) {
    /* loop for evry string in the vector word, i-> string 
    reverse the curr string word[i] and check if same as str - palindrome*/
    for(int i=0; i<words.size();i++){
        string s = words[i];
        reverse(s.begin(),s.end());
        if(words[i] == s)      return words[i];    // then return the string
    }
    return "";
    }
};

/* ABOUT REVERSE FUNCTION
The reverse function is a built-in function in C++ that is used to reverse the order of elements in a container, such as a string or a vector. When you call reverse(beginIterator, endIterator), it reverses the elements in the range defined by the iterators beginIterator (inclusive) and endIterator (exclusive).

Here's how it works:
The beginIterator points to the beginning of the range, and the endIterator points to the element just beyond the end of the range.
It swaps the elements pointed to by the iterators, moving inward from both ends of the range until they meet in the middle.
After the function completes, the elements within the specified range are reversed.


The reverse function is available as part of the C++ Standard Library and is defined in the <algorithm> header. It operates on various containers such as strings, vectors, arrays, etc., 
    but it doesn't have its own data structure. Instead, it manipulates the elements of the container directly using iterators.
*/
