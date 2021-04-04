#include <iostream>
#include <list>
#include <algorithm>

struct Item 
{
public:
    int data_, priority_;
public:
    Item(int data, int priority) {data_ = data; priority_ = priority;}
};
class PriorityQueue
{
public:
    void putItem(int data, int priority)
    {
        auto current = queue.begin();
        while(current != queue.end())
        {   
            if(priority < current->priority_)
            {
                
                queue.insert(current, Item(data, priority));
                return;
                
            }
            else
            {
                current++;
            }
        }

        queue.insert(queue.end(), Item(data, priority));
          
      
    }

    int getNextItem()
    {
       if(queue.empty())
       {
           return -1;
       }
       else
       {
           int data = queue.front().data_;
           queue.pop_front();
           return data;
       }
    }

private:
    std::list<Item> queue;
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