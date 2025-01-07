type Name = String
type Capital = Name
type AvgYearlyTemperature = Double
type Elevation = Int
data City = City Name Elevation AvgYearlyTemperature
    deriving Eq
data Country = Country Name Capital [City] 

getHigherCity :: City -> City -> City
getHigherCity (City name1 elevation1 temp1) (City name2 elevation2 temp2)
 | elevation1 >= elevation2 = (City name1 elevation1 temp1)
 | otherwise = (City name2 elevation2 temp2)

highestCapital :: [Country] -> Name
highestCapital arr = let (Country name _ _) = foldr1 (\ (Country n1 c1 (city1:cities1)) (Country n2 c2 (city2:cities2)) -> if getHigherCity city1 city2 == city1 then Country n1 c1 (city1:cities1)  else Country n2 c2 (city2:cities2)) $ map getOnlyCapital arr in name

getOnlyCapital :: Country -> Country
getOnlyCapital (Country name1 capital cities) = Country name1 capital (filter (\ (City n el at) -> n == capital) cities)
main = do
    print $ highestCapital [(Country "Bulgaria" "Sofia" [(City "Varna" 0 16), (City "Plovdiv" 120 14), (City "Sofia" 420 13)]), (Country "Germany" "Berlin" [(City "Munchen" 200 15), (City "Berlin" 150 12), (City "Ulm" 210 15)]), (Country "France" "Paris" [(City "Paris" 180 15), (City "Nice" 0 14), (City "Lyon" 500 13)])] == "Bulgaria"
    print $ highestCapital [ (Country "Germany" "Berlin" [(City "Munchen" 200 15), (City "Berlin" 150 12), (City "Ulm" 210 15)]), (Country "France" "Paris" [(City "Paris" 180 15), (City "Nice" 0 14), (City "Lyon" 500 13)])] == "France" -- my test