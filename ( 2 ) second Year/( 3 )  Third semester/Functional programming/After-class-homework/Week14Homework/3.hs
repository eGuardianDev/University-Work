

numAdvance :: (Ord a, Num a) => Int -> ([a] -> Int)
numAdvance k = (\xs -> let num = xs !! (k-1) in length $ filter (\x -> x >= num && x > 0) xs )

main = do
    print $ (numAdvance 5) [10, 9, 8, 7, 7, 7, 5, 5] == 6
    print $ (numAdvance 2) [0, 0, 0, 0] == 0
    print $ (numAdvance 3) [10, 9, 8, 7, 7, 7, 5, 5] == 3
    print $ (numAdvance 1) [10, 9, 8, 7, 7, 7, 5, 5] == 1
    print $ (numAdvance 2) [10, 9, 8, 7, 7, 7, 5, 5] == 2
    print $ (numAdvance 9) [5, 5, 5, 3, 3, 3, 0, 0, 0, 0] == 6
    print $ (numAdvance 10) [5, 5, 5, 3, 3, 3, 0, 0, 0, 0] == 6