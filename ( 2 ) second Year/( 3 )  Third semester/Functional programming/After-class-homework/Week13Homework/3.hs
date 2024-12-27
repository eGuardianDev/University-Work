data Tree = Nil | Node Int Tree Tree 


numberBTree = Node 10 (Node 5 (Node 1 Nil Nil) (Node 9 Nil Nil))
                      (Node 6 (Node 8 Nil Nil) (Node 7 Nil Nil))
                      
numberBTree2 = Node 14 (Node 5 (Node 1 Nil Nil) (Node 9 Nil Nil))
                       (Node 11 Nil (Node 4 Nil Nil))

levelSum :: Tree -> Int -> Int
levelSum Nil _ = 0
levelSum (Node val left right) 0 = val
levelSum (Node val left right) n = levelSum left (n-1) + levelSum right (n-1) 


getHeight :: Tree -> Int
getHeight Nil = 0
getHeight (Node _ left right) = 1 + max (getHeight left) (getHeight right)

cone :: Tree -> Bool
cone Nil = True
cone tree = helper tree 0 (getHeight tree -1)
    where
        helper :: Tree -> Int -> Int -> Bool
        helper Nil _ _= False
        helper tree k n 
         | k == n = True
         | levelSum tree k < levelSum tree (k+1) = helper tree (k+1) n
         | otherwise = False


main = do
    print $ levelSum numberBTree 1 == 11 -- (5 + 6)
    print $ cone numberBTree == True

    print $ levelSum numberBTree2 1 == 16 -- my test
    print $ cone numberBTree2 == False -- my test

    