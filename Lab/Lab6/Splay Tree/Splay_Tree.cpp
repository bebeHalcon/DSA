void rotateLeft(Node* x) {
    if (!x) return;
    Node* p = x->pParent;
    if (!p) return;

    p->pRight = x->pLeft; 
    if (x->pLeft) {
        x->pLeft->pParent = p;
    }

    x->pLeft = p; 
    x->pParent = p->pParent;

    if (p->pParent) {
        if (p == p->pParent->pLeft) p->pParent->pLeft = x;
        else p->pParent->pRight = x;
    }

    p->pParent = x;

    if (p == root) {
        root = x;
    }
}

void rotateRight(Node* x) {
    if (!x) return;
    Node* p = x->pParent;
    if (!p) return;
    
    p->pLeft = x->pRight;
    if (x->pRight) {
        x->pRight->pParent = p;
    }

    x->pRight = p;
    x->pParent = p->pParent;

    if (p->pParent) {
        if (p == p->pParent->pLeft) p->pParent->pLeft = x;
        else p->pParent->pRight = x;
    }

    p->pParent = x;
    if (p == root) {
        root = x;
    }
}

bool isLeftChild(Node* p) {
    if (!p->pParent) return false;
    return (p->pParent->pLeft == p);
}

Node* bstInsert(int val) {
    if (!root) {
        root = new Node(val);
        return root;
    }
    Node* cur = root;
    Node* par = nullptr;
    while (cur) {
        par = cur;
        if (val < cur->val) {
            cur = cur->pLeft;
        }
        else {
            cur = cur->pRight;
        }
    }
    Node* newNode = new Node(val);
    newNode->pParent = par;
    if (val < par->val) {
        par->pLeft = newNode;
    } else {
        par->pRight = newNode;
    }
    return newNode;
}

Node* findLastAccessed(int val) {
    Node* cur = root;
    Node* last = nullptr;
    while (cur) {
        last = cur;
        if (val == cur->val) {
            return cur; // found
        } else if (val < cur->val) {
            cur = cur->pLeft;
        } else {
            cur = cur->pRight;
        }
    }
    return last; // not found, return last accessed
}

Node* getMaxNode(Node* p) {
    if (!p) return nullptr;
    while (p->pRight) {
        p = p->pRight;
    }
    return p;
}

void splay(Node* p) {
    // To Do
    if (!p) return;
    while (p != root) {
        Node* parent = p->pParent;
        Node* grand = parent ? parent->pParent : nullptr;

        if (parent == root) {
            if (isLeftChild(p)) {
                rotateRight(p);
            } else {
                rotateLeft(p);
            }
        }
        else if (grand) {
            bool pIsLeftChild  = isLeftChild(p);
            bool parentIsLeftChild = isLeftChild(parent);

            if (pIsLeftChild && parentIsLeftChild) {
                rotateRight(parent);
                rotateRight(p);
            } else if (!pIsLeftChild && !parentIsLeftChild) {
                rotateLeft(parent);
                rotateLeft(p);
            }
            else {
                if (pIsLeftChild && !parentIsLeftChild) {
                    rotateRight(p);
                    rotateLeft(p);
                } else {
                    rotateLeft(p);
                    rotateRight(p);
                }
            }
        }
    }
}

void insert(int val) {
    // To Do
    Node* newNode = bstInsert(val);
    splay(newNode);
}

bool search(int val) {
    // To Do
    if (!root) return false;
    Node* accessed = findLastAccessed(val);
    splay(accessed);
    return (root && root->val == val);
}

Node* remove(int val) {
    // To Do
    if (!root) return nullptr;

    Node* accessed = findLastAccessed(val);
    splay(accessed);
    
    if (!root || root->val != val) {
        return nullptr;
    }
    
    Node* removedNode = root;
    Node* leftSubtree = root->pLeft;
    Node* rightSubtree = root->pRight;
    
    if (leftSubtree) leftSubtree->pParent = nullptr;
    if (rightSubtree) rightSubtree->pParent = nullptr;
    root = nullptr;
    
    if (!leftSubtree) {
        root = rightSubtree;
    } else {
        Node* maxNode = getMaxNode(leftSubtree);
        splay(maxNode);
        maxNode->pRight = rightSubtree;
        if (rightSubtree) {
            rightSubtree->pParent = maxNode;
        }
        root = maxNode;
    }
    
    return removedNode;
}

