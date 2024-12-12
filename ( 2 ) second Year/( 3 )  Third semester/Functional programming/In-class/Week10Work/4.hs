


data Point2D a = Point a a
 deriving (Eq, Show)

myImages :: (Num a, Eq a) => (a->a) -> (a->a) -> [Point2D a] -> [Point2D a]
myImages f g points = filter (\(Point x y) -> f x == g y ) points

myImagesFold :: (Num a, Eq a) => (a->a) -> (a->a) -> [Point2D a] -> [Point2D a]
myImagesFold f g points = foldr (\ point@(Point x y) acc -> if f x == g y then point : acc else acc  ) [] points 
-- foldr acc is in right (\ x acc -> )
-- foldl acc is in left  (\ acc x -> )
main = do
    print $ myImages (\x -> x * x) (2+) [Point 2 2, Point 1 2, Point 3 7] == [Point 2 2, Point 3 7]
    print $ myImagesFold (\x -> x * x) (2+) [Point 2 2, Point 1 2, Point 3 7] == [Point 2 2, Point 3 7]