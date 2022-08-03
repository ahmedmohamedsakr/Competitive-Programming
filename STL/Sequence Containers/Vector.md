# Vector

![alt text](https://github.com/ahmedmohamedsakr/desktop-tutorial/blob/train/hi/vectors.jpg)

### Properties:
***
1. Vectors are the same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted, with their storage being handled automatically by the container.
2. Vector elements are placed in contiguous storage so that they can be accessed and traversed using iterators.
3. Inserting at the end takes differential time, as sometimes the array may need to be extended.Removing the last element takes only constant time because no resizing happens. 
4. Inserting and erasing at the beginning or in the middle is linear in time.

### Vectors vs Array in C++:
***
Comparisons   | Vector        | Array         |
 ---  | --- | --- |
Structure|template class and is C++ only construct|built-in language construct and present in both C and C++|
implementation|dynamic arrays|statically or dynamically <br /> <ul><li>int array[100];`// Static Implementation` </li><li>int* arr = new int[100];`// Dynamic Implementation`</li></ul>|
memory allocation|heap memory|<ul><li>heap memory:`if it is implemented dynamically`</li><li>stack memory:`if it is implemented statically`</li></ul>|
size|resizable|fixed size|
memory|occupy more memory than Array|memory efficient|

<br/>

### To use vectors, we need to include the vector header file in our program:
***
```cpp
#include <vector>
```
### Declaration
***
```cpp
//(1) empty container constructor (default constructor)
vector<T> vector_name;  //The type parameter <T> specifies the type of the vector.
//(2) fill constructor
 vector<T> vector_name(n,val);   //Constructs a container with n elements. Each element is a copy of val.
//(3) range constructor
vector<T> vector_name(first,last);  //first & last : Input iterators to the initial and final positions in a range. 
//The range used is [first,last), which includes all the elements between first and last, including the element pointed by first but not the element pointed by last.
//(4) copy constructor
vector<T> vector_name(x);  //x: Another vector object of the same type
```
### Initialization
***
```cpp
vector<int> vector1 = {1, 2, 3, 4};
//or
vector<int> vector2 {1, 2, 3, 4};

vector<int> first;                                // empty vector of ints (default constructor)
vector<int> second (4,100);                       // four ints with value 100 (fill constructor)
vector<int> third (second.begin(),second.end());  // iterating through second (range constructor)
vector<int> fourth (third);                       // a copy of third (compy construcotr)

//the iterator constructor can also be used to construct from arrays:
int myints[] = {16,2,77,29};
vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );  // (copy constructor)
```
### Functions:
***
### `1. Iterators:`
Function|Return Value|Parameters|Description|Complexity|
 --- | --- | --- | --- | --- |
begin()|iterator|none|Returns an iterator to the beginning of the sequence container.|O(1)|
end()|iterator|none|Returns an iterator pointing to the theoretical element that follows the last element in the vector.|O(1)|
rbegin()|reverse_iterator|none|Returns a reverse iterator pointing to the last element in the vector.|O(1)|
rend()|reverse_iterator|none|Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector.|O(1)|
cbegin()|const_iterator|none|Returns a constant iterator pointing to the first element in the vector.|O(1)|
cend()|const_iterator|none|Returns a constant iterator pointing to the theoretical element that follows the last element in the vector.|O(1)|
crbegin()|const_reverse_iterator|none|Returns a constant reverse iterator pointing to the last element in the vector.|O(1)|
crend()|const_reverse_iterator|none|Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector.|O(1)|
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    for(int i=1; i<6; ++i)v.push_back(i);
    cout<<"vector elements: ";
    for(vector<int>::iterator it=v.begin(); it!=v.end(); it++)cout<<*it<<" ";
    cout<<endl;
    //v.begin()
    cout<<"begin: "<<*v.begin()<<endl;
    //v.end()
    cout<<"end: "<<*(v.end()-1)<<endl; //return the last element.
    cout<<"element past the end: "<<*v.end()<<endl;  //return an element past the end of the sequence.
    //cbegin and cend just like begin and end but they return a constant iterator.
    //v.rbegin()
    cout<<"rbegin: "<<*v.rbegin()<<endl;  //return the last element.
    //v.rend()
    cout<<"rend: "<<*(v.rend()-1)<<endl; //return the first element.
    cout<<"element preceding the first: "<<*v.rend()<<endl; //return an element preceding the first element in the vector.
    //crbegin and crend just like rbegin and rend but they return a constant iterator.
    return 0;
}
```
`Output`
```
vector elements: 1 2 3 4 5
begin: 1
end: 5
element past the end: 0
rbegin: 5
rend: 1
element preceding the first: 268494464
```
### `2. Capacity:`
Function|Return Value|Parameters|Description|Complexity|
 --- | --- | --- | --- | --- |
size()|size_type|none|Returns the number of elements in the vector.|O(1)|
max_size()|size_type|none|Returns the maximum number of elements that the vector can hold.|O(1)|
resize()|none|size_type n|Resizes the container so that it contains n elements|O(N)|
capacity()|size_type|none|Returns the size of the storage space currently allocated for the vector, expressed in terms of elements.|O(1)|
empty()|bool|none|Returns whether the vector is empty|O(1)|
reserve()|none|size_type n|Requests that the vector capacity be at least enough to contain n elements.|O(N)|
shrink_to_fit()|none|none|Requests the container to reduce its capacity to fit its size.|O(N)|

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    for(int i=1; i<6; ++i)v.push_back(i);
    
    if(v.empty())cout<<"vector is empty."<<endl;
    else cout<<"vector is not empty."<<endl;
    
    cout<<"vector size: "<<v.size()<<endl;
    cout<<"vector max_size: "<<v.max_size()<<endl;
    v.resize(4);
    cout<<"vector size after resize: "<<v.size()<<endl;
    
    cout<<"vector capacity: "<<v.capacity()<<endl;
    v.shrink_to_fit();
    cout<<"vector capacity after shrink to fit: "<<v.capacity()<<endl;
    v.reserve(10);
    cout<<"vector capacity after reserve: "<<v.capacity()<<endl;
    
    cout<<"vector elements: ";
    for(vector<int>::iterator it=v.begin(); it!=v.end(); it++)cout<<*it<<" ";
    cout<<endl;

    return 0;
}
```
`Output`
```
vector is not empty.
vector size: 5
vector max_size: 4611686018427387903
vector size after resize: 4
vector capacity: 8
vector capacity after shrink to fit: 4
vector capacity after reserve: 10
vector elements: 1 2 3 4
```
### `3. Element access:`
Function|Return Value|Parameters|Description|Complexity|
 --- | --- | --- | --- | --- |
