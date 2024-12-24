import Data.List

data BTree = Nil | Node Int BTree BTree
  deriving (Eq, Show)


t3 :: BTree
t3 = Node 8 (Node 3 (Node 1 Nil Nil) (Node 6 (Node 4 Nil Nil) (Node 7 Nil Nil))) (Node 10 Nil (Node 14 (Node 13 Nil Nil) Nil))

t4 :: BTree
t4 = Node 8 (Node 3 (Node 5 Nil Nil) (Node 6 Nil Nil)) (Node 10 Nil (Node 14 Nil Nil))

t5 :: BTree
t5 = Node 8 (Node 3 (Node 2 Nil Nil) (Node 6 Nil Nil)) (Node 10 Nil (Node 1 Nil Nil))

t6 :: BTree 
t6 = Node 8 (Node 3 (Node 1 Nil Nil) (Node 4 Nil Nil)) (Node 10 (Node 5 Nil Nil) Nil)



binaryTreeToList :: BTree -> [Int]
binaryTreeToList Nil = [] 
binaryTreeToList (Node val left right) = binaryTreeToList left ++ [val] ++ binaryTreeToList right 

isBinarySearchTree :: BTree -> Bool
isBinarySearchTree Nil = True
isBinarySearchTree tree = list == sort list
    where list = binaryTreeToList tree

main = do 
    print $ isBinarySearchTree t3 == True
    print $ isBinarySearchTree t4 == False
    print $ isBinarySearchTree t5 == False
    print $ isBinarySearchTree t6 == False