
type Vector a = (a,a,a)

crossProduct :: (Num a) => Vector a -> Vector a -> Vector a
crossProduct (a1,a2,a3) (b1,b2,b3) = ( a2*b3-a3*b2, a3*b1-a1*b3, a1*b2-a2*b1)

magnitude :: (Floating a) => Vector a -> a
magnitude (x,y,z) = sqrt ( x^2 +y^2 +z^2)

main = do 
    print $ crossProduct (1, 2, 3) (7, 4, 1) == (-10, 20, -10)
    print $ crossProduct (5, 2, 159) (0, -1, -2) == (155, 10, -5)
    print $ crossProduct (1,2,3) (3,4,5) == (-2, 4, -2) -- my test

    print $ magnitude (1, 2, 3) == 3.7416573867739413
    print $ magnitude (7, 4, 1) == 8.12403840463596
    print $ magnitude (-10, 20, -10) == 24.49489742783178
    print $ magnitude (5, 2, 159) == 159.0911688309568
    print $ magnitude (0, -1, -2) == 2.23606797749979
    print $ magnitude (155, 10, -5) == 155.40270267920053
    print $ magnitude (-2, 4, -2) == 4.898979485566356 -- my test