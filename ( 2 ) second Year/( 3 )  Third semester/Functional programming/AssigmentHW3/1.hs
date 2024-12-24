



RunAlgo currGroups [] = currGroups
RunAlgo currGroups dots = RunAlgo (currGroups ++ helper [] dots) (dots/ helper [] dots)
    where
        helper currentWorking [] = 
        helper currentWorking dots =...

    

checkTouchOutOfBound currSelectedDot =....
CheckIfLooped currGroup = filter checktOutOfBount currGroup


main = do 