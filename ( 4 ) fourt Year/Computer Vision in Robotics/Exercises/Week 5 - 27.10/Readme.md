
# ROS 2 setup and docker

## Github
https://github.com/kyovchev/webots-ros2-docker

## Links 4 using the robot
http://localhost:9090/stream?topic=/object_detector/camera/image_color
http://127.0.0.1:8001/api/status



## Notes
Може да инсталираме WeBots R2025a програмта локално и да модифицираме света,
след това това да изпълним

Обаче в контейнера ако запазим, то ще се запази в temp локация

Ние може да я започнем чрез команта `webots` и след това
`/ros../webots/worlds` да намерим света и да запишем файла

`. /run.sh` - запазва временно данните


### Display sensors
- View -> Optional Rendeing 


### Change sensor settings
Може да изберем отляво камерата и да видим
 - translation
 - rotation
 - other...
може да нагласяме камерата да е възможно по-близо до реалния физически сензор


range finder sensor - дълбочинна камера


### Robot desciption

`/docker/workspace/src/webots_simulations/protos/my_robot.proto`
- defining robot axis, etc.

има дефинирани камери и други, така че не нужно да правим нещо специално
- range finder, camera, led, gyroscopes, etc.

## Undistortion algorithms
Променяме на изгледа на камерата спрямо шаблон
Цел: калибриране за по-точно предвидване на системите


## Mapping algorithm

намиране на маркери и слагане на елемети в реалното пространство    