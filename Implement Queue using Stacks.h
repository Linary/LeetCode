class Queue {
public:
    
    /***************************************************************************/
    /*  Implement the following operations of a queue using stacks.
    /*  push(x) -- Push element x to the back of queue.
    /*  pop() -- Removes the element from in front of queue.
    /*  peek() -- Get the front element.
    /*  empty() -- Return whether the queue is empty.
    /***************************************************************************/
    
    /***************************************************************************/
    /*  思路：两个栈实现一个队列
    /*  1）压入数据全往输入栈压
    /*  2）弹出时，只要输出栈有数据就从输出栈弹出，否则先从输入栈弹道输出栈，
    /*     再从输出栈取
    /*  3）只有两个栈都为空了才为空
    /***************************************************************************/
    void push(int x) {
        input.push(x);
    }

    void pop(void) {
        peek();
        output.pop();
    }

    int peek(void) {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

    bool empty(void) {
        return input.empty() && output.empty();
    }
private:
    stack<int> input, output;
};