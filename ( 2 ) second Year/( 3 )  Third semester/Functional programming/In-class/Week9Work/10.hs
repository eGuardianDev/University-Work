

checkRootLC :: (Eq a, Num a, Enum a) => [(a,a)] -> [Bool]
checkRootLC xs = [x*x == y |(x,y) <-xs] 


checkRootHOF :: (Eq a, Num a) => [(a,a)] -> [Bool]
checkRootHOF = map (\(x,y) -> x *x == y ) 


main = do
    print $ checkRootLC [(5, 25), (6, 36), (7, 47), (8, 88)] == [True, True, False, False]
    print $ checkRootHOF [(5, 25), (6, 36), (7, 47), (8, 88)] == [True, True, False, False]