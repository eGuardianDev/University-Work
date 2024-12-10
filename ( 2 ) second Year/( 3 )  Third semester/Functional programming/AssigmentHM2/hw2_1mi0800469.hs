import Data.List

isValidLine :: [Int] -> Bool
isValidLine xs = sort xs == [1..8]

isValidEveryRow :: [[Int]] -> Bool
isValidEveryRow = all isValidLine

isValidEveryCollum :: [[Int]] -> Bool
isValidEveryCollum = all isValidLine . transpose
  
makeTwoBoxes :: [[Int]] -> [[Int]]
makeTwoBoxes xss = [take 4 ( head xss) ++ take 4 ( head $ tail xss)] ++ [drop 4 ( head xss) ++ drop 4 ( head $ tail xss)]

isValidEveryBoxes :: [[Int]] -> Bool
isValidEveryBoxes xss = isValidEveryRow $ makeTwoBoxes xss ++ makeTwoBoxes ( drop 2 xss) ++ makeTwoBoxes ( drop 4 xss) ++ makeTwoBoxes ( drop 6 xss)

isValidSudoku :: [[Int]] -> Bool
isValidSudoku xss = isValidEveryRow xss && isValidEveryCollum xss && isValidEveryBoxes xss 
main = do 
    print $ isValidSudoku [[1, 2, 3, 4, 5, 6, 7, 8],
                           [5, 6, 7, 8, 1, 2, 3, 4],
                           [2, 3, 4, 1, 6, 5, 8, 7],
                           [6, 5, 8, 7, 2, 3, 4, 1],
                           [3, 4, 1, 2, 7, 8, 5, 6],
                           [7, 8, 5, 6, 3, 4, 1, 2],
                           [4, 1, 2, 3, 8, 7, 6, 5],
                           [8, 7, 6, 5, 4, 1, 2, 3]]
-- → True
    print $ isValidSudoku [[1, 6, 3, 4, 5, 6, 7, 8],
                           [5, 2, 7, 8, 1, 2, 3, 4],
                           [2, 3, 4, 1, 6, 5, 8, 7],
                           [6, 5, 8, 7, 2, 3, 4, 1],
                           [3, 4, 1, 2, 7, 8, 5, 6],
                           [7, 8, 5, 6, 3, 4, 1, 2],
                           [4, 1, 2, 3, 8, 7, 6, 5],
                           [8, 7, 6, 5, 4, 1, 2, 3]]
-- → False
    print $ isValidSudoku [[1, 2, 3, 4, 5, 6, 7, 8],
                           [5, 6, 7, 8, 1, 2, 3, 4],
                           [2, 3, 4, 1, 6, 5, 8, 7],
                           [6, 5, 8, 7, 2, 3, 4, 1],
                           [3, 4, 1, 2, 2, 8, 5, 6],
                           [7, 8, 5, 6, 3, 4, 1, 2],
                           [4, 1, 2, 3, 8, 7, 6, 5],
                           [8, 7, 6, 5, 4, 1, 2, 3]]
-- → False