operator[]| reference|size_type n|Returns a reference to the element at position n in the vector container.|O(1)|
at()|reference|size_type n|<ul><li>Returns a reference to the element at position n in the vector.</li><li>The function automatically checks whether n is within the bounds of valid elements in the vector, throwing an out_of_range exception if it is not.</li></ul>|O(1)|
front()|reference|none|Returns a reference to the first element in the vector.|O(1)|
back()|reference|none|Returns a reference to the last element in the vector.|O(1)|
data ()|value_type*|none|Returns a direct pointer to the memory array used internally by the vector to store its owned elements.|O(1)|

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    for(int i=1; i<6; ++i)v.push_back(i);

    cout<<"[] operator: "<<v[0]<<endl;
    cout<<"at(2): "<<v.at(2)<<endl;
    cout<<"front(): "<<v.front()<<endl;
    cout<<"back(): "<<v.back()<<endl;
    //pointer to the first element using data().
    cout<<"value of the first element: "<<*v.data()<<endl;
    
    return 0;
}
```
`Output`
```
[] operator: 1
at(2): 3
front(): 1
back(): 5
value of the first element: 1
```

### `4. Modifiers:`
Function|Return Value|Parameters|Description|Complexity|
 --- | --- | --- | --- | --- |
assign()|none|`1. range:` <ul><li>(first_position, last_position)</li></ul>`2. fill:` <ul><li>(size, value)</li></ul>`3. initializer list:` <ul><li>(initializer_list<value_type> il)</li></ul>|Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.|O(N)|
push_back()|none|value|Adds a new element at the end of the vector.|O(1)|
pop_back()|none|none|Removes the last element in the vector.|O(1)|
insert()|An iterator that points to the first of the newly inserted elements.|`1. Single element:` <ul><li>(position, value)</li></ul>`2. Fill :` <ul><li>(position, size, value)</li></ul>`3. Range :` <ul><li>(insertion_position, first_position, last_position)</li></ul>|Inserts new elements before the element at the specified position, effectively increasing the container size by the number of elements inserted.|O(N)|
erase()|An iterator pointing to the new location of the element that followed the last element erased by the function call.|`1. Single element: `<ul><li>(position)</li></ul>`2. Range element: `<ul><li>(first_position, last_position)</li></ul>|1. Removes from the vector either a `single element` (position) or a `range of elements [first,last)`.<br/>2. The range includes all the elements between first and last, `including the element pointed by first but not the one pointed by last`.|O(N)|
swap()|none|vector& v|Swap the contents of one vector with another vector of same type.Sizes may differ.|O(1)|
clear()|none|none|Removes all elements from the vector.|O(N)|
emplace()|An iterator that points to the newly emplaced element.|(position, element)|The container is extended by inserting a new element at position.|O(N)|
emplace_back()|none|element|Inserts a new element at the end of the vector.|O(1)|

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> first;
    vector<int> second= {2,5,7,9};
    //push_back():
    first.push_back(1);
    //pop_back()
    first.pop_back();    // the vector is empty now.
    //assign(): using fill mode.
    first.assign(4,7);
    cout<<"assign the array with 7 four times using assign():";
    for(auto it:first)cout<<" "<<it;
    //insert(): using fill mode.
    first.insert(first.begin()+2,3,5);
    cout<<"\ninsert 5 at the third position 3 times using insert():";
    for(auto it:first)cout<<" "<<it;
    //erase(): using range erase.
    first.erase(first.begin(),first.begin()+2);
    cout<<"\nerase 2 elements from beginning using erase():";
    for(auto it:first)cout<<" "<<it;
    //swap()
    first.swap(second);
    cout<<"\nswap first vector elements by second vector using swap():";
    for(auto it:first)cout<<" "<<it;
    //emplace()
    first.emplace(first.begin()+1,10);
    cout<<"\ninserting 10 at the second position using emplace():";
    for(auto it:first)cout<<" "<<it;
    //emplace_back()
    first.emplace_back(15);
    cout<<"\ninsert 15 at the end using emplace_back():";
    for(auto it:first)cout<<" "<<it;
    //clear()
    first.clear();
    cout<<"\nvector size after clear: "<<first.size()<<endl;
    return 0;
}
```
`Output`
```
assign the array with 7 four times using assign(): 7 7 7 7
insert 5 at the third position 3 times using insert(): 7 7 5 5 5 7 7
erase 2 elements from beginning using erase(): 5 5 5 7 7
swap first vector elements by second vector using swap(): 2 5 7 9
inserting 10 at the second position using emplace(): 2 10 5 7 9
insert 15 at the end using emplace_back(): 2 10 5 7 9 15
vector size after clear: 0
```