data Tree = Nil | Node Int [Tree]

t1 = Node 1 [Node 3 [Nil],Node 5 [Nil],Node 7 [Nil],Node 9 [Nil]]

t2 = Node 7 [Node 9 [Node 5 [], Node 2 []]]
t3 = Node 4 [Node 3 [Nil],Node 7 [Nil],Node 9 [Nil]]

isEven :: [Tree] -> Bool
isEven [] = True
isEven [Nil] = True
isEven xs = even $ length xs

isGraceful :: Tree -> Bool
isGraceful Nil = True
isGraceful (Node _ xs) = isEven xs && all isGraceful xs


main :: IO ()
main = do
    print $ isGraceful t1 == True
    print $ isGraceful t2 == False
    print $ isGraceful t3 == False -- my test