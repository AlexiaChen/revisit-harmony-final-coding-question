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