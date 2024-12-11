
type Tuple a = (a,a)

combine :: (Num a, Ord a ) => [Tuple a] -> Tuple a
combine [] = error "Cannot pass empty list"
combine xs = foldl (\(acc1,acc2) (x,y) -> (acc1*10 + x, acc2*10+y) ) (0,0) [(min x y, max x y) |(x,y)<-xs]

main = do
    print $ combine [(1, 2), (1, 2)] == (11, 22)
    print $ combine [(3, 9), (8, 7), (7, 9), (8, 8), (5, 0), (9, 2)] == (377802, 989859)
    print $ combine [(1, 4), (2, 5), (3, 6)] == (123, 456) -- my test