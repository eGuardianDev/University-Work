
toTuples :: (Num a) => [a]->[a]->[(a,a)]
-- toTuples [] [] = []
-- toTuples (x:xs) [] = (x,0) : toTuples xs []
-- toTuples [] (y:ys) = (y,0) : toTuples [] ys
-- toTuples (x:xs) (y:ys) = (x,y) : toTuples xs ys
toTuples xs [] = zip xs (replicate (length xs) 0 )
toTuples [] ys = zip (replicate (length ys) 0 ) ys
toTuples (x:xs) (y:ys) = (x,y) : toTuples xs ys



main = do
    print $ toTuples [1, 2, 3, 4] [4, 3, 2, 1] == [(1, 4), (2, 3), (3, 2), (4, 1)]
    print $ toTuples [1.52, 2.75] [] == [(1.52, 0), (2.75, 0)]

