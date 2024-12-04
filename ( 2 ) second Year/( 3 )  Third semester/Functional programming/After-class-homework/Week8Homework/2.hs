
import Data.Char

containsDigit :: Int -> Int -> Bool
containsDigit x y = elem (chr (y+48)) $ show x 

checkIfPrime :: Int -> Bool
checkIfPrime x = [1,x] == [y | y<-[1..x], mod x y == 0] 

sumSpecialPrimes :: Int -> Int -> Int
sumSpecialPrimes 0 d = 0
sumSpecialPrimes n d = helper 2 n d
 where 
    helper :: Int->Int->Int->Int
    helper _ 0 _ = 0
    helper curr count digit
     | checkIfPrime curr && containsDigit curr digit = curr + helper (curr+1) (count-1) digit
     | otherwise = helper (curr+1) count digit

main = do
    print $ sumSpecialPrimes 5 2 == 392
    print $ sumSpecialPrimes 5 3 == 107
    print $ sumSpecialPrimes 10 3 == 462
    print $ sumSpecialPrimes 3 2 == 54 -- my test