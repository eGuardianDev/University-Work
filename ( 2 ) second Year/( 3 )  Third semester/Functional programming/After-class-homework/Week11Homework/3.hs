data Tree = Nil | Node Interval Tree Tree
type Interval = (Int,Int)

t1 = Node (3,10) (Node (5,8) (Node (6,7) Nil Nil) ( Node (4,9) Nil Nil))
                 (Node (2,12) Nil (Node (1,15) Nil Nil))

t2 = Node (3,10) (Node (5,8) (Node (6,7) Nil Nil) 
                             ( Node (7,9) Nil Nil))
                 (Node (2,12) Nil
                             (Node (1,15) Nil Nil))



ordered :: Tree -> Bool
ordered Nil = True
ordered (Node (a,b) (Node (a1,b1) left1 right1) (Node (a2,b2) left2 right2)) = 
    (a<a1 && b1<b) && (a2<a && b<b2)&& ordered (Node (a1,b1) left1 right1) && ordered (Node (a2,b2) left2 right2)


main = do
    print $ ordered t1 == True
    print $ ordered t2 == False