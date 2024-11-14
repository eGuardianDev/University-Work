
sumOfDivisors :: Int -> Int
sumOfDivisors n = helper n (n-1) 0
 where 
    helper :: Int -> Int -> Int -> Int
    helper n 0 sum = sum
    helper n current sum = 
        if mod n current == 0 
            then helper n (current - 1) (sum + current) 
            else helper n (current - 1) sum

areAmicable :: Int -> Int -> Bool
areAmicable x y = sumOfDivisors x  == y && sumOfDivisors y == x




main = do
    print $ areAmicable 200 300 == False
    print $ areAmicable 220 284 == True
    print $ areAmicable 284 220 == True
    print $ areAmicable 1184 1210 == True
    print $ areAmicable 2620 2924 == True
    print $ areAmicable 6232 6368 == True
    print $ areAmicable 123 45 == False -- my test

