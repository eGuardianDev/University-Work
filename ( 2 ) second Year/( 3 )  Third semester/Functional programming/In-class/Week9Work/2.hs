

isTriangular :: (Num a, Eq a) => [[a]] -> Bool
isTriangular xss = helper 0 xss
 where 
    helper :: (Num a, Eq a)=> Int -> [[a]] -> Bool
    helper _ [] = True
    helper count (x:xs) = all (==0) (take count x) && helper (count+1) xs
    --  | all (== 0) $ take count x = helper (count+1) xs 
    --  | otherwise = False
main = do
    print $ isTriangular [] == True
    print $ isTriangular [[-1]] == True
    print $ isTriangular [[-1, -2, -3], [0, -5, -6], [0, 0, -9]] == True
    print $ isTriangular [[1, 2, 3], [0, 5, 6], [0, 0, 9]] == True
    print $ isTriangular [[0, 2, 3], [0, 0, 6], [1, 0, 0]] == False
    print $ isTriangular [[1, 2, 3], [1, 5, 6], [0, 0, 9]] == False
    print $ isTriangular [[1, 2, 3, 4], [0, 5, 6, 7], [0, 0, 8, 9], [0, 0, 0, 9]] == True