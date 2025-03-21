
isInsideNoLists :: Int -> Int -> Int -> Bool
isInsideNoLists start end x = min start end <= x && x <= max start end

isInsideLists :: Int -> Int -> Int -> Bool
isInsideLists start end x = x `elem` [min start end .. max start end]

isInsideLambda :: Int -> Int -> (Int -> Bool)
isInsideLambda start end = (\ x ->  x `elem` [ min start end .. max start end])


main = do
    print $ isInsideNoLists 5 1 4 == True -- start, end, x
    print $ isInsideNoLists 10 50 20 == True
    print $ isInsideNoLists 10 50 1 == False

    print $ isInsideLists 5 1 4 == True
    print $ isInsideLists 10 50 20 == True
    print $ isInsideLists 10 50 1 == False

    print $ (isInsideLambda 5 1) 4 == True
    print $ (isInsideLambda 10 50) 20 == True
    print $ (isInsideLambda 10 50) 1 == False