#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s) {
  // Initialize a hash map to store the characters and their positions
  unordered_map<char, int> char_pos;
  // Initialize variables to store the length of the longest substring and the starting position of the current substring
  int longest = 0, start = 0;

  // Iterate through the string
  for (int i = 0; i < s.size(); i++) {
    // If the current character has been seen before in the current substring, update the starting position of the current substring
    if (char_pos.count(s[i]) && start <= char_pos[s[i]]) {
      start = char_pos[s[i]] + 1;
    }
    // Update the position of the current character in the hash map
    char_pos[s[i]] = i;
    // Update the length of the longest substring if necessary
    longest = max(longest, i - start + 1);
  }

  return longest;
}

int main() {
  string s = "abcabcbb";
  cout << lengthOfLongestSubstring(s) << endl;
  return 0;
}
