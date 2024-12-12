
data Shape a = Circle a | Rectangle a a | Triangle a a a | Cylinder a a 
 deriving (Show, Eq, Read, Ord)

f :: String -> Shape Int
f = read

main = do
    print $ Circle 5
    print $ Triangle 1 2 3 
    print $ Circle 3 == Circle 2
    print $ Rectangle 5 4 == Rectangle 5 4
    print $ f "Circle 6" == Circle 6
    print $ Cylinder 1 2 > Cylinder 0 4
