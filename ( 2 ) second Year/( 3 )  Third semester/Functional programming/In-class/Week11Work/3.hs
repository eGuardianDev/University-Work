
data BTree a = Nil | Node a (BTree a) (BTree a)
  deriving (Eq, Show)


constructMaxBTree :: (Eq a, Ord a) => [a] -> BTree a
constructMaxBTree [] = Nil
constructMaxBTree xs = Node maxElement (constructMaxBTree $ takeWhile (/= maxElement) xs) 
                                       (constructMaxBTree $ tail $ dropWhile (/= maxElement) xs)
  where  
    maxElement = maximum xs


t = Node 6 (Node 3 Nil (Node 2 Nil (Node 1 Nil Nil))) (Node 5 (Node 0 Nil Nil) Nil)
  
main = do
  print $ constructMaxBTree [3, 2, 1, 6, 0, 5] == t