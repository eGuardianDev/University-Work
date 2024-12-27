

myPoly :: (Num a) => [a] -> (a-> Int -> a)
myPoly arr = \x y -> product $ map (x-) $ take y arr


main = do
    print $ myPoly [2.7, 3.0 ..] 2.2 3 == -0.4399999999999998
    print $ myPoly [2.7, 3.0 ..] 2.2 4 == 0.6159999999999994 -- my test