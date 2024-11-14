
myGcdG :: Int -> Int -> Int
myGcdG x y
 | x == 0 = y   
 | y == 0 = x
 | otherwise = myGcdG y (mod x y)

myGcdPM :: Int -> Int -> Int
myGcdPM x y = helper x y
 where 
    helper x 0 = x
    helper 0 y = y
    helper x y = helper y (mod x y)


main :: IO ()
main = do
    print $ myGcdG 5 13 == 1
    print $ myGcdG 13 1235 == 13
    print $ myGcdG 20 180 == 20 -- my test

    print $ myGcdPM 5 13 == 1
    print $ myGcdPM 13 1235 == 13
    print $ myGcdPM 20 180 == 20 -- my test
