1032 - digit dp. Use a three dimesional dp where func ( pos, cnt, prev, flag ) denotes pos = position, cnt = number of adjacent count,
prev = whether previosu value was 1 or 0 and flag = 1 than limit is digit[pos] else 1.
run a loop from 0 to limit 
if prev and i is 1 then increae cnt 1 otherwise keep as it is.
1159 - LCS extension for three strings
       Keep a dp[i][j][k] = dp[i-1][j-1][k-1] + 1 if (s1[i-1] == s2[j-1] == s3[k-1]) otherwise
              dp[i][j][k] = max (dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1])).
