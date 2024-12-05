import Data.List

isSorted :: (Num a, Ord a) => [a] -> Bool
isSorted [] = True
isSorted [x] = True
isSorted (x:y:xs) = (x == y && isSorted (y:xs)) || (x < y && isSortedAsc (y:xs)) || (x > y && isSortedDesc (y:xs))
    where 
        isSortedAsc :: (Num a, Ord a) => [a] -> Bool
        isSortedAsc [] = True
        isSortedAsc [x] = True
        isSortedAsc (x:y:xs) = x <= y && isSortedAsc (y:xs)
        isSortedDesc :: (Num a, Ord a) => [a] -> Bool
        isSortedDesc [] = True
        isSortedDesc [x] = True
        isSortedDesc (x:y:xs) = x >= y && isSortedDesc (y:xs)


isSortedXs :: (Num a, Ord a) => [a] -> Bool
isSortedXs xs = (sort xs == xs ) || (reverse $ sort xs) == xs

main = do
    print $ isSorted [-5, -5, -6] == True
    print $ isSorted [-5, -5, -4] == True
    print $ isSorted [1, 1, 1, 1, 1, 1, 1, 1, 1] == True
    print $ isSorted [1, 2, 3, 3, 3, 4, 5, 6, 6] == True
    print $ isSorted [1, -1, -3, -3, -3, -4, -5, -6, -6] == True
    print $ isSorted [1, 2, 3, 3, 3, 4, 5, 6, 5] == False
    print $ isSorted [-100, -99, -99, -99] == True
    print $ isSorted [-100, -99, -99, -99, 100] == True
    print $ isSorted [100, 101, -102] == False
    print $ isSorted [1, 2, 3, 4, 5, 6] == True
    print $ isSorted [-1, -2, -3, -4, -5, -6] == True

    print $ isSortedXs [-5, -5, -6] == True
    print $ isSortedXs [-5, -5, -4] == True
    print $ isSortedXs [1, 1, 1, 1, 1, 1, 1, 1, 1] == True
    print $ isSortedXs [1, 2, 3, 3, 3, 4, 5, 6, 6] == True
    print $ isSortedXs [1, -1, -3, -3, -3, -4, -5, -6, -6] == True
    print $ isSortedXs [1, 2, 3, 3, 3, 4, 5, 6, 5] == False
    print $ isSortedXs [-100, -99, -99, -99] == True
    print $ isSortedXs [-100, -99, -99, -99, 100] == True
    print $ isSortedXs [100, 101, -102] == False
    print $ isSortedXs [1, 2, 3, 4, 5, 6] == True
    print $ isSortedXs [-1, -2, -3, -4, -5, -6] == True