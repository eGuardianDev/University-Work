type Rat a = (a,a)

fixRat :: (Integral a, Ord a)=> Rat a -> Rat a
fixRat (x,y) = (div x  theGcd, div y theGcd)
    where 
        theGcd = gcd x y

sumRats :: (Integral a,Ord a) => Rat a-> Rat a -> Rat a
sumRats (x1,x2) (y1,y2) = fixRat (x1*y2 + x2*y1, x2*y2) 

multiplyRats :: (Integral a,Ord a) => Rat a-> Rat a -> Rat a
multiplyRats (x1,x2) (y1,y2) = fixRat (x1*y1, x2*y2) 

divideRats :: (Integral a,Ord a) => Rat a-> Rat a -> Rat a
divideRats (x1,x2) (y1,y2) = fixRat (x1*y2, x2*y1 )

areEqual :: (Integral a,Ord a) => Rat a-> Rat a -> Bool
areEqual x y = fixRat x == fixRat y
main = do
    print $ sumRats (2, 5) (5, 2) == (29, 10)
    print $ sumRats (52, 123) (96, 14) == (6268, 861)
    print $ sumRats (2, 5) (3, 5) == (1, 1)
    print $ sumRats (1, 4) (4, 4) == (5, 4) -- my test

    print $ multiplyRats (2, 5) (5, 2) == (1, 1)
    print $ multiplyRats (52, 123) (96, 14) == (832, 287)
    print $ multiplyRats (2, 5) (3, 5) == (6, 25)
    print $ multiplyRats (1, 4) (4, 4) == (1,4) -- my test

    print $ divideRats (2, 5) (5, 2) == (4, 25)
    print $ divideRats (52, 123) (96, 14) == (91, 1476)
    print $ divideRats (2, 5) (3, 5) == (2, 3)
    print $ divideRats (1, 4) (4, 4) == (1, 4) -- my test

    print $ areEqual (2, 5) (5, 2) == False
    print $ areEqual (52, 123) (52 * 3, 123 * 3) == True
    print $ areEqual (2, 6) (5, 15) == True
    print $ areEqual (4, 4) (5, 5) == True -- my test
