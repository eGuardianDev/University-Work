

getEven :: [a]  -> [a]
getEven xs = helper xs True
    where 
        helper :: [a] -> Bool -> [a]
        helper [] _ = []
        helper (x:xs) bool
         | bool = x : helper xs False
         | otherwise = helper xs True

prodEvens:: (Num a) => [a] -> a
-- prodEvens = product . getEven
prodEvens  =  foldr (\(x,y) acc -> if even x then y * acc else acc) 1 . zip [0..] 


main = do
    print $ prodEvens [1,2,3,4,5,6] ==  15
    print $ prodEvens [7.66,7,7.99,7] ==  61.2034