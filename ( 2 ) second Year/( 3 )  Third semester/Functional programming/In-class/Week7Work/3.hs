
factXs :: Int -> Int
factXs n = product [1 .. n]

factIter :: Int -> Int
factIter n
 | n < 0 = error "n must be non negative"
 | otherwise = helper 1 n
 where
    helper :: Int -> Int -> Int
    helper result 0 = result
    helper result leftover = helper (result * leftover) (leftover - 1) 

factRec :: Int -> Int
factRec n
 | n < 0 = error "n must be non negative"
 | otherwise = helper n
 where 
    helper :: Int -> Int
    helper 0 = 1
    helper n = n * helper (n - 1)




main = do
    print $ factRec 11 == 39916800
    print $ factIter 11 == 39916800
    print $ factXs 11 == 39916800