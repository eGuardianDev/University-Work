

isImage :: [Int] -> [Int] -> Bool
isImage xs ys =  ys == map (\x-> x - head xs + head ys) xs

main = do
    print $ isImage [] [] == True
    print $ isImage [1, 2, 3] [2, 3, 4] == True
    print $ isImage [1, 2, 3] [4, 6, 9] == False
    print $ isImage [1, 2, 3] [2, 5, 4] == False