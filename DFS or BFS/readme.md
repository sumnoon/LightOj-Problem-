# 1046 - Basic 2d Graph traversal. Think every rider as 1- rider. Than update where they can traverse using this equation,
                                 cnt[i][j]  = ( dist[i][j] / k ) + ( dist[i][j] % k != 0 ) where
                                 dist[i][j] = distance from i to j using certain rider. thinking everyone is 1-rider. 
                                 k          = given in the statement
                                 cnt[i][j]  = count of distance if the rider is k-rider.
