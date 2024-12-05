

isPresent :: (Eq a, Num a) => a -> [a] -> Bool
isPresent _ [] = False
isPresent a (x:xs) = (a == x) || isPresent a xs

main = do
    print $ isPresent 0 [0, -1, 2] == True
    print $ isPresent 1 [0, 1, 2] == True
    print $ isPresent 2 [0, 1, -2] == False
    print $ isPresent 3 [0, 1, 2] == False
    print $ isPresent 4 [0, 1, 2] == False