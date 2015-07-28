class Queue {
    private:
        stack<int> mInS;
        stack<int> mOutS;

    private:
        void moveElements() {
            if (mOutS.empty()) {
                while (!mInS.empty()) {
                    mOutS.push(mInS.top());
                    mInS.pop();
                }
            }
        }

    public:
        // Push element x to the back of queue.
        void push(int x) {
            mInS.push(x);
        }

        // Removes the element from in front of queue.
        void pop(void) {
            moveElements();
            mOutS.pop();
        }

        // Get the front element.
        int peek(void) {
            moveElements();
            return mOutS.top();
        }

        // Return whether the queue is empty.
        bool empty(void) {
            return mInS.empty() && mOutS.empty();
        }
};
