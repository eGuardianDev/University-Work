
isPrimeG :: Int -> Bool
isPrimeG n = helper n $ n-1
 where 
    helper :: Int -> Int -> Bool
    helper n leftover
     | n <= 1 = False
     | leftover < 2 = True
     | mod n leftover == 0 = False
     | otherwise = helper n $ leftover-1

isPrimeLC :: Int -> Bool
-- isPrimeLC n = if n <= 1 then False else length [x | x <- [2..n-1], mod n x == 0] == 0
isPrimeLC n = n > 1 && null [x | x <- [2..n-1], mod n x == 0]


main = do
    print $ isPrimeG 1 == False
    print $ isPrimeG 2 == True
    print $ isPrimeG 3 == True
    print $ isPrimeG 6 == False
    print $ isPrimeG 61 == True
    print $ isPrimeG 10 == False -- my test

    print $ isPrimeLC 1 == False
    print $ isPrimeLC 2 == True
    print $ isPrimeLC 3 == True
    print $ isPrimeLC 6 == False
    print $ isPrimeLC 61 == True
    print $ isPrimeLC 10 == False -- my test