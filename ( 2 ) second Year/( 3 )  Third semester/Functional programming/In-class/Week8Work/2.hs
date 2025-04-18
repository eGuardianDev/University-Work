
addOneXsPA :: (Num a) => [a] -> [a]
addOneXsPA = map (+1)  
addOneNPA :: (Num a) => a -> a
addOneNPA = (+1)
sqPlusOne :: (Num a) => a -> a
sqPlusOne = (+1).(^2)

main = do
    print $ addOneXsPA [1, 2, 3, 4, 5] == [2, 3, 4, 5, 6]
    print $ addOneNPA 5 == 6
    print $ sqPlusOne 5 == 26