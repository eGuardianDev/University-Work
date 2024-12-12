import Data.List

type TreeNode = (Int,Int,Int) 
type Tree = [TreeNode]

isLeaf :: Tree -> Int -> Bool
isLeaf tree n = not $ any (\(x,y,z) ->x == n) tree 

listLeaves :: Tree -> [Int]
listLeaves tree = filter (\x -> isLeaf tree x ) $ nub $ concatMap (\(x,y,z) -> [x,y,z]) tree

main = do
    -- you may get slightly different results eg. [3, 4, 5] on test 1 <- not a problem
    print $ listLeaves [(1, 2, 3), (2, 4, 5)] == [3, 4, 5]
    -- print $ listLeaves [(1, 2, 3), (2, 4, 5)] == [4, 3, 5]
    print $ listLeaves [(2, 4, 5), (1, 2, 3)] == [4, 5, 3]
    print $ listLeaves [(1, 2, 3), (3, 4, 5), (5, 6, 9)] == [2, 4, 6, 9]

    print $ listLeaves [(1,3,0), (3, 4, 5)] == [0,4,5] -- my test