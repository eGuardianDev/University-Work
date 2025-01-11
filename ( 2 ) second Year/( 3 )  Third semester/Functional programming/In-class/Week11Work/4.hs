

data BTree a = Nil | Node a (BTree a) (BTree a)
  deriving (Eq, Show)



insert :: (Num a, Ord a) => BTree a -> a -> BTree a
insert Nil n = Node n Nil Nil
insert (Node val left right) n
 | n < val = Node val (insert left n ) right
 | otherwise = Node val left (insert right n)


numberTreeBefore = (Node 10 (Node 5 (Node 3 Nil Nil) (Node 7 Nil Nil)) (Node 15 Nil (Node 18 Nil Nil)))

numberTreeAfter = foldl insert Nil [10,5,3,7,15,18]
secondNumberTree = foldl insert Nil [10,5,3,1,7,6,15,13,18]
main = do
    print $ insert (Node 10 (Node 5 (Node 3 Nil Nil) (Node 7 Nil Nil)) (Node 15 Nil (Node 18 Nil Nil))) 13 == (Node 10 (Node 5 (Node 3 Nil Nil) (Node 7 Nil Nil)) (Node 15 (Node 13 Nil Nil) (Node 18 Nil Nil)))

    print $ (numberTreeAfter == numberTreeBefore) == True

    print $ secondNumberTree == Node 10 (Node 5 (Node 3 (Node 1 Nil Nil) Nil) (Node 7 (Node 6 Nil Nil) Nil)) (Node 15 (Node 13 Nil Nil) (Node 18 Nil Nil))