import Data.List

getDivisors :: (Enum a, Integral a) => a -> [a]
getDivisors n = [x |x <- [1..n-1], mod n x == 0]


naturalProduct :: (Integral a) => [a] -> a -> a
naturalProduct xs divisor =
    let res = filter (\x -> mod (sum $ getDivisors x) divisor == 0 ) (filter (>0) xs)
    in if null res then 0 else product res

main = do
    print $ naturalProduct [-1, 0, -2, -3] 5 == 0 -- There are no natural numbers
    print $ naturalProduct [5, 10] 5 == 0 -- Sum of the divisors for 5 is 1 and for 10 is 1+2+5=8
    print $ naturalProduct [95, 75, 15, 55, 11, 14, 18, 35, 25] 5 == 1330
    print $ naturalProduct [10, 20, 5, 1] 5 == 1 -- my test
