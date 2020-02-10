# Queue

![alt text](https://media.geeksforgeeks.org/wp-content/uploads/geek-queue-1.png)


### Properties:
***
1. Operates in a first in first out **(FIFO)** type of arrangement.
2. Add From the **back**(rear) and delete from the **front**.
3. It is implemented by [deque](https://github.com/ahmedmohamedsakr/Competitive-Programming/blob/mine/STL/Sequence%20Containers/Deque.md) or 
[list](https://github.com/ahmedmohamedsakr/Competitive-Programming/blob/mine/STL/Sequence%20Containers/List.md).
4. Time Complexity of `add/delete` : ` **O(1)** `.

### Functions:
***
1. **push() , emplace()** : add a new element at the end(rear) of the queue , **emplace()** is useful for storage space.
2. **pop()** : deletes the first element(from the front) of the queue.
3. **front()** :  returns a reference to the first element of the queue.
4. **back()** :  returns a reference to the last element of the queue.
5. **empty()** : returns whether the queue is empty or not.
6. **size()** : returns the size of the queue.
7. **swap()** : Exchange the contents of two queues but the queues must be of same type, although sizes may differ.

### C++ code:
***
```cpp
#include <bits/stdc++.h>
using namespace std;
queue<int>q,p;
/*
 queue<int>q;  
 is equal to :
 queue<int,deque<int> >q;
 queue<int,list<int>>q;
*/

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

