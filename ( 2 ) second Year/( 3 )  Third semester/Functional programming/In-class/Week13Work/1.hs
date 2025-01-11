data BTree a = Nil | Node a (BTree a) (BTree a)

t1 :: BTree Char
t1 = Node 'a' (Node 'c' (Node 'f' Nil Nil) (Node 'd' Nil Nil)) (Node 'b' Nil (Node 'e' Nil Nil))

t2 :: BTree Char
t2 = Node 'a' (Node 'c' (Node 'd' Nil Nil) Nil) (Node 'b' Nil Nil)

t3 :: BTree Char
t3 = Node 'a' (Node 'b' (Node 'd' (Node 'h' Nil Nil) (Node 'i' Nil Nil)) (Node 'e' Nil Nil)) (Node 'c' (Node 'f' Nil Nil) (Node 'g' Nil Nil)) 



getLevel :: BTree a -> Int -> [a]
getLevel Nil _ = [] 
getLevel (Node value _ _) 0 = [value] 
getLevel (Node _ left right) k = getLevel left (k-1) ++ getLevel right (k-1)

containsWord :: (Eq a) => BTree a -> [a] -> Bool
containsWord Nil _ = False
containsWord _ [] = False
containsWord (Node val Nil Nil) [w] = val == w
containsWord t@(Node val left right) wholeWord@(w:word)
 | (not $ null word) && w == val && elem (head word) (getLevel t 1) = containsWord left word|| containsWord right word
 | otherwise =  containsWord left wholeWord || containsWord right wholeWord

main = do
    print $ containsWord t1 "acd" == True
    print $ containsWord t1 "cd" == True
    print $ containsWord t1 "af" == False
    print $ containsWord t1 "ac" == False
    print $ containsWord t1 "acdh" == False
    print $ containsWord t1 "b" == False
    print $ containsWord t1 "e" == True
    print $ containsWord t2 "ab" == True
    print $ containsWord t2 "ad" == False
    print $ containsWord t3 "bdh" == True
    print $ containsWord t3 "bdi" == True
    print $ containsWord t3 "ac" == False