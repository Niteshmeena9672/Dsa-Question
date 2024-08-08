/*
### Notes for the Problem: **151. Reverse Words in a String**

#### **Problem Overview**
- **Objective:** Given an input string `s`, the goal is to reverse the order of the words in the string.
- **Definition of a Word:** A word is defined as a sequence of non-space characters.
- **Constraints:**
  - Words in the string are separated by at least one space.
  - The output should be a string where the words are in reverse order and separated by a single space.
  - The returned string should not include leading, trailing, or multiple spaces between words.

#### **Examples**
1. **Input:** `s = "the sky is blue"`
   - **Output:** `"blue is sky the"`

2. **Input:** `s = "  hello world  "`
   - **Output:** `"world hello"`
   - **Explanation:** The reversed string should not contain leading or trailing spaces.

3. **Input:** `s = "a good   example"`
   - **Output:** `"example good a"`
   - **Explanation:** Multiple spaces between two words should be reduced to a single space.

#### **Constraints**
- **Length of the String `s`:** `1 <= s.length <= 10^4`
- **Characters in the String:** The string contains English letters (both upper-case and lower-case), digits, and spaces `' '`.
- **There is at least one word in the string.**

#### **Solution Explanation**
The solution uses a straightforward approach to reverse the words in the string by iterating through the input string and building the result.

**Code Breakdown:**
*/
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();  // Get the size of the string
        int i = 0;  // Initialize the index for iteration
        string ans = "";  // Initialize the final answer string
        
        // Iterate through the string
        while(i < n) {
            string temp = "";  // Temporary string to store the current word
            
            // Skip any leading spaces
            while(s[i] == ' ' && i < n) {
                i++;
            }
            
            // Collect characters of the current word
            while(s[i] != ' ' && i < n) {
                temp += s[i];
                i++;
            }
            
            // Add the word to the final answer string in reverse order
            if(temp.size() > 0) {
                if(ans.size() == 0) {
                    ans = temp;  // If ans is empty, assign the first word
                } else {
                    ans = temp + ' ' + ans;  // Otherwise, prepend the word
                }
            }
        }
        
        return ans;  // Return the reversed words as a single string
    }
};
/*

**Explanation:**
1. **Initial Setup:**
   - The function initializes the variables `n` (size of the string), `i` (index for iteration), and `ans` (string to store the final result).

2. **Iterating Over the String:**
   - The outer `while` loop runs through the string until the end.
   - The inner `while` loops:
     - **First Loop:** Skips any leading spaces.
     - **Second Loop:** Collects characters of a word and appends them to `temp`.

3. **Constructing the Reversed String:**
   - If `temp` contains a word:
     - If `ans` is empty (this is the first word), assign `temp` to `ans`.
     - If `ans` already has words, prepend the new word (with a space) to `ans`.

4. **Return the Result:**
   - The function returns the string `ans`, which contains the words in reverse order.

#### **Key Points**
- **Efficiency:** The code runs in O(n) time complexity where `n` is the length of the string. This is efficient given the constraints.
- **In-Place Follow-Up:** If you need to solve this problem in-place (i.e., without using extra space), you would need to carefully manage the characters in the string and avoid using additional strings like `ans` or `temp`.

#### **Real-World Application**
- This type of string manipulation is common in text processing tasks, such as reversing the order of words in a sentence, which is useful in formatting tools, natural language processing, and command-line utilities.

By understanding and solving this problem, you build foundational skills for more complex string manipulation tasks.
*/