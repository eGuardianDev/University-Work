import Data.List

data BTree a = Nil | Node a (BTree a) (BTree a)

t1 = Node 94 (Node 73 Nil (Node 80 Nil Nil)) (Node 87 (Node 73 Nil Nil) Nil)
t2 = Node 94 (Node 73 Nil (Node 80 Nil Nil)) (Node 87 (Node 73 Nil Nil) (Node 7 Nil Nil))
t3 = Node 94 (Node 0 Nil (Node 42 Nil Nil)) (Node 0 (Node 42 Nil Nil) (Node 42 Nil Nil))

getLevel :: BTree a -> Int -> [a]
getLevel Nil _ = []
getLevel (Node val _ _ ) 1 = [val]
getLevel (Node _ left right) k = getLevel left (k-1) ++ getLevel right (k-1)

height :: BTree a -> Int
height Nil = 0
height (Node _ left right) = max (1 + height left) (1 + height right) 


maximumLevel :: (Ord a, Num a) => BTree a -> Int
maximumLevel tree = snd $ last $ sort $ map (\x -> ((sum $ getLevel tree x), x)) [1 .. (height tree)]

main = do
   print $ maximumLevel t1 == 2
   print $ maximumLevel t2 == 3
   print $ maximumLevel t3 == 3