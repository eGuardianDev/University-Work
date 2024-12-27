-- import Debug.Trace
import Data.List
import Data.Binary.Get (label)

type Pos = (Int,Int)
type Maze = [String]

isValidPos :: Pos -> Maze -> Bool
isValidPos (x,y) maze = 0 <= y && y<= length maze - 1 && 0 <= x && x <= length (head maze) - 1 

getNextValid :: Pos -> Maze -> [Pos]
getNextValid pos maze = filter (`isValidPos` maze) $ nextPositions pos maze  

getStartingY :: Maze -> Int
getStartingY maze 
 | null mazeY = error "Missing starting position - symbol S"
 | otherwise = length maze - length mazeY
    where mazeY = dropWhile not $ map (elem 'S') maze

getStartingX :: String -> Int
getStartingX row 
 | null rowX = error "Missing Starting position - symbol S"
 | otherwise = length row - length rowX
    where rowX = dropWhile not $ map (== 'S') row

getStart :: Maze -> Pos
getStart maze = (x,y)
    where
        y = getStartingY maze
        x = getStartingX $ maze !! y

getSymbol :: Pos -> Maze -> Char
getSymbol (x,y) maze
 | not $ isValidPos (x,y) maze = error "Out of bound position"
 | otherwise = (!! x) . (!! y) $ maze


nextPositions :: Pos -> Maze -> [Pos]
nextPositions (x,y) maze
 | symbol == 'S' = [(x,y+1),(x,y-1),(x+1,y),(x-1,y)]
 | symbol == 'L' = [(x+1,y),(x,y-1)]
 | symbol == 'J' = [(x-1,y),(x,y-1)]
 | symbol == '7' = [(x-1,y),(x,y+1)]
 | symbol == 'F' = [(x+1,y),(x,y+1)]
 | symbol == '.' = []
 | symbol == '|' = [(x,y-1),(x,y+1)]
 | symbol == '-' = [(x-1,y),(x+1,y)]
 | otherwise = error "Invalid symbol found"
 where symbol = getSymbol (x,y) maze


perimeter :: Maze -> Int
perimeter maze = let start = getStart maze
        in head $ perimeterHelper maze 1 start start (getNextValid start maze)
    where 
        perimeterHelper :: Maze -> Int -> Pos -> Pos -> [Pos] -> [Int]
        perimeterHelper maze count lastPos currPos nextPositions =
            let filtered = filter (/= lastPos) nextPositions
            in if getStart maze `elem` filtered then [count]
            else 
                concatMap 
                (\x -> perimeterHelper maze (count+1) currPos x (getNextValid x maze)) filtered
            



roads :: Maze -> [Pos]
roads maze = let start = getStart maze
        in perimeterHelper maze start start (getNextValid start maze) []
    where 
        perimeterHelper :: Maze -> Pos -> Pos -> [Pos] -> [Pos] -> [Pos]
        perimeterHelper    maze  lastPos currPos nextPos passed =
            let filtered = filter (/= lastPos) nextPos
            in if getStart maze `elem` filtered then passed
            else 
                concatMap 
                (\x -> perimeterHelper maze currPos x (getNextValid x maze) (if getSymbol x maze /= '.' then  passed ++ [x] else passed) ) filtered


findDots :: Maze -> [Pos]
findDots maze = helper maze 0 0 []
    where  
        helper :: Maze -> Int -> Int -> [Pos] -> [Pos]
        helper maze x y res
         | x == length ( head maze) = helper maze 0 (y+1) res   
         | y == length maze = res
         | getSymbol (x,y) maze == '.' = helper maze (x+1) y $ (x,y):res 
         | otherwise = helper maze (x+1) y res


areNeighbors :: Pos -> Pos -> Bool
areNeighbors (x,y) (a,b) = abs (x -  a) <=1 &&  abs (y - b) <=1 

getLocalNeighbors :: Pos -> [Pos] -> [Pos]
getLocalNeighbors curr = filter (areNeighbors curr)

