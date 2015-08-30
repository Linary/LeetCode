class Stack {
    /****************************************************************/
    /*  Implement the following operations of a stack using queues.
    /*  push(x) -- Push element x onto stack.
    /*  pop() -- Removes the element on top of the stack.
    /*  top() -- Get the top element.
    /*  empty() -- Return whether the stack is empty.
    /****************************************************************/
    
    /****************************************************************/
    /*  思路：用队列实现一个栈
    /*  1）压入元素时加到队列末尾
    /*  2）并把末尾前面的元素全部弹出并再次压入队尾
    /****************************************************************/
public:
    queue<int> que;
    // Push element x onto stack.
    void push(int x) {
        que.push(x);
        for(int i = 0;i < que.size() - 1; ++i){
            que.push(que.front());
            que.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        que.pop();
    }

    // Get the top element.
    int top() {
        return que.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return que.empty();
    }
};