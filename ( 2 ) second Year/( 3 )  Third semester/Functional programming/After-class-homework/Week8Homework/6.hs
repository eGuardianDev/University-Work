import Data.List



sumUnique :: [[Int]] -> Int
sumUnique xs = sum $ concat $ concatMap (filter (\x -> length x == 1). group . sort) xs

main = do
    print $ sumUnique [[1,2,3,2],[1,-4],[1]] == 2
    print $ sumUnique [[1,2,3,2],[-4,-4],[5]] == 9
    print $ sumUnique [[2,2,2],[3,3,3],[4,4,4]] == 0
    print $ sumUnique [[1,2,3],[4,5,6],[7,8,9]] == 45   
    print $ sumUnique [[1,1,1],[0,1,2],[1,0,1]] == 3 -- my test