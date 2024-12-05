
import Data.Char

containsDigit :: Int -> Int -> Bool
containsDigit x y = elem (intToDigit y) $ show x 

checkIfPrime :: Int -> Bool
checkIfPrime x = [1,x] == [y | y<-[1..x], mod x y == 0] 

sumSpecialPrimes :: Int -> Int -> Int
sumSpecialPrimes n d = sum $ take n [x | x <-[2..], checkIfPrime x && containsDigit x d]
main = do
    print $ sumSpecialPrimes 5 2 == 392
    print $ sumSpecialPrimes 5 3 == 107
    print $ sumSpecialPrimes 10 3 == 462
    print $ sumSpecialPrimes 3 2 == 54 -- my test