#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    static int longestPalindrome(string& s) {
        int freq[58]; //'A'=64~'z'=122
        memset(freq, 0, sizeof(freq));
        for(char c: s) freq[c-'A']++;

        int len = 0; // lenght of palindrome
        bool hasOdd = 0;
        for(int f: freq){
            if ((f&1)==0) len+=f; // if f is even number
            else{ // if f is odd number
                len += (f-1);
                hasOdd = 1;
            }
        }
        return len+hasOdd;
    }
};