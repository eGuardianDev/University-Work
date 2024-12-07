

removeAll :: (Num a, Ord a) => a -> [a] ->[a]
removeAll x xs = [el | el <-xs, el /= x]

removeAllHOF :: (Num a, Ord a) => a -> [a] ->[a]
removeAllHOF x = filter (/= x)

main = do
    print $ removeAll 5 [5] == []
    print $ removeAll 4 [4, 4] == []
    print $ removeAll 5 [1] == [1]
    print $ removeAll 5 [5, 1, 5, 3, 5] == [1, 3]
    print $ removeAll 3 [5, 1, 5, 3, 5] == [5, 1, 5, 5]
    print $ removeAll 1 [5, 1, 5, 3, 5] == [5, 5, 3, 5] -- my test

    print $ removeAllHOF 5 [5] == []
    print $ removeAllHOF 4 [4, 4] == []
    print $ removeAllHOF 5 [1] == [1]
    print $ removeAllHOF 5 [5, 1, 5, 3, 5] == [1, 3]
    print $ removeAllHOF 3 [5, 1, 5, 3, 5] == [5, 1, 5, 5]
    print $ removeAllHOF 1 [5, 1, 5, 3, 5] == [5, 5, 3, 5] -- my test
