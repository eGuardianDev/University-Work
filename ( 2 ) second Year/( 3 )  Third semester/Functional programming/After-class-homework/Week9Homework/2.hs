

removeFirst :: (Num a, Eq a) => a -> [a] -> [a]
removeFirst _  [] = [] 
removeFirst el (x:xs)
 | el == x = xs
 | otherwise = x : removeFirst el xs 


main = do
    print $ removeFirst 5 [5, 1, 5, 3, 5] == [1, 5, 3, 5]
    print $ removeFirst 3 [5, 1, 5, 3, 5] == [5, 1, 5, 5]
    print $ removeFirst 1 [5, 1, 5, 3, 5] == [5, 5, 3, 5] -- my test