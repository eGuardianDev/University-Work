type Node = Int
type Nodes = [Node]
type Graph = [(Node, [Node])]
type Path = [Node]

getChild ::  Node -> Graph -> [Node]
getChild n gr = head $ [ ys | (x,ys) <- gr,  x == n ]

getExtensionOfPath :: Node -> Graph -> [Path]
getExtensionOfPath n gr =  
    let pair = head $ filter (\ (p,c) -> p == n ) gr 
    in map (\x -> [x] ) $ snd pair



simplePaths :: Graph -> Int -> Node -> [Path]
simplePaths gr count start 
    | null $ filter (\ (p,c) -> p == start ) gr = error "Non existing node"
    | otherwise = helper gr count [[start]]
    where
        helper :: Graph -> Int -> [Path] -> [Path]
        helper graph 0 paths = paths
        helper graph count path = helper graph (count-1) (concatMap (\x -> map (\y -> x ++ y) $ getExtensionOfPath (last x) graph) path)


main = do
    print $ simplePaths [(1, [2, 3]), (2, [3, 4]), (3, []), (4, [])] 0 1 == [[1]]
    print $ simplePaths [(1, [2, 3]), (2, [3, 4]), (3, []), (4, [])] 1 1 == [[1, 2], [1, 3]]
    print $ simplePaths [(1, [2, 3, 4]), (2, [3, 4]), (3, []), (4, [])] 1 1 == [[1,2],[1,3],[1,4]]
    print $ simplePaths [(1, [2, 3]), (2, [3, 4]), (3, []), (4, [])] 2 1 == [[1, 2, 3], [1, 2, 4]]
    print $ simplePaths [(1, [2, 3]), (2, [3, 4]), (3, []), (4, [])] 1 2 == [[2,3],[2,4]]
    print $ simplePaths [(1, [2, 3]), (2, [3]), (3, []), (4, [])] 1 2 == [[2,3]]
    
    print $ simplePaths [(1, [2, 3]), (2, [3, 4]), (3, []), (4, [])] 3 1 == []  -- my test