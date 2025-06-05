Node* rotateRight(Node* root) {
    //TODO: Rotate and return new root after rotate
    Node* temp = root -> pLeft;
    root -> pLeft = temp -> pRight;
    temp -> pRight = root;
    root = temp;
    return root;
}

Node* rotateLeft(Node* root) {
    //TODO: Rotate and return new root after rotate
    Node *temp = root -> pRight;
    root -> pRight = temp -> pLeft;
    temp -> pLeft = root;
    root = temp;
    return root;
}

int getBalance(Node *subroot) {
        if (!subroot) return 0;
        return getHeightRec(subroot->pLeft) - getHeightRec(subroot->pRight);
    }

Node* helpAdd(Node* node, T value) {
    if (!node) 
        return new Node(value);
    if (value < node->data) 
        node->pLeft = helpAdd(node->pLeft, value);
    else if (value > node->data) 
        node->pRight = helpAdd(node->pRight, value);
    else 
        return node;
        
    int h = getBalance(node);
    if (node->pLeft) {
        if (h > 1 && value < node->pLeft->data) // R-rotate
            return rotateRight(node);
        if (h > 1 && value > node->pLeft->data) { // LR-rotate
            node->pLeft = rotateLeft(node->pLeft);
            return rotateRight(node);
        }
    }

    if (node->pRight) {
        if (h < -1 && value > node->pRight->data) // L-rotate
            return rotateLeft(node);
        if (h < -1 && value < node->pRight->data) { // RL-rotate
            node->pRight = rotateRight(node->pRight);
            return rotateLeft(node);
        }
    }
    return node; // no rotate require
}

void insert(const T &value) {
    this->root = helpAdd(this->root, value);
}

int getNodeHeight(Node* node) {
    return node ? getHeightRec(node) : 0;
}

int getBalanceFactor(Node* node) {
    if (!node) return 0;
    return getNodeHeight(node->pLeft) - getNodeHeight(node->pRight);
}

Node* findMin(Node* node) {
    if (!node) return nullptr;
    while (node->pLeft) {
        node = node->pLeft;
    }
    return node;
}

Node* findMax(Node* node) {
    if (!node) return nullptr;
    while (node->pRight) {
        node = node->pRight;
    }
    return node;
}

Node* rebalance(Node* node) {
    if (!node) return nullptr;

    int balance = getBalanceFactor(node);
    if (balance > 1) {
        int leftBalance = getBalanceFactor(node->pLeft);
        if (leftBalance >= 0) {
            return rotateRight(node);
        } else {
            node->pLeft = rotateLeft(node->pLeft);
            return rotateRight(node);
        }
    }
    
    if (balance < -1) {
        int rightBalance = getBalanceFactor(node->pRight);
        if (rightBalance <= 0) {
            return rotateLeft(node);
        } else {
            node->pRight = rotateRight(node->pRight);
            return rotateLeft(node);
        }
    }

    return node;
}

Node* helpDel(Node* node, const T& value) {
    if (!node) return nullptr;

    if (value < node->data) {
        node->pLeft = helpDel(node->pLeft, value);
    }
    else if (value > node->data) {
        node->pRight = helpDel(node->pRight, value);
    }
    else {
        if (!node->pLeft && !node->pRight) {
            delete node;
            return nullptr;
        }
        
        if (!node->pLeft || !node->pRight) {
            Node* child = node->pLeft ? node->pLeft : node->pRight;
            delete node;
            return child;
        }
        
        Node* pred = findMax(node->pLeft);
        node->data = pred->data;
        node->pLeft = helpDel(node->pLeft, pred->data);
    }
    
    return rebalance(node);
}

void remove(const T& value) {
    if (!root) return;
    root = helpDel(root, value);
}

void helpPrint(Node* node) {
    if (!node) return;

    helpPrint(node->pLeft);
    cout << node->data << " ";
    helpPrint(node->pRight);
}

void printInorder() {
    //TODO
    helpPrint(root);
}

bool helpSearch(Node* node, T value) {
    if (!node) return false;

    if (value < node->data) return helpSearch(node->pLeft, value);
    else if (value > node->data) return helpSearch(node->pRight, value);
    else return true;
}

bool search(const T &value) {
    //TODO
    return helpSearch(root, value);
}
