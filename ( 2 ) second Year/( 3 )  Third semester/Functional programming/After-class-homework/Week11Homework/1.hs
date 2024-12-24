import System.Directory.Internal.Prelude (mkIOError)
data BTree a = Nil | Node a (BTree a) (BTree a)
    deriving (Show, Eq)


numberBTree = Node 5 (Node 12 (Node 1 (Node 96 Nil Nil)
                                       Nil) 
                            (Node 0 Nil Nil))
                     (Node 4 (Node 2 Nil Nil)
                             (Node 5 Nil
                                    (Node 21 Nil Nil)))


charBTree = Node 'k' (Node 'a' (Node 'h' Nil Nil) (Node 's' Nil Nil))
                     (Node 'l' (Node 'e' Nil Nil) (Node 'l' Nil Nil))

size :: BTree a -> Int
size Nil = 0
size (Node _ left right) = 1 + size left + size right

sumTree :: (Num a) => BTree a -> a
sumTree Nil = 0
sumTree (Node val left right) = val + sumTree left + sumTree right


height :: BTree a -> Int
height Nil = 0
height (Node _ left right) = max (1+ height left) (1+ height right)


average :: (Fractional a,RealFrac a) => BTree a -> a
average Nil = 0
average tree =  (fromIntegral . round $ (sumTree tree /  fromIntegral (size tree))*100 ) / 100


sumLeaves :: (Fractional a) => BTree a -> a
sumLeaves Nil = 0;
sumLeaves (Node val Nil Nil) = val
sumLeaves (Node val left right) = sumLeaves left + sumLeaves right

areEqual :: (Eq a)=> BTree a -> BTree a -> Bool
areEqual Nil Nil = True
areEqual tree Nil = False
areEqual Nil tree = False
areEqual (Node val1 left1 right1) (Node val2 left2 right2)
 | val1 == val2 = areEqual left1 left2   && areEqual right1 right2
 | otherwise = False


setLevels :: BTree a -> BTree (Int,a)
setLevels tree = helper tree 0
    where
        helper :: BTree a-> Int -> BTree (Int,a) 
        helper Nil _ = Nil
        helper (Node val left right) n = Node (n, val) (helper left (n+1)) (helper right (n+1))

mirrorTree :: BTree a -> BTree a
mirrorTree Nil = Nil
mirrorTree (Node val left right) = Node val (mirrorTree right) (mirrorTree left)

main = do 
    print $ height numberBTree == 4
    print $ height charBTree == 3

    print $ average numberBTree == 16.22
    --print $ average charBTree -- should not work

    print $ sumLeaves numberBTree == 119
    -- --print $ sumLeaves charBTree -- shouldn't work

    print $ areEqual numberBTree (Node 5 (Node 12 (Node 1 (Node 96 Nil Nil) Nil) (Node 0 Nil Nil)) (Node 4 (Node 2 Nil Nil) (Node 5 Nil Nil))) == False
    print $ areEqual charBTree charBTree == True
    print $ areEqual numberBTree (Node 5 (Node 12 (Node 1 (Node 96 Nil Nil) Nil) (Node 0 Nil Nil)) (Node 8 (Node 2 Nil Nil) (Node 5 Nil (Node 21 Nil Nil)))) == False

    print $ setLevels numberBTree == Node (0,5) (Node (1,12) (Node (2,1) (Node (3,96) Nil Nil) Nil) (Node (2,0) Nil Nil)) (Node (1,4) (Node (2,2) Nil Nil) (Node (2,5) Nil (Node (3,21) Nil Nil)))
    print $ setLevels charBTree == Node (0,'k') (Node (1,'a') (Node (2,'h') Nil Nil) (Node (2,'s') Nil Nil)) (Node (1,'l') (Node (2,'e') Nil Nil) (Node (2,'l') Nil Nil))

    print $ mirrorTree numberBTree == Node 5 (Node 4 (Node 5 (Node 21 Nil Nil) Nil) (Node 2 Nil Nil)) (Node 12 (Node 0 Nil Nil) (Node 1 Nil (Node 96 Nil Nil)))
    print $ mirrorTree charBTree == Node 'k' (Node 'l' (Node 'l' Nil Nil) (Node 'e' Nil Nil)) (Node 'a' (Node 's' Nil Nil) (Node 'h' Nil Nil))