
data Tree = Nil | Node Int Tree Tree 
 deriving Eq
tree = (Node 4 (Node 1 (Node 0 Nil Nil) (Node 2 Nil (Node 3 Nil Nil)))
               (Node 6 (Node 5 Nil Nil) (Node 7 Nil (Node 8 Nil Nil))))
tree2 = (Node 4 (Node 1 (Node 0 Nil Nil) (Node 4 Nil Nil))
               (Node 6 (Node 5 Nil Nil) Nil))

sumOver :: Int -> Tree -> Int
sumOver _ Nil = 0
sumOver n (Node val left right)
 | n <= val = val + sumOver n left + sumOver n right
 | otherwise = sumOver n left + sumOver n right
    
convert :: Tree -> Tree
convert Nil = Nil
convert tree = helper tree tree
 where 
    helper :: Tree -> Tree -> Tree
    helper _ Nil = Nil
    helper originalTree (Node val left right) = Node (sumOver val originalTree) (helper originalTree left)(helper originalTree right)

main = do
    print $ convert tree == (Node 30 (Node 36 (Node 36 Nil Nil) (Node 35 Nil (Node 33 Nil Nil))) (Node 21 (Node 26 Nil Nil) (Node 15 Nil (Node 8 Nil Nil))))
    print $ convert tree2 == Node 19 (Node 20 (Node 20 Nil Nil) (Node 19 Nil Nil)) (Node 6 (Node 11 Nil Nil) Nil) -- my test