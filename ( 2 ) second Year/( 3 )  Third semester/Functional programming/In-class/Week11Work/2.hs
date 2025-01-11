
data NTree a = Nil | Node a [NTree a]
  deriving Show


t1 = Node 1 [Node 3 [], Node 5 [], Node 7 [],Node 9 []]

t2 = Node 1 [Node 9 [Node 5 [], Node 2 []]]


main = do 
  print t1
  print t2