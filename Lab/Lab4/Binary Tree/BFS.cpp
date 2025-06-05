void BFS() {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node *current = q.front();
        cout << current -> value << " ";

        if (current -> pLeft) q.push(current -> pLeft);
        if (current -> pRight) q.push(current -> pRight);

        q.pop();
    }
}