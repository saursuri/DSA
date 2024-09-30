/*
Problem Link: https://leetcode.com/problems/design-a-stack-with-increment-operation/description/?envType=daily-question&envId=2024-09-30
Time Complexity: O(1)
Space Complexity: O(n) -> No of elements on the stack
*/

class CustomStack {
    int* mystack;
    int* incstack;
    int indx;
    int maxSize;
public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        mystack = new int[maxSize];
        incstack = new int[maxSize];

        for (int i=0; i<maxSize; i++)
        {
            mystack[i] = 0;
            incstack[i] = 0;
        }

        indx = 0;
    }

    ~CustomStack() {
        delete[] mystack;
        delete[] incstack;
    }
    
    void push(int x) {
        if (indx < maxSize)
        {
            mystack[indx++] = x;
        }
    }
    
    int pop() {
        if (indx > 0)
        {
            int val = mystack[--indx] + incstack[indx];
            if (indx > 0)
            { 
                incstack[indx-1] += incstack[indx];  
            }

            incstack[indx] = 0;
            
            return val;
        }

        return -1;
    }
    
    void increment(int k, int val) {
        if (k < indx)
        {
            incstack[k-1] += val;
        }
        else if (indx > 0)
        {
            incstack[indx-1] += val;
        }
    }
};
