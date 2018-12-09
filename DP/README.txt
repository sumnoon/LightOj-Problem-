# 1032 - digit dp. Use a three dimesional dp where func ( pos, cnt, prev, flag ) denotes pos = position, cnt = number of adjacent count,
prev = whether previosu value was 1 or 0 and flag = 1 than limit is digit[pos] else 1.
run a loop from 0 to limit 
if prev and i is 1 then increae cnt 1 otherwise keep as it is.
# 1159 - LCS extension for three strings
       Keep a dp[i][j][k] = dp[i-1][j-1][k-1] + 1 if (s1[i-1] == s2[j-1] == s3[k-1]) otherwise
              dp[i][j][k] = max (dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1])).

# 1037 - Bit mask DP. From every i check whether other can be killed with the help of others' weapon and minimize it. At last check whether killing with USA is minimizes it.
# 1217 - Basic DP. recurse such that you will start taking from first item or second item. And skip after each item. The recursion function will be like this,
              func ( pos, check ) = 0 if pos >= n
                                  = a[pos] if pos == n - 1 & first item is not taken
                                  = max ( a[pos] + func ( pos + 2, check ) , func ( pos + 1, check ) )
find maximum between func ( 0, 0 ) and func ( 1, 1 ).

#1060 - https://www.geeksforgeeks.org/find-n-th-lexicographically-permutation-string-set-2/

#1051 - think vowels as 0 and consonent as 1. Then find whether there can be three consecutive 0's or 5 consecutive 1's. DP states will be 
        1. pos - position of the character
        2. vowel_count - if consonent count increase vowel count will be zero
        3. consonent_count - if vowel count increase consonent count will be zero
        otherwise check both putting vowel and consonent.
