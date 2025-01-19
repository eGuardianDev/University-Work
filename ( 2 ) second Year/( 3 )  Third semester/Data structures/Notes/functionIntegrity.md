# Writing good functions

### key points
When writting a good function we need to think
1. the arguments we are getting
    - are they manipulating something
    - are they being manipulated
    - what types are being used

2. check for edges cases
    - null values
    - invalid data

*somewhere here is the function logic*

3. memory management
    - Are there pointers
    - Are pointers created
    - Are pointers deleted
4. return type
    - is it reference
    - will it be deleted after function ends
    - is the type correct
    - are we returning pointers
### arguments
#### pass by reference
```cpp
// parsing values
void function(int &data);
```
1. can manipulate the original data
2. safes time and memory -> doesn't use copy operator

#### return by reference
```cpp
int& function(){
    // locally defined, will be deleted after the function is gone
    int data = 0;
    return data;
}
```
this can be a problem, because the function will delete **data** and this will cause a problem.

You can return by reference for classes to save copy constructor call, but use const to prevent changes to the variable if not wanted

```cpp
const int& function(){
    return this->val;
}
```


Using references for trees can be very usefull for functions when nodes are manipulated

``` cpp
void function(Node* &curr){
    // make new instance of function
    // doesn't change anything
    function(curr->left);

    ...

    // changes the previous pointer
    curr = curr->left;
}
```
this function will change curr to be this

*from*
```
  root
       curr
    left
```
*to*
```
  root
     left               curr <- somewhere in heap
```
1. Take a note, that *curr* is still in the heap and needs to be deleted/saved before doing the **change operation**
2. Take a note that *curr* is still having left as its child


#### writing const
write const when argument is not going to be changes
```cpp
void function(const std::string data)
```
very usefull used with references, because it ignores copying and saves memory, but blocks the original data from being changed
```cpp
void function(const std::string &data)
```

##### in classes
when writing classes you can use const in this way
```cpp
class MyClass{
    int val = 0;
    void function(int data) const{
        val = data; // <- error
    }
}
```
this needs to be applied when you want to make
```cpp
const MyClass object;
```
any function that doesn't have const cannot be used

this is why we need to use const when writting operators