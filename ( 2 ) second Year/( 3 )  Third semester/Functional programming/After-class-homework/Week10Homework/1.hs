type Node = Int
type Graph = [(Node, [Node])]
type Path = [Node]

getPair :: Node -> Graph -> (Node, [Node])
getPair node gr = head $ filter (\(x,xs) -> x == 1) gr

simplePaths :: Graph -> Int -> Node -> [Path]
simplePaths _ 0 _ = [] 
simplePaths gr k n = 
    let (y,ys) = getPair n gr
    in y : map (\x -> simplePaths gr (k-1) x) ys 
        


main = do
    print $ simplePaths [(1, [2, 3]), (2, [3, 4]), (3, []), (4, [])] 0 1 == [[1]]
    print $ simplePaths [(1, [2, 3]), (2, [3, 4]), (3, []), (4, [])] 1 1 == [[1, 2], [1, 3]]
    print $ simplePaths [(1, [2, 3, 4]), (2, [3, 4]), (3, []), (4, [])] 1 1 == [[1,2],[1,3],[1,4]]
    print $ simplePaths [(1, [2, 3]), (2, [3, 4]), (3, []), (4, [])] 2 1 == [[1, 2, 3], [1, 2, 4]]
    print $ simplePaths [(1, [2, 3]), (2, [3, 4]), (3, []), (4, [])] 1 2 == [[2,3],[2,4]]
    print $ simplePaths [(1, [2, 3]), (2, [3]), (3, []), (4, [])] 1 2 == [[2,3]]