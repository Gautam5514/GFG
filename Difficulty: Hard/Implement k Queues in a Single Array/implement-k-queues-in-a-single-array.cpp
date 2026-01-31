class kQueues {
    
    int *arr;
    int *front;
    int *rear;
    int *next;
    int free;
    int n, k;
  public:
    kQueues(int n, int k) {
        // Initialize your data members
        this -> n = n;
        this -> k = k;
        
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        next = new int[n];
        
        // initialize queue as empty
        for(int i = 0; i < k; i++) {
            front[i] = rear[i] = -1;
        }
        // initialize free list
        for(int i = 0; i < n - 1; i++) {
            next[i] = i + 1;
        }
        next[n - 1] = -1;
        free = 0;
    }

    void enqueue(int x, int qi) {
        // enqueue element x into queue i
        if(free == -1) return; // overflow
        int index = free;
        free = next[index]; // take free index
        
        arr[index] = x;
        
        if(front[qi] == -1) {
            front[qi] = index;
        } else {
            next[rear[qi]] = index;
        }
        next[index] = -1;
        rear[qi] = index;
    }

    int dequeue(int qi) {
        // dequeue element from queue i
        if(front[qi] == -1) return -1; // underflow
        
        int index = front[qi];
        front[qi] = next[index];
        // add index back to free list
        next[index] = free;
        free = index;
        return arr[index];
    }

    bool isEmpty(int qi) {
        // check if queue i is empty
        return front[qi] == -1;
    }

    bool isFull() {
        // check if array is full
        return free == -1;
    }
};
