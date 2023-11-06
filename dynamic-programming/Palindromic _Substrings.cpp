// Given a string A consisting of only lowercase English letters.
// Return the number of substrings of A which are palindrome
int Solution::solve(string s) {
    int n=s.size();
    //conditions for substring of s[i..j] to be a palindrome
    //1. s[i]==s[j]
    //2. s[i+1..j-1] is a palindrome 
    //2nd condition mai dp kaam aa jayega apne
    //to find is substring of length 3 is palindrome or not,we need to know about all 
    //substrings of length 2 and so on
    vector<vector<bool>>dp(n,vector<bool>(n,false));
    //dp[i][j]=true means s[i..j] is a palindrome 
    //all strings of 1 are palindrome; also handle length 2 separately
    int count=0;//apna ans i.e number of palindromic substrings
    for(int i=0;i<n;i++){
        dp[i][i]=true;
        count++;
        if(i<n-1 && s[i]==s[i+1]){
            count++;
            dp[i][i+1]=true;
        }
    }
    //now start checking from length 3 substrings 
    for(int gap=2;gap<=n-1;gap++){
        for(int i=0;i<n;i++){
            //i is the start of substr to be checked 
            int j=i+gap;//j is the end index ; if gap=2 means substr of length 3 and so on 
            if(j>=n) break;
            if(s[i]==s[j] && dp[i+1][j-1]==true){
                dp[i][j]=true;
                count++;
            }
        }
    } 
    return count;
}
