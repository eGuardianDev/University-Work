

type Vector a = (a,a,a)

sumVectors :: (Num a) => Vector a -> Vector a -> Vector a
sumVectors (a,b,c) (d,f,g) = (a+d,b+f,c+g)

scaleVector :: (Num a) => Vector a -> a -> Vector a
scaleVector (a,b,c) x = (a*x, b*x, c*x)

dotProduct :: (Num a) => Vector a -> Vector a -> a
dotProduct (a,b,c) (d,f,g) = a*d + b*f + c*g 
main = do
    print $ sumVectors (1, 2, 3) (4, 5, 6) == (5, 7, 9)
    print $ sumVectors (0, 0, 0) (100, 200, -300) == (100, 200, -300)

    print $ scaleVector (1, 2, 3) 5 == (5, 10, 15)
    print $ scaleVector (5, 2, 159) (-2) == (-10, -4, -318)

    print $ dotProduct (1, 2, 3) (7, 4, 1) == 18
    print $ dotProduct (5, 2, 159) (0, -1, -2) == -320