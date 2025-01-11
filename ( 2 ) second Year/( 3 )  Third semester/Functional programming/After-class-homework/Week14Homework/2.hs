import Data.Char

reversed :: Bool -> Bool
reversed True = False
reversed False = True


type Cmd = String
type Last = Int

data State = Openning | Closing | StoppedClosing | StoppedOpenning | Openned | Closed


buttonPressed :: Cmd -> State -> Last -> [Int]
buttonPressed cmd state pos = case state of
    Closed ->          simulation cmd Openning        pos
    Openned ->         simulation cmd Closing         pos
    StoppedClosing ->  simulation cmd Closing         pos
    StoppedOpenning -> simulation cmd Openning        pos
    Closing ->         simulation cmd StoppedClosing  pos
    Openning ->        simulation cmd StoppedOpenning pos

obsticalDetected :: Cmd -> State -> Last -> [Int]
obsticalDetected cmd state pos = case state of
    Closed ->           simulation cmd Closed          pos
    Openned ->          simulation cmd Openned         pos
    StoppedClosing ->   simulation cmd StoppedClosing  pos
    StoppedOpenning ->  simulation cmd StoppedOpenning pos
    Closing ->          simulation cmd Openning        pos
    Openning ->         simulation cmd Closing         pos

dotSelected :: Cmd -> State -> Last -> [Int]
dotSelected cmd state pos = case state of
    Closing -> if pos > 0 then
        simulation cmd Closing ( pos-1)
        else simulation cmd Closed pos
    Openning -> if pos < 5 then
        simulation cmd Openning  (pos+1)
        else simulation cmd Openned pos
    _ -> simulation cmd state pos

simulation :: Cmd -> State -> Last -> [Int]
simulation [] _ _ = [] 
simulation (x:xs) state pos = case x of 
    'P' -> buttonPressed xs state pos
    'O' -> obsticalDetected xs state pos
    '.' -> dotSelected xs state pos


controller :: Cmd -> String
controller "" = ""
controller cmd = foldr (\x acc -> chr (x+48) : acc ) "" $ simulation cmd Closed 0


main = do
   print $ controller "" == ""
   print $ controller ".........."  == "0000000000"
   print $ controller "P...." == "12345"
   print $ controller "P.P.." == "12222"
   print $ controller "..P...O..." == "0012343210"
   print $ controller "P......P......" == "12345554321000"
   print $ controller "P.P.P...." -- == "122234555"
   print $ controller ".....P.P........P...." -- == "000001222222222234555"
   print $ controller ".........." == "0000000000"
   print $ controller "P.." == "123"
   print $ controller "P...." == "12345"
   print $ controller "P......P......" == "12345554321000"
   print $ controller "P.P.." == "12222"
   print $ controller "P.P.P...." == "122234555"
   print $ controller ".....P.P........P...." == "000001222222222234555"
   print $ controller ".....P......P.P..P...." == "0000012345554333321000"
   print $ controller "P.O...." == "1210000"
   print $ controller "P......P.O...." == "12345554345555"
   print $ controller "P..OP..P.." == "1232222100"
   print $ controller "P......P..OP..P..." == "123455543233334555"
   print $ controller "..P...O....." == "001234321000"