# Serialization/Deserialization, file streams and other

|name|class|task|
|-|-|-|
|Output stream|ofstream|	Creates and writes to files| 
|Input stream|ifstream| 	Reads from files|
|File stream|fstream| 	A combination of ofstream and ifstream: creates, reads, and writes to files| 

# Read from file
```cpp
// Input/Output controll
#include <iostream>
// File control
#include <fstream>
```

### file open
```cpp
// file openning 
std::fstream file("path");

// alternative
std::fstream file;
file.open(path);
```
### Closing files
```cpp
// don't forget
file.close();
```
### Safety check
```cpp
//good check
if(!file.is_open())
    throw std::invalid_argument("file not found");
```

#### Important
Sometimes I prefere writing
```cpp
std::cout << "Hello, world\n";
```
because it is faster, but this won't show if there is problem
``` cpp
std::cout << "Hello, world\n";
throw "error";
// no output
```
when we use **std::endl** we force the program to show the text.
Under the hood it calls **os.flush()**. [Docs](https://en.cppreference.com/w/cpp/io/manip/endl)
``` cpp
std::cout << "Hello, world" << std::endl;
throw "error";
// Hello world is outputed, then the error
```

## Reading data

#### Read line, save to char array
```cpp
char input[255];
file.getline(input,255);
```

#### Read line, save to string
```cpp
std::string data;
std::getline(file,data);
```




# Write to file
more information here [w3schools](https://www.w3schools.com/cpp/ref_fstream_ofstream.asp)
#### open file
```cpp
std::ofstream file;
file.open(path);
```

#### write specific number of characters
```cpp
file.write("cat is cool",6); // -> "cat is"
```
#### write with operator <<
```cpp
file << "cat"
```
operation of writing will continue until you close the file
this means you won't override anything by default

```cpp
file.put('a'); // character
```