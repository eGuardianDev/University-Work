data Measuring = Temp Int Float -- day / Degrees

averageTemp :: [Measuring] -> Float
averageTemp arr = sum ( map (\(Temp i fl) -> fl) arr) / fromIntegral (length arr)

differenceInTemp :: Measuring -> Float -> Float
differenceInTemp (Temp day1 temp1) temp2 = abs( temp1 - temp2)

closestAverage :: [Measuring] -> Int
closestAverage xs = 
    let avg = averageTemp xs
        (Temp i _) = fst $ foldr1 (\ (Temp d1 t1, dif1) (Temp d2 t2, dif2)-> if dif1 <= dif2 then (Temp d1 t1,dif1) else (Temp d2 t2,dif2)) $ map (\x -> (x, differenceInTemp x avg) ) xs in i

main = do
    print $ closestAverage [(Temp 1 23.6), (Temp 6 24.2), (Temp 11 24.2), (Temp 16 21.2), (Temp 21 23.8), (Temp 26 26.5), (Temp 31 24.5)] == 6
    print $ closestAverage [(Temp 11 24.2), (Temp 16 21.2), (Temp 21 23.8), (Temp 26 26.5), (Temp 31 24.5)] == 11 -- my test