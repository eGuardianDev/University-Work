
import Data.List

type Node = Int
type Nodes = [Node]
type Edge = (Node, Node)
type Graph = [Edge]


nodes :: Graph -> Nodes
nodes  = nub . concatMap (\(x,y) -> [x,y]) 

neighbors :: Node -> Graph-> Nodes
-- neighbors x g = [x2 |(x1,x2) <-g,x1==x] 
neighbors x = map snd . filter (\(x1,x2) -> x1 == x) 

adjacencyList :: Graph -> [(Node, Nodes)]
adjacencyList gr = map (\p -> (p, neighbors p gr)) $ nodes gr


main = do
    print $ nodes [(1, 2), (1, 3), (2, 3), (2, 4)] == [1, 2, 3, 4]

    print $ neighbors 2 [(1, 2), (1, 3), (2, 3), (2, 4)] == [3, 4]
    print $ neighbors 4 [(1, 2), (1, 3), (2, 3), (2, 4)] == []

    print $ adjacencyList [(1, 2), (1, 3), (2, 3), (2, 4)] == [(1, [2, 3]), (2, [3, 4]), (3, []), (4, [])]