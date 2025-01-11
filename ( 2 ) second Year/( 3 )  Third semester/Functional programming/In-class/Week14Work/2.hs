
import Data.List


findUniques :: [(String, Int)] -> (Int -> [String])
findUniques db = (\x -> filter (\y -> length y >= x) $ map fst $ (filterBooks db))
    where
     filterBooks :: [(String, Int)] -> [(String,Int)]
     filterBooks db =
        let years =  map head $ filter (\x -> length x == 1 ) $ group $ sort $ map snd  db
         in filter (\(x,y) -> y `elem` years )  db

db :: [(String, Int)]
db = [("SICP",1996),("Learn You a Haskell for Great Good",2011),("Real World Haskell",2008),("Programming in Haskell",2011)]

main = do
    print $ (findUniques db) 4 == ["SICP","Real World Haskell"]
    print $ (findUniques db) 8 == ["Real World Haskell"]
    print $ (findUniques db) 32 == []