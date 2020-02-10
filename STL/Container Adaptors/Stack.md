# Stack

![alt text](https://media.geeksforgeeks.org/wp-content/uploads/geek-stack-1.png)


### Properties:
***
1. Operates in a `last in first out` **`(LIFO)`** type of arrangement.
2. Add and delete From the **`back`**`(top)`.
3. It is implemented by [`deque`](https://github.com/ahmedmohamedsakr/Competitive-Programming/blob/mine/STL/Sequence%20Containers/Deque.md) or 
[`list`](https://github.com/ahmedmohamedsakr/Competitive-Programming/blob/mine/STL/Sequence%20Containers/List.md) or [`vector`](https://github.com/ahmedmohamedsakr/Competitive-Programming/blob/mine/STL/Sequence%20Containers/Vector.md).
4. Time Complexity of `add/delete` : **`O(1)`** .

### Functions:
***
1. **push() , emplace()** : add a new element at the top of the stack,`Time Complexity : O(1)`.
2. **pop()** : deletes the first element(from the top) of the stack,`Time Complexity : O(1)`.
3. **top()** :  returns a reference to the first element of the stack,`Time Complexity : O(1)`.
4. **empty()** : returns whether the stack is empty or not,`Time Complexity : O(1)`.
5. **size()** : returns the size of the stack,`Time Complexity : O(1)`.

### Use stack in your program by using this header file:
```cpp
#include <stack>
```

### Stack is defined as:
```cpp
stack<T> my_stack;
 //or
stack<T, container> my_stack (container_instance);
```
* T is the datatype of elements in the stack like int, float
* container is the data structure used to initialize your stack. This is optionally and `by default`, it will be `deque<T>` and can be set to other values like `vector<T>` or `list<T>`.
* container_instance is the instance of container type.

### Ways To Initialize Stack Based On Container:
```cpp
deque<int>dq(5,100);
vector<int>v(5,100);
list<int>l(5,100);

stack<int,deque<int> >s_deque;     // empty stack.

stack<int,deque<int> >s_deque2(dq); // stack initialized to copy of deque.
stack<int,vector<int> >s_vector(v);  // stack initialized to copy of vector.
stack<int,list<int> >s_list(l);      // stack initialized to copy of list.
```

### Implementation:
***
```cpp
#include <bits/stdc++.h>
using namespace std;
stack<int>s;

void show(stack<int>s)
{
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    puts("");
}

int main()
{
    for(int i=1; i<6; ++i)s.push(i);
    //s.emplace(7);
    cout<<"s: ";
    show(s);
    cout<<"top of stack: "<<s.top()<<endl;
    cout<<"stack size : "<<s.size()<<endl;

    return 0;
}

```

**Output:**
```
s: 5 4 3 2 1
top of stack: 5
stack size : 5
```

