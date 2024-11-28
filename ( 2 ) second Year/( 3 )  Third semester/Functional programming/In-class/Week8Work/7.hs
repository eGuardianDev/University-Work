
pack :: [Int] -> [[Int]]
pack (x:xs) = map reverse (helper [x] xs)
 where 
    helper :: [Int] -> [Int] -> [[Int]]
    helper xs [] = [xs]
    helper (x:xs) (y:ys) 
     | x + 1 == y = helper (y:x:xs) ys  
     | otherwise = (x:xs) : helper [y] ys



main = do
    print $ pack [1, 2, 3, 7, 8 ,9] == [[1,2,3],[7,8,9]]
    print $ pack [1, 7, 8 ,9] == [[1],[7,8,9]]
    print $ pack [1, 9] == [[1],[9]]