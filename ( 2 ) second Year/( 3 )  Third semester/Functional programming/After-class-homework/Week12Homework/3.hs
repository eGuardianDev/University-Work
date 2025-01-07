
data Color = Red | Green | Blue
data Tree = Empty | Node Color Tree Tree

colorTree = Node Blue (Node Red (Node Green Empty
                                             Empty)
                                Empty)
                      (Node Red (Node Blue (Node Green Empty Empty) 
                                            (Node Red Empty Empty)) 
                                Empty)

colorTree2 = Node Blue (Node Red (Node Green Empty
                                             Empty)
                                Empty)
                      (Node Red (Node Red (Node Green Empty Empty) 
                                            (Node Red Empty Empty)) 
                                Empty)


maxDepthBlueNode :: Tree -> Int
maxDepthBlueNode Empty = -1
maxDepthBlueNode tree = helper 0 0 tree
    where
        helper :: Int -> Int ->Tree -> Int
        helper deepestBlue current Empty = deepestBlue
        helper deepestBlue current (Node Blue left right) = max ( helper (max current deepestBlue) (current+1) left) ( helper (max current deepestBlue) (current+1) right) 
        helper deepestBlue current (Node _ left right) = max ( helper deepestBlue (current+1) left) ( helper deepestBlue (current+1) right) 


main = do 
    print $ maxDepthBlueNode colorTree == 2
    print $ maxDepthBlueNode colorTree2 == 0 -- my test
    print $ maxDepthBlueNode Empty == -1 -- my test