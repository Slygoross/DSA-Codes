void insertAtBottom(stack<int>& s, int x) {
    // Base case: if the stack is empty, push the element
    if (s.empty()) {
        s.push(x);
        return;
    }

    // Pop all elements and insert x at the bottom recursively
    int temp = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(temp);
}

// Function to reverse the stack using recursion
void reverseStack(stack<int>& s) {
    // Base case: if the stack is empty or has only one element
    if (s.size() <= 1) {
        return;
    }

    // Pop the top element
    int temp = s.top();
    s.pop();

    // Reverse the remaining stack
    reverseStack(s);

    // Insert the popped element at the bottom of the reversed stack
    insertAtBottom(s, temp);
}