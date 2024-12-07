
isImage :: (Num a, Ord a) => [a] -> [a] -> (Bool, a)
isImage xs ys = 
    let
        n = head ys - head xs
        res = all (==n) [ y - x  | (x,y) <- zip xs ys ]
    in (res, if res then n else 0)

main = do
    print $ isImage [1, 2, 3, 4] [2, 3, 4, 5] == (True, 1)
    print $ isImage [1, 2, 3, 4] [4, 5, 6, 7] == (True, 3)
    print $ isImage [4, 5, 6, 7] [1, 2, 3, 4] == (True, -3)
    print $ isImage [1, 2, 3, 4] [4, 5, 6, 6] == (False, 0)
    print $ isImage [1, 2] [-1, -2] == (False, 0)
    print $ isImage [1, 2, 3, 4] [2, 3, 4, 4] == (False, 0)
    print $ isImage [2, 4, 6, 8] [4, 6, 8, 10] == (True, 2) -- my test