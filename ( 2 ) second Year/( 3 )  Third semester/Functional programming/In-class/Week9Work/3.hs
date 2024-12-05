

sumTupleNoPM :: (Num a) => (a,a) -> a
sumTupleNoPM tuple = fst tuple + snd tuple 

sumTuplePM :: (Num a) => (a,a) -> a
sumTuplePM (x,y) = x+y

main = do
    print $ sumTupleNoPM (4, 5) == 9
    print $ sumTupleNoPM (-5, 5) == 0

    print $ sumTuplePM (4, 5) == 9
    print $ sumTuplePM (-5, 5) == 0

    -- print $ ??? (4, 5) == 9
    -- print $ ??? (-5, 5) == 0