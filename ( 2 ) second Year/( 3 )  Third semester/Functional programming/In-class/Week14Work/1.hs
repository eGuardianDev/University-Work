import Data.Char

numberToArray :: Int -> [Int]
numberToArray pos = map (\x -> ord x - 48 ) $ show pos

doMath :: Int -> Bool
doMath xs 
 | mod xs 10 == 0 = False
 | otherwise =  all odd $ numberToArray (xs + getReversedNum xs) 

getReversedNum :: Int -> Int
getReversedNum num = read $ reverse $ show num

reversibleNumbers :: Int -> [Int]
reversibleNumbers n = [x | x <- [1..n], doMath x  ]



main = do
    print $ reversibleNumbers 20 == [12,14,16,18]
    print $ reversibleNumbers 31 == [12,14,16,18,21,23,25,27]
    print $ reversibleNumbers 10 == []