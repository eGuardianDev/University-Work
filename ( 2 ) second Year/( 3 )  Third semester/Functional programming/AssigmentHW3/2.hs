import Data.List (groupBy, sortBy)
import Data.Function (on)

-- Group vectors by the first argument
groupByFirst :: [(Int, Int)] -> [[(Int, Int)]]
groupByFirst vectors = 
    groupBy ((==) `on` fst) $ sortBy (compare `on` fst) vectors

main :: IO ()
main = do
    let vectors = [(1, 2), (1, 3), (2, 4), (3, 5), (2, 6), (1, 7)]
    print $ groupByFirst vectors