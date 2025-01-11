

data NTree a = Nil | Node a [NTree a]
  deriving (Eq, Show)



t = Node 10 [Node 3 [Node 5 [],
                    Node 8 
                        [Node 1 [],
                         Node 2 []],
                    Node 9 []], 
            Node 7 
                [Node 11 [],
                 Node 13 []],
            Node 12 
                [ Node 6 [],
                 Node 4 []]]


size :: NTree a -> Int
size Nil = 0
size (Node _ xs) = 1 + (sum $ map size xs)

getLevel :: NTree a -> Int -> [a]
getLevel Nil _ = []
getLevel (Node x xs) 0 = [x] 
getLevel (Node _ xs) n = concatMap (\node -> getLevel node (n-1) ) xs


main = do
    print $ t
    print $ size t == 13
    print $ getLevel t 2 == [5, 8, 9, 11, 13, 6, 4]