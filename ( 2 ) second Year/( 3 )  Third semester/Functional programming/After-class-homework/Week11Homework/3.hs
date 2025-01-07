data Tree = Nil | Node Interval Tree Tree
type Interval = (Int,Int)

t1 = Node (3,10) (Node (5,8)  (Node (6,7) Nil Nil) 
                              ( Node (4,9) Nil Nil))
                 (Node (2,12) Nil 
                              (Node (1,15) Nil Nil))

t2 = Node (3,10) (Node (5,8) (Node (6,7) Nil Nil) 
                             ( Node (7,9) Nil Nil))
                 (Node (2,12) Nil
                             (Node (1,15) Nil Nil))


compareIsIntervalGood :: Interval -> Interval-> Bool
compareIsIntervalGood (a,b) (a1,b1) = (a <= a1 && b1 <= b) || (a1<=a && b <= b1)


traverseDFS :: Tree -> [Interval] 
traverseDFS Nil = []
traverseDFS (Node interval left right) =  [interval] ++ traverseDFS left ++ traverseDFS right


ordered :: Tree -> Bool
ordered Nil = True
ordered tree = let dfs = traverseDFS tree in
     all (\ (x, y) -> compareIsIntervalGood x y) $ zip dfs (tail dfs)


main = do
    print $ ordered t1 == True
    print $ ordered t2 == False
    print $ ordered Nil == True -- my test