#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

struct Node {
    int key;
    int value;
    int freq;
    list<int>::iterator it;
};

class LFUCache {
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (!keyToNode.count(key))
            return -1;

        Node &node = keyToNode[key];
        touch(node);
        return node.value;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        // If key already exists, update value and frequency
        if (keyToNode.count(key)) {
            Node &node = keyToNode[key];
            node.value = value;
            touch(node);
            return;
        }

        // Cache is full, remove LFU element
        if (keyToNode.size() == capacity) {
            int keyToEvict = freqToList[minFreq].back();
            freqToList[minFreq].pop_back();

            if (freqToList[minFreq].empty())
                freqToList.erase(minFreq);

            keyToNode.erase(keyToEvict);
        }

        // Insert new key with frequency = 1
        minFreq = 1;
        freqToList[1].push_front(key);

        Node node;
        node.key = key;
        node.value = value;
        node.freq = 1;
        node.it = freqToList[1].begin();

        keyToNode[key] = node;
    }

private:
    int capacity;
    int minFreq;

    unordered_map<int, Node> keyToNode;
    unordered_map<int, list<int>> freqToList;

    void touch(Node &node) {
        int prevFreq = node.freq;

        // Remove key from old frequency list
        freqToList[prevFreq].erase(node.it);

        if (freqToList[prevFreq].empty()) {
            freqToList.erase(prevFreq);

            if (minFreq == prevFreq)
                minFreq++;
        }

        // Increase frequency
        node.freq++;

        // Insert into new frequency list
        freqToList[node.freq].push_front(node.key);
        node.it = freqToList[node.freq].begin();
    }
};

int main() {
    LFUCache cache(2);

    cache.put(1, 10);
    cache.put(2, 20);

    cout << "Get 1 : " << cache.get(1) << endl;

    cache.put(3, 30);

    cout << "Get 2 : " << cache.get(2) << endl;
    cout << "Get 3 : " << cache.get(3) << endl;

    cache.put(4, 40);

    cout << "Get 1 : " << cache.get(1) << endl;
    cout << "Get 3 : " << cache.get(3) << endl;
    cout << "Get 4 : " << cache.get(4) << endl;

    return 0;
}

/*
Logic:
The LFU (Least Frequently Used) Cache stores key-value pairs while keeping track of how many times each key has been accessed. Every node contains its key, 
value, current frequency, and an iterator pointing to its position inside a frequency list. Two hash maps are maintained: one maps each key to its corresponding 
node, while the other maps each frequency to a doubly linked list containing all keys having that frequency. The front of each list stores the most recently used 
key among that frequency, whereas the back stores the least recently used. Whenever a key is accessed using get() or updated using put(), its frequency increases 
by one. The key is removed from its old frequency list and inserted at the front of the new frequency list. If the old list becomes empty and it was the minimum 
frequency, the minimum frequency is updated. When inserting a new key into a full cache, the key with the smallest frequency (minFreq) is removed. If multiple keys have the same minimum frequency, the least recently used one (the back of the list) is evicted. Because all insertions, deletions, updates, and lookups are performed using hash maps and linked lists, every operation executes in O(1) time.
*/
