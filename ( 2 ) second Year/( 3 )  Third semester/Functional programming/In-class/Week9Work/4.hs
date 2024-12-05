

divideNoPM :: Integral b => (b,b) -> (b,b)
divideNoPM tuple = (div (fst tuple) (snd tuple), mod (fst tuple) (snd tuple))


dividePM :: (Integral a) => (a,a) -> (a,a)
dividePM (x,y) = (div x y,mod x y)
main = do
    print $ divideNoPM (10, 5) == (2, 0) -- 10 / 5 = 2 and 10 % 5 = 0
    print $ divideNoPM (69, 42) == (1, 27)

    print $ dividePM (10, 5) == (2, 0)
    print $ dividePM (69, 42) == (1, 27)

    print $ (\(x,y) ->  (div x y,mod x y)) (10, 5) == (2, 0)
    print $ (\(x,y) ->  (div x y,mod x y))  (69, 42) == (1, 27)