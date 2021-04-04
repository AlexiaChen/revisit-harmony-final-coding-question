# revisit-harmony-final-coding-question

Revisit Harmony Final Coding Question

Because it is not good for my performance in the final round coding question of the interview using English, So I just publish a survy for the coding question and show  that  my thinking process at that time.

The Coding Question:

```txt
Design and implement a priority queue for processing below list of items.
This priority queue must return an item with highest priority(lowest value for priority field) and should not take more than O(1) time.

(Data, Priority)

==================

(8, 1)
(4, 3)
(7, 0)
(3, 0)
(6, 2)
(5, 4)

// returns the data part of the next highest Priority item and remove it
func getNextItem() int {
    // Complexity O(1)
}

func putItem(data int, priority int)  {
    // Complexity <= O(n)
}

main program (output)
==================================

putItem(8,1)
putItem(4,3)
putItem(7,0)
putItem(3,0)

getNextItem() // must return (7, 0)

putItem(6,2)
putItem(5,4)

getNextItem() // must return (3, 0)
getNextItem() // must return (8, 1)
getNextItem() // must return (6, 2)
getNextItem() // must return (4, 3)
getNextItem() // must return (5, 3)

```

At first I saw the question description, I first think I need using C++ standard library <queue>
, it is implemented priority queue this data structure(maybe using min heap and max heap), but I think the key of the coding question may not such easy, maybe cannot use C++ standard library so that I did not ask interviewer: Can I use standard library for priority queue? 

so I cannot implement priority queue using max-heap or min-heap（tree-like data structure） online, it is much more complex, and next, my brain went blank, I have no idea for that. a few minutes after, interviewer  saw that I didn't write any code on the whiteboard, so he shows me some tips:  How to store data?   tree? map ? linked-list ?  Why not linked-list ?   

So I go and review the question and found that it could implemented using single-linked list, maybe the key of question is about using linked-list, but cannot use standard library for linked-list, it must implement by myself, so that I did not ask interviewer: Can I use standard library for linked-list ?

I just do it, and finnally not completed question, cause some corner cases about linked-list


## Correct Question Answer

- the question answer below if could use C++ standard library \<queue\>:

```cpp
// g++ main.cpp -o main
#include <iostream>
#include <queue>

struct Item 
{
public:
    int data_, priority_;
public:
    Item(int data, int priority) {data_ = data; priority_ = priority;}
};


struct compare{
public:
  bool operator()(Item& a,Item& b) 
  {
       return a.priority_ > b.priority_;
  }
};

class PriorityQueue
{
public:
    void putItem(int data, int priority)
    {
        queue.push(Item(data, priority));
    }

    int getNextItem()
    {
        int data = queue.top().data_;
        queue.pop();
        return data;
    }

private:
    std::priority_queue<Item, std::vector<Item>, compare> queue;
};

int main()
{
    PriorityQueue queue;
    queue.putItem(8, 1);
    queue.putItem(4, 3);
    queue.putItem(7, 0);
    queue.putItem(3, 0);

    std::cout << queue.getNextItem() << std::endl;

    queue.putItem(6, 2);
    queue.putItem(5, 4);

    std::cout << queue.getNextItem() << std::endl;
    std::cout << queue.getNextItem() << std::endl;
    std::cout << queue.getNextItem() << std::endl;
    std::cout << queue.getNextItem() << std::endl;
    std::cout << queue.getNextItem() << std::endl;
}
```

- the question answer below if could use C++ standard library \<list\>:

```cpp
```

- the question answer below if could not use C++ standard library about any related data structure:

this is my answer in the final interview, but it is not completed at that time.

```cpp
```

this is my answer now, for completing the question

```cpp
```