import Data.Char
 
reduceStrOnce :: String -> String -> String
reduceStrOnce output [] = output
reduceStrOnce output (x:[]) = output ++ [x]
reduceStrOnce output (x:y:ys)
  | chr (ord x +32 ) == y || chr (ord x-32) == y = reduceStrOnce output ys
  | otherwise = reduceStrOnce (output ++ [x]) (y:ys)

reduceStr :: String -> String
reduceStr a = runner a ""
 where 
    runner :: String -> String -> String
    runner a last
     | last == reduceStrOnce "" a = last
     | otherwise = runner (reduceStrOnce "" a) (reduceStrOnce "" a)

main = do 
    print $ reduceStr "dabAcCaCBAcCcaDD" == "dabCBAcaDD"
    print $ reduceStr "AeeaAbsSB" == "Aee" -- my test