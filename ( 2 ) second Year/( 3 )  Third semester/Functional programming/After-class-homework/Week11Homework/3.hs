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




compareIntervalsInside :: Interval -> Tree -> Bool
compareIntervalsInside _ Nil = True
compareIntervalsInside (a,b) (Node (a1,b1) _ _) = a <= a1 && b1 <= b

compareIntervalsOutside :: Interval -> Tree -> Bool
compareIntervalsOutside _ Nil = True
compareIntervalsOutside (a,b) (Node (a1,b1) _ _ ) = a1<=a && b <=b1 

ordered :: Tree -> Bool
ordered Nil = True
ordered (Node (a,b) left right) = 
    compareIntervalsInside (a,b) left 
    && compareIntervalsOutside (a,b) right
    && ordered left
    && ordered right

main = do
    print $ ordered t1 == True
    print $ ordered t2 == False
    print $ ordered Nil == True -- my test