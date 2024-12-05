


rf :: (Num a, Ord a) => (a -> a) -> (a -> a) -> ([a]-> (a->a) -> [a])
rf f g  = (\ xs fun -> map fun [ x | x <- xs, (f x)>(g x)] )


main = do
    print $ (rf ((-) (-4)) (* (-2))) [1..10] (*3)  == [15,18,21,24,27,30] 
    -- only 5, 6, 7, 8, 9 and 10 satisfy the condition