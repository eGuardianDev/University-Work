


data NTree a = Nil | Node a [NTree a]
  deriving (Eq, Show)



t = Node 10 [Node 3 [Node 5 [Nil], Node 8 [Node 1 [Nil], Node 2 [Nil]], Node 9 [Nil]], Node 7 [Node 11 [Nil], Node 13 [Nil]], Node 12 [Node 6 [Nil], Node 4 [Nil]]]


getVal :: (Num a) => NTree a -> a
getVal Nil = 0
getVal (Node val _) = val


sumOfChildren :: (Num a) => [NTree a] -> a
sumOfChildren [] = 0
sumOfChildren xs = sum $ map getVal xs 


numOfNodes :: (Num a, Eq a ) => NTree a -> Int
numOfNodes Nil = 0
numOfNodes (Node grandFather children) = (length $ filter (== grandFather) $ sumOfChildren children ) 


main = do
    print $ numOfNodes t -- 8 and 12