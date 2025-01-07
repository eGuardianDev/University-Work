
import Data.List

data Shape a = Circle a | Rectangle a a | Triangle a a a | Cylinder a a 
 deriving (Show, Eq, Read, Ord)

area :: Shape Float -> Float
area (Circle r) = r*r* pi
area (Cylinder r h) = 2*pi*r*h + 2*pi*r*r
area (Rectangle w h) = w*h 
area (Triangle a b c) =
    let s = (a + b + c)/2
    in  sqrt (s * (s-a)*(s-b)*(s-c))

getAreas :: [Shape Float] -> [Float]
getAreas = map area 

maxArea :: [Shape Float] -> Shape Float
maxArea = foldr1 (\x y -> if area x >= area y then x else y)


main = do
    print $ getAreas [Circle 5, Rectangle 2.5 4.5, Rectangle 5.5 20.6, Triangle 5.3 3.9 4.89, Cylinder 20 30] == [78.53981633974483,11.25,113.30000000000001,9.127927385194024,6283.185307179587]
    print $ maxArea [Circle 5, Rectangle 2.5 4.5, Rectangle 5.5 20.6, Triangle 5.3 3.9 4.89, Cylinder 20 30] == Cylinder 20.0 30.0


    print $ getAreas [Circle 2, Rectangle 4 2, Triangle 3 2 3] == [12.566371,8.0,2.828427] -- my test
    print $ maxArea [Circle 2, Rectangle 4 2, Triangle 3 2 3] == Circle 2.0 -- my test
