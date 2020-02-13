# Priority Queue

![alt text](https://cdn.programiz.com/sites/tutorial2program/files/Introduction.png)


### Properties:
***
1. Priority Queue is an extension of `queue` with following properties:
   * Each element is associated with a `priority` and is served according to its priority.
   * If elements with the same priority occur, they are served according to their order in the queue.
   * The element with the highest value is considered as the highest priority element. However, in other case, we can assume the element with the lowest value as the highest priority element.
2. It is implemented by [`vector`](https://github.com/ahmedmohamedsakr/Competitive-Programming/blob/mine/STL/Sequence%20Containers/Vector.md) or [`deque`](https://github.com/ahmedmohamedsakr/Competitive-Programming/blob/mine/STL/Sequence%20Containers/Deque.md).

### Functions:
***
1. **push() , emplace()** : add a new element at the top of the priority queue and then the queue is rearranged,`Time Complexity : O(nlogn)`.
2. **pop()** : deletes the element at the top of the priority queue,`Time Complexity : O(1)`.
3. **top()** :  returns a reference to the top element of the priority queue,`Time Complexity : O(1)`.
4. **empty()** : returns whether the priority queue is empty or not,`Time Complexity : O(1)`.
5. **size()** : returns the size of the priority queue,`Time Complexity : O(1)`.
6. **swap()** : Exchange the contents of two priority queues but the priority queues must be of same `type and size`,`Time Complexity : O(n)`.


### Use priority queue in your program by using this header file:
```cpp
#include <queue>
```

### priority queue is defined as:
```
priority_queue<T> my_priority_queue;
 //or
priority_queue<T, container> priority_my_queue (container_instance);
priority_queue<T, container,compare function> priority_my_queue (container_instance);
```
* T is the datatype of elements in the priority queue like int, float
* container is the data structure used to initialize your priority queue.`by default`, it will be `vector<T>` and can be set to `deque<T>`,`you must use it when you use compare fuction`.
* container_instance is the instance of container type.`This is optional you can put it or not`.
* compare function responsable for giving priority to elements `by default`, it will be by defualt `less<T>` and can be set to `greater<T>` or you can built your own compare function.

> less\<T\> The element with the highest value is considered as the highest priority element.

> greater\<T\> The element with the lowest value is considered as the highest priority element.

### Ways To Initialize priority queue Based On Container:
```cpp
deque<int>dq(5,100);
vector<int>v(5,100);

priority_queue<int,vector<int> >pq_vector;     // empty priority_queue.

priority_queue<int,vector<int> >pq_vector2(l);      // priority queue initialized to copy of vector.
priority_queue<int,deque<int> >pq_deque(dq); // priority queue initialized to copy of deque.
```

### Ways To Initialize priority queue Based On Compare Function:
```cpp
#include <bits/stdc++.h>
using namespace std;

struct comp
{
    bool operator()(int l,int r)      //equal less<int>
    {
        return l<r;
    }
};

priority_queue <int,vector<int>,less<int> >pq;  //sort elements descending.
priority_queue <int,vector<int>,greater<int> >pq1;  //sort elements ascending.
priority_queue<int,vector<int>,comp>pq2;             //sort depending on compare function.

int main()
{
    for(int i=1; i<7; ++i)pq2.push(i);
    while(!pq2.empty())
    {
        cout<<pq2.top()<<" ";
        pq2.pop();
    }
    return 0;
}

```


### Illustration of Priority Queue:
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

