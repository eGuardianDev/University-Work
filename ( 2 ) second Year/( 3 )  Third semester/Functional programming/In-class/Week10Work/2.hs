
type Node = Int
type Nodes = [Node]
type Graph = [(Node, Nodes)]

type Path = Nodes 

isChild :: Node -> Node -> Graph -> Bool
isChild p c g = elem c $ head $ [ y | (x,y) <- g, x == p]


isPath :: Graph -> Path -> Bool
isPath gr path = all (\(x,y) -> isChild x y gr) $ zip path $ tail path



main = do
    print $ isPath [(1, [2, 3]), (2, [3, 4]), (3, []), (4, [])] [1, 2, 4] == True
    print $ isPath [(1, [2, 3]), (2, [3, 4]), (3, []), (4, [])] [1, 3, 4] == False
    print $ isPath [(1, [2, 3]), (2, [3, 4]), (3, []), (4, [])] [2, 3] == True
    print $ isPath [(1, [2, 3]), (2, [3, 4]), (3, []), (4, [])] [3, 1] == False