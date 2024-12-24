import Data.Char

-- data BTree a = Nil | Node a {BTree a} {BTree a}
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

-- = Null | Noda a  {BTree a} {BTree a} 



size :: BTree a -> Int
size Nil = 0
size (Node _ left right) = 1 + size left + size right

sumTree :: (Num a) => BTree a -> a
sumTree Nil = 0
sumTree (Node val left right) = val + sumTree left + sumTree right

traverseDFS :: BTree a -> [a]
traverseDFS Nil = []
traverseDFS (Node val left right) =  traverseDFS left ++ [val] ++ traverseDFS right 

getLevel :: BTree a -> Int -> [a]
getLevel Nil _ = []
getLevel (Node val left right) 0 = [val]
getLevel (Node val left right) n = getLevel left (n-1) ++ getLevel right (n-1)



traverseBFS :: BTree a -> [a]
traverseBFS bTree = concat $ takeWhile (not.null) $ map (getLevel bTree) [0..] 


mapTree :: BTree a -> (a-> b)-> BTree b
mapTree Nil _ = Nil
mapTree (Node val left right) func = (Node (func val) (mapTree left func) (mapTree right func))


main :: IO ()
main = do 
    print $ numberBTree
    print $ charBTree

    print $ size numberBTree == 9
    print $ size charBTree == 7

    print $ sumTree numberBTree == 146
    -- print $ sumTree charBTree -- should not work

    print $ traverseDFS numberBTree == [96, 1, 12, 0, 5, 2, 4, 5, 21]
    print $ traverseDFS charBTree == "haskell"

    print $ getLevel numberBTree 2 == [1, 0, 2, 5]
    print $ getLevel charBTree 1 == "al"
    print $ getLevel charBTree 3 == []

    print $ traverseBFS numberBTree == [5,12,4,1,0,2,5,96,21]
    print $ traverseBFS charBTree == "kalhsel"

    print $ mapTree numberBTree (*2) == Node 10 (Node 24 (Node 2 (Node 192 Nil Nil) Nil) (Node 0 Nil Nil)) (Node 8 (Node 4 Nil Nil) (Node 10 Nil (Node 42 Nil Nil)))
    print $ mapTree numberBTree (show) == Node "5" (Node "12" (Node "1" (Node "96" Nil Nil) Nil) (Node "0" Nil Nil)) (Node "4" (Node "2" Nil Nil) (Node "5" Nil (Node "21" Nil Nil)))
    print $ mapTree charBTree (toUpper) == Node 'K' (Node 'A' (Node 'H' Nil Nil) (Node 'S' Nil Nil)) (Node 'L' (Node 'E' Nil Nil) (Node 'L' Nil Nil))