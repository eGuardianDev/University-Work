

isPerfect :: Int -> Bool
-- isPerfect n = helper 0 n 1 == n
--  where 
--     helper :: Int -> Int -> Int -> Int
--     helper sum n counter
--      | counter == n  = sum 
--      | mod n counter == 0 = helper (counter+sum) n (counter+1)
--      | otherwise = helper sum n (counter+1)
isPerfect n = n == sum [x | x <- [1..n-1], mod n x == 0]


main = do
    print $ isPerfect 1 == False
    print $ isPerfect 6 == True
    print $ isPerfect 495 == False
    print $ isPerfect 33550336 == True -- slow
    print $ isPerfect 8128 == True -- my test