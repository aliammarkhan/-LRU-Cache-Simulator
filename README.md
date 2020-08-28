# -LRU-Cache-Simulator
In this project I have implemented a simulator which shows the working of a LRU cache. This implementation
deepens our understanding of Cache memory , particularly how a cache works when there is a cache miss. The simulator
is implemented using C++ and making best use of the data structures to enhance the performance of the application.

# Working of LRU-Cahce
When a miss occurs, the cache controller must select a block to be replaced with the desired data. A benefit of directmapped placement is that hardware decisions are simplified—in fact, so simple that there is no choice: Only one block
frame is checked for a hit, and only that block can be replaced. With fully associative or set associative placement, there
are many blocks to choose from on a miss. There are three primary strategies employed for selecting which block to
replace:

1. Select any Random Block
2. Least Recently Used (LRU)
3. FIFO (First in First out)

The strategy used in this project is LRU, in order to reduce the chance of throwing out information that will be needed
soon, accesses to blocks are recorded. Relying on the past to predict the future, the block replaced is the one that has been
unused for the longest time. LRU relies on a corollary of locality: If recently used blocks are likely to be used again, then
a good candidate for disposal is the least recently used block. LRU makes use of the concept of temporal locality.
A virtue of random replacement is that it is simple to build in hardware. As the number of blocks to keep track of
increases, LRU becomes increasingly expensive and is usually only approximated. A common approximation (often
called pseudo-LRU) has a set of bits for each set in the cache with each bit cor- responding to a single way (a way is bank
in a set associative cache; there are four ways in four-way set associative cache) in the cache. When a set is accessed, the
bit corresponding to the way containing the desired block is turned on; if all the bits associated with a set are turned on,
they are reset with the exception of the most recently turned on bit. When a block must be replaced, the processor chooses
a block from the way whose bit is turned off, often randomly if more than one choice is available. This approximates
LRU, since the block that is replaced will not have been accessed since the last time that all the blocks in the set were
accessed

# Setup
The simulator is implemented in C++ , this is a console based application . Following are requirements and
considerations for the project.
1. We have considered the simulated Cache as fully associative.
2. Data structures used in this implementation are arrays,doubly linked lists and Hash table.
3. A block has been simulated as an array in this implementation . For integer data , block size can of minimum 4
Bytes and maximum SIZE_MAX.
4. Data is considered to be integer but since we have used templates so type of data can change and the minimum
and maximum will be set according to the data type.
5. A C++ Compiler is required to run this project.
6. Following built in libraries will be required.
  
    • Iostream
  
    • stdlib
  
    • time.h

# Working
We have used a simple algorithm for this simulator using hash tables and linked list. There are basically only two
methods used for accessing a block in cache that are read and write, this simulator also makes use of only these two
methods for accessing the block.

At first our cache will be empty since no reference has been made for a block, on the first read or write which will result
in a miss , the block will be inserted to the front of the linked list. Consider there are three 3 reads for block 0 ,1 and 2
respectively ,the current state of the linked list will be.

![1](https://user-images.githubusercontent.com/50051546/91594577-8fbd0480-e97b-11ea-93e8-44a3d928595f.png)

Block 0 since was the least recently used will be moved to the back of the list and block 2 which was recenly used will
be right in the front. The state of the hashtable at this particular instance will be:

![2](https://user-images.githubusercontent.com/50051546/91594668-b54a0e00-e97b-11ea-98c8-8bc08ed49b96.png)

Since the hash table uses open chaining so if a block gets mapped to the same key then it will mapped as a linked list of
addresses at that key. Hash table will give us O(1) searching time in the best case. Now if the capacity of cache is 12
bytes and there is another cache miss for block 4 then block 0 will be evicted from cache and block 4 will be added to
the front of the list.

![3](https://user-images.githubusercontent.com/50051546/91594809-efb3ab00-e97b-11ea-9271-81fee8106fdc.png)

Now block 1 be evicted on a cache miss. Linked list will give us an O(1) insertion time.
The overall space complexity is O(n). The General algorithm for this simulation will be:

1. On a cache miss , if the capacity of cache is not full, insert the block to the front of the linked list.
2. On a cache miss , if the capacity is full evict the block at the back of the linked list.
3. On a read or a write to block, move the block to the front of the list.
4. When a block is brought in the cache, put the reference of the node in the hashtable.
5. Clear the reference of the block from the table when the block gets evicted.

# Results
Following table shows the average miss rates and hit rates generated by the simulator on specified block and cache
size

![4](https://user-images.githubusercontent.com/50051546/91595299-c3e4f500-e97c-11ea-9065-473d95f1d9a0.png)

# Conclusion:

This algorithm requires keeping track of what was used when, which is expensive for hardware if one wants to make
sure the algorithm always discards the least recently used item. However it makes use of the temporal locality which
in some cases very useful. This implementation of LRU cache gives the simple idea of the working of cache and its
block eviction policy and how it effects the hits and misses.

# Reference:
- Computer Architecture A Quantitative Approach by John L. Hennessy and David A. Patterson





