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
1. **push() , emplace()** : add a new element at the top of the stack , **emplace()** is useful for storage space.
2. **pop()** : deletes the first element(from the top) of the stack.
3. **top()** :  returns a reference to the first element of the stack.
4. **empty()** : returns whether the stack is empty or not,`Time Complexity : O(1)`.
5. **size()** : returns the size of the stack,`Time Complexity : O(1)`.


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