getChainNeighbors :: Pos -> [Pos] ->[Pos]
getChainNeighbors curr allData = helper [curr] [] allData
    where 
        helper :: [Pos] -> [Pos] -> [Pos] -> [Pos]
        helper curr remember allData        
         | curr == remember = curr
         | otherwise = helper (nub $ concatMap ( `getLocalNeighbors` allData) curr) curr allData

groupNeighbors :: [Pos] -> [[Pos]]
groupNeighbors input = helper input []
 where 
    helper :: [Pos] -> [[Pos]] -> [[Pos]]
    helper [] res = res 
    helper curr res = 
        let neighbors = getChainNeighbors (head curr) curr
        in helper (removeInList neighbors curr) (res ++ [neighbors])

removeInList :: (Eq a) => [a] -> [a] -> [a]
removeInList [] res = res 
removeInList (x:curr) list = removeInList curr $ filter (/= x) list

touchingOutterWall :: Maze -> [Pos] -> Bool
touchingOutterWall maze pos = maxY pos == l || minY pos == 0 || minX pos == 0 || maxX pos == row   
    where
        l =  length maze -1 
        row = (+ (-1)) $ length $ head maze
        maxX :: [Pos] -> Int
        maxX  = maximum . map fst 
        maxY :: [Pos] -> Int
        maxY  = maximum . map snd
        minX :: [Pos] -> Int
        minX  = minimum . map fst 
        minY :: [Pos] -> Int
        minY  = minimum . map snd


getGlobalNeighbors :: Pos -> [Pos]
getGlobalNeighbors (x,y) = [(x+1,y),(x-1,y),(x,y+1),(x,y-1)]

getBorder :: [Pos] -> Maze -> [Pos]
getBorder poses maze =  filter (`isValidPos` maze) $ concatMap getGlobalNeighbors poses


isGroupLoopedInRoad :: [Pos] -> Maze -> Bool
isGroupLoopedInRoad group maze = all (\x -> elem x (roads maze)) $ removeInList group (removeInList group $ getBorder group maze)



numEnclosed :: Maze -> Int
numEnclosed maze = length $ filter (\a -> (isGroupLoopedInRoad a maze) && (not $ touchingOutterWall maze a) )( groupNeighbors $ findDots maze) 



-- testmaze = ["...|.....|...",
--                         ".S---7..F--7.",
--                         ".|...|--|..|.",
--                         ".L---J..L--J.",
--                         "...|.....|..."]
main = do
--ex 1
    print $ perimeter  ["7-F7-",
                        ".FJ|7",
                        "SJLL7",
                        "|F--J",
                        "LJ.LJ"] == 16 
    print $ perimeter ["-.|F7",
     ".S-7|",
     "L|7||",
     "-L-J|",
     "L|-JF"] == 8
    print $ perimeter ["F--7",
     "|F-7",
     ".S.|",
     "|L-J"] == 8


-- ex 2
    print $ numEnclosed ["...|.....|...",
                        ".S---7..F--7.",
                        ".|...|--|..|.",
                        ".L---J..L--J.",
                        "...|.....|..."] == 1
    print $ numEnclosed [".F--S--7.",
                        ".|F---7|.",
                        ".||...||.",
                        ".|L-7FJ|.",
                        ".L--JL-J."]  == 1
    print $ numEnclosed [".S-------7.",
                        ".|F-----7|.",
                        ".||.....||.",
                        ".|L-7.F-J|.",
                        ".|..|.|..|.",
                        ".L--J.L--J.",
                        "..........."] == 2
    print $ numEnclosed [".S--------7.",
                        ".|.F----7.|.",
                        ".|.|....|.|.",
                        ".|.|....|.|.",
                        ".|.L-7F-J.|.",
                        ".|...||...|.",         
                        ".L---JL---J."] == 3
    print $ numEnclosed ["..F-S-7.",
                        ".FJF-7L7",
                        "FJFJ.L7|",
                        "L-J...LJ"]  == 0