import Data.List

isValidLine :: [Int] -> Bool
isValidLine xs = length ( map head $ group $ sort xs) == 8

isValidEveryRow :: [[Int]] -> Bool
isValidEveryRow = all isValidLine

myTranspose :: [[Int]] -> [[Int]]
myTranspose [] = []
myTranspose [[]] = []
myTranspose xss
    | null $ head xss = []
    | otherwise = map head xss : myTranspose (map tail xss)

isValidEveryCollum :: [[Int]] -> Bool
isValidEveryCollum = all isValidLine . myTranspose



makeTwoBoxes :: [[Int]] -> [[Int]]
makeTwoBoxes xss = [take 4 ( head xss) ++ take 4 ( head $ tail xss)] ++ [drop 4 ( head xss) ++ drop 4 ( head $ tail xss)]

checkBoxes :: [[Int]] -> Bool
checkBoxes xss = isValidEveryRow $ makeTwoBoxes xss ++ (makeTwoBoxes $ drop 2 xss) ++ (makeTwoBoxes $ drop 4 xss) ++ (makeTwoBoxes $ drop 6 xss)


isValidSudoku :: [[Int]] -> Bool
isValidSudoku xss = isValidEveryRow xss && isValidEveryCollum xss && checkBoxes xss

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
