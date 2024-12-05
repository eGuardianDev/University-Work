

type Rat a = (a,a) 
normalize :: (Integral a) => Rat a -> Rat a
normalize (x,y) = (div x highstCommDenom, div y highstCommDenom)
    where 
        highstCommDenom = gcd x y

main = do
    print $ normalize (4, 2) == (2, 1)
    print $ normalize (8, 4) == (2, 1)
    print $ normalize (2, 4) == (1, 2)