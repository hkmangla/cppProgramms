#include <iostream>
#include <queue>

using namespace std;
// Some member functions of priority queues are:
// empty(): Returns true if the priority queue is empty and false if the priority queue has at least one element. Its time complexity is O(1).
// pop(): Removes the largest element from the priority queue. Its time complexity is O(logN) where N is the size of the priority queue.
// push(): Inserts a new element in the priority queue. Its time complexity is O(logN) where N is the size of the priority queue.
// size(): Returns the number of element in the priority queue. Its time complexity is O(1).
// top(): Returns a reference to the largest element in the priority queue. Its time complexity is O(1).
int main()
{
    priority_queue<int> pq;
    pq.push(10);
    pq.push(20);
    pq.push(5);
    while(!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }
    return 0;
}