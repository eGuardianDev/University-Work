
type Tuple a = (a,a)

combine :: (Num a, Ord a ) => [Tuple a] -> Tuple a
combine [] = error "Cannot pass empty list"
combine xs = helper (0,0) xs
 where 
    helper :: (Num a, Ord a ) => Tuple a -> [Tuple a] -> Tuple a
    helper res [] = res
    helper (x,y) ((x1,y1):curr) = helper (x*10+ min x1 y1, y*10 + max x1 y1) curr  

main = do
    print $ combine [(1, 2), (1, 2)] == (11, 22)
    print $ combine [(3, 9), (8, 7), (7, 9), (8, 8), (5, 0), (9, 2)] == (377802, 989859)