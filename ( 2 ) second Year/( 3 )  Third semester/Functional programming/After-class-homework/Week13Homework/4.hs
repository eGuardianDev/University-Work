import Data.List
data BTree = Nil | Node Int BTree BTree deriving (Eq, Ord)

t1 = (Node 10 (Node 1 Nil Nil) (Node 25 Nil (Node 30 (Node 26 Nil Nil) (Node 32 Nil Nil))))
t2 = (Node 25 (Node 10 (Node 1 Nil Nil) Nil) (Node 30 (Node 32 Nil Nil) (Node 26 Nil Nil)))
t3 = (Node 10 (Node 1 Nil Nil) (Node 25 Nil (Node 30 (Node 26 Nil Nil) (Node 32 Nil Nil))))
t4 :: BTree
t4 = (Node 10 (Node 1 Nil Nil) (Node 25 Nil (Node 30 (Node 27 Nil Nil) (Node 32 Nil Nil))))

getLeaves :: BTree -> [BTree]
getLeaves Nil = []
getLeaves (Node val Nil Nil) = [(Node val Nil Nil)]
getLeaves (Node val left right) = getLeaves left ++ getLeaves right

leavesAreEqual :: BTree -> BTree -> Bool
leavesAreEqual bt1 bt2 = sort (getLeaves bt1) == sort (getLeaves bt2)



main = do
 print $ leavesAreEqual t1 t2 == True
 print $ leavesAreEqual t3 t4 == False
 
 print $ leavesAreEqual t1 t3 == True -- my test
 print $ leavesAreEqual t2 t4 == False -- my test