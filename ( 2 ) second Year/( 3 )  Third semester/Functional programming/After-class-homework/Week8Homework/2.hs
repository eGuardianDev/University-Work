
import Data.Char

containsDigit :: Int -> Int -> Bool
containsDigit x y = elem (chr (y+48)) $ show x 

sumSpecialPrimes :: Int -> Int -> Int
sumSpecialPrimes 0 d = 0
sumSpecialPrimes n d
 | containsDigit d = 

-- print $ sumSpecialPrimes 5 2 == 392
-- print $ sumSpecialPrimes 5 3 == 107
-- print $ sumSpecialPrimes 10 3 == 462