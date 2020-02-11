# Priority Queue

![alt text](https://cdn.programiz.com/sites/tutorial2program/files/Introduction.png)


### Properties:
***
1. **Priority Queue is an extension of `queue` with following properties:**
* each element is associated with a `priority` and is served according to its priority.
*If elements with the same priority occur, they are served according to their order in the queue.
*The element with the `highest value` is considered as the `highest` priority element by `default`. However, 
in other case, we can assume the element with the `lowest value` as the highest priority element.
3. It is implemented by [`deque`](https://github.com/ahmedmohamedsakr/Competitive-Programming/blob/mine/STL/Sequence%20Containers/Deque.md) or 
[`list`](https://github.com/ahmedmohamedsakr/Competitive-Programming/blob/mine/STL/Sequence%20Containers/List.md).

### Functions:
***
1. **push() , emplace()** : add a new element at the back of the queue,`Time Complexity : O(1)`.
2. **pop()** : deletes the first element(from the front) of the queue,`Time Complexity : O(1)`.
3. **front()** :  returns a reference to the first element of the queue,`Time Complexity : O(1)`.
4. **back()** :  returns a reference to the last element of the queue,`Time Complexity : O(1)`.
5. **empty()** : returns whether the queue is empty or not,`Time Complexity : O(1)`.
6. **size()** : returns the size of the queue,`Time Complexity : O(1)`.
7. **swap()** : Exchange the contents of two queues but the queues must be of same type, although sizes may differ,`Time Complexity : O(n)`.


### Use queue in your program by using this header file:
```cpp
#include <queue>
```

### queue is defined as:
```cpp
queue<T> my_queue;
 //or
queue<T, container> my_queue (container_instance);
```
* T is the datatype of elements in the queue like int, float
* container is the data structure used to initialize your queue. This is optionally and `by default`, it will be `deque<T>` and can be set to `list<T>`.
* container_instance is the instance of container type.

### Ways To Initialize queue Based On Container:
```cpp
deque<int>dq(5,100);
list<int>l(5,100);

queue<int,deque<int> >q_deque;     // empty queue.

queue<int,deque<int> >q_deque2(dq); // queue initialized to copy of deque.
queue<int,list<int> >q_list(l);      // queue initialized to copy of list.
```

### Implementation:
***
```cpp
#include <bits/stdc++.h>
using namespace std;
queue<int>q,p;

void show(queue<int>q)
{
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    puts("");
}

int main()
{
    for(int i=1; i<6; ++i)q.push(i);
    for(int i=6;i<11;++i)p.push(i);
    //q.emplace(7);
    cout<<"q elements: ";
    show(q);
    cout<<"p elements: ";
    show(p);
    cout<<"q.front : "<<q.front()<<endl;
    cout<<"q.back : "<<q.back()<<endl;
    cout<<"q.size : "<<q.size()<<endl;
    
    /*
    q.swap(p);
    cout<<"after swap: \n";
    cout<<"q elements: ";
    show(q);
    cout<<"p elements: ";
    show(p);
    */
    return 0;
}

```

**Output:**
```
q elements: 1 2 3 4 5
p elements: 6 7 8 9 10
q.front : 1
q.back : 5
q.size : 5
```

