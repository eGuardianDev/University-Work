data Color = Red | Green | Blue
data Tree = Empty | Node Color Tree Tree


colorTree = Node Blue (Node Red (Node Green Empty Empty) Empty) (Node Red (Node Blue (Node Green Empty Empty) (Node Red Empty Empty)) Empty )

colorTree2 = Node Blue (Node Green Empty Empty) Empty
colorTree3 = Empty

minDepthGreenNode :: Tree -> Int
minDepthGreenNode Empty = -1
minDepthGreenNode (Node Green _ _) = 0
minDepthGreenNode (Node _ Empty right) = 1 + minDepthGreenNode right
minDepthGreenNode (Node _ left Empty) = 1 + minDepthGreenNode left
minDepthGreenNode (Node _ left right) = 1 + min (minDepthGreenNode left)  (minDepthGreenNode right)


main = do
    print $ minDepthGreenNode colorTree == 2
    print $ minDepthGreenNode colorTree2 == 1 -- my test
    print $ minDepthGreenNode colorTree3 == -1 -- my test