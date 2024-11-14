import Distribution.TestSuite (Test(Test))


hasIncDigits :: Int -> Bool
hasIncDigits n = helper n
    where 
        helper :: Int -> Bool
        helper 0 = True
        helper n
         | n < 10 = True
         | mod n 10 < (mod (div n 10) 10) = False
         | otherwise = helper (div n 10)


main = do
    print $ hasIncDigits 1244 == True
    print $ hasIncDigits 12443 == False 
    print $ hasIncDigits 1203 == False 