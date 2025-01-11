import Data.List
data BTree a = Nil | Node a (BTree a) (BTree a)

t1 :: BTree Char
t1 = Node 'a' (Node 'c' (Node 'f' Nil Nil) (Node 'd' Nil Nil)) (Node 'b' Nil (Node 'e' Nil Nil))

t2 :: BTree Char
t2 = Node 'a' (Node 'c' (Node 'd' Nil Nil) Nil) (Node 'b' Nil Nil)

t3 :: BTree Char
t3 = Node 'a' (Node 'b' (Node 'd' (Node 'h' Nil Nil) (Node 'i' Nil Nil)) (Node 'e' Nil Nil)) (Node 'c' (Node 'f' Nil Nil) (Node 'g' Nil Nil)) 

t4 :: BTree Char
t4 = Node 'a' (Node 'c' (Node 'd' Nil Nil) Nil) (Node 'g' Nil Nil)


containsWord :: (Eq a) => BTree a -> [a] -> Bool
containsWord Nil _ = False
containsWord _ [] = False
containsWord (Node val Nil Nil) [w] = val == w
containsWord t@(Node val left right) wholeWord@(w:word)
 | (not $ null word) && w == val && elem (head word) (getLevel t 1) = containsWord left word|| containsWord right word
 | otherwise =  containsWord left wholeWord || containsWord right wholeWord

getLevel :: BTree a -> Int -> [a]
getLevel Nil _ = [] 
getLevel (Node value _ _) 0 = [value] 
getLevel (Node _ left right) k = getLevel left (k-1) ++ getLevel right (k-1)


traverses :: BTree Char -> [Char]
traverses Nil = []
traverses (Node val left right) = [val] ++ traverses left ++ traverses right


genWords :: BTree Char -> [String]
genWords t = sort $ filter (containsWord t)$ subsequences $ traverses t

allContain :: [BTree Char] -> [String]
-- allContain ts = foldl1 intersect $ map genWords ts
allContain ts = map head $ filter (\x -> length x == length ts) $ group $ sort $ concatMap genWords ts

main = do
    print $ allContain [t1, t2] == ["acd","cd","d"]
    print $ allContain [t1, t2, t3] == []
    print $ allContain [t3, t4] == ["g"]