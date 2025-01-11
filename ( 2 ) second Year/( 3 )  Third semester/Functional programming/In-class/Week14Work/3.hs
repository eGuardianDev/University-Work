import Data.Char


isSubString :: String -> String -> Bool
isSubString substring [] = False 
isSubString substring original@(x:xs) 
 | take (length substring ) original == substring = True
 | otherwise = isSubString substring xs


getNum :: String -> Int
getNum str = case str of
    "one" -> 1
    "two" -> 2
    "three" -> 3
    "four" -> 4
    "five" -> 5
    "six" -> 6
    "seven" -> 7
    "eight" -> 8
    "nine" -> 9
    "zero" -> 0

-- getNumFromString :: String -> Int
getNumFromString str = getNum $ head $ filter (\x -> isSubString x str) ["one","two","three","four","five","six","seven","eight","nine","zero"]

calibrationValue :: String -> Int
calibrationValue word = read $ filter (\x -> let val = ord x- 48 in val>=0 && val <= 9 ) word

minCalibrationValue :: [String] -> String
minCalibrationValue val = ""

main = do
    print $ minCalibrationValue ["1abc2", "pqrthreestu8vwx", "a1b2c3d4e5f", "trebsevenuchet"] == "1abc2"
    print $ minCalibrationValue ["has2ell", "rac5et"] == "has2ell"
    print $ minCalibrationValue ["jboktwoneaad", "agga20zs"] == "agga20zs"
    print $ minCalibrationValue ["jboktwoneaad", "agninega5zs"] == "jboktwoneaad"
    print $ minCalibrationValue ["1hhdz156qpfmmrb", "onetwo6ctkntf", "pfthree3oneninegzqpgxq2eight", "four99", "8bcr"] == "onetwo6ctkntf"
    print $ minCalibrationValue ["eight24five1", "k8two918hrnine", "948", "jnhldbh7dkskeight9", "np2"] == "np2"
    print $ minCalibrationValue ["rkmbh8", "five3xhpsdfkg94two3six", "bcstq5dghsfrcmftwo4lflbbrpztwo","fiveightjdd4eight", "7mmvkgmq"] == "bcstq5dghsfrcmftwo4lflbbrpztwo"