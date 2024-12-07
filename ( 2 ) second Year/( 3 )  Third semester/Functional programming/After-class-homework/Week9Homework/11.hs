
subLists :: (Num a) => [a] -> Int -> [[a]]
subLists _ 0  =  error "cannot split into zero containers"  
subLists [] _  = []  
subLists xs el = take el xs : subLists (drop el xs) el

main = do
    print $ subLists [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] 2 == [[1, 2], [3, 4], [5, 6], [7, 8], [9, 10]]
    print $ subLists [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] 4 == [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10]]
    print $ subLists [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] 1 == [[1],[2],[3],[4],[5],[6],[7],[8],[9],[10]] -- my test