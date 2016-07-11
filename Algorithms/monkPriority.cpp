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
    int t;cin>>t;while(t--)
    {
    priority_queue<long long int> pq;
    long long int x,sum = 0,n,k; cin>>n>>k;

     for(int i=0;i<n;i++)
        {
            cin>>x;
            pq.push(x);
        }

        while(k--){
            long long int l = pq.top();
            sum += l;
            pq.pop();
            pq.push(l/2);
        }    
        cout<<sum<<endl;
    }
    
    return 0;
}