 Node* addRec(Node* root, T value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root -> value) {
        root -> pLeft = addRec(root -> pLeft, value);
    } else if (value > root -> value || value == root -> value) {
        root -> pRight = addRec(root -> pRight, value);
    }

    return root;
}

Node* findMin(Node* root) {
    while (root -> pLeft != nullptr) {
        root = root -> pLeft;
    }
    return root;
}

Node* deleteRec(Node* root, T value) {
    if (root == nullptr) {
        return root;
    }

    if (value < root -> value) {
        root -> pLeft = deleteRec(root -> pLeft, value);
    } else if (value > root -> value) {
        root -> pRight = deleteRec(root -> pRight, value);
    } else {
        if (root -> pLeft == nullptr) {
            Node* temp = root -> pRight;
            delete root;
            return temp;
        } else if (root -> pRight == nullptr) {
            Node* temp = root -> pLeft;
            delete root;
            return temp;
        }

        Node* temp = findMin(root -> pRight);

        root -> value = temp -> value;

        root -> pRight = deleteRec(root -> pRight, temp -> value);
    }

    return root;
}
void add(T value) {
    root = addRec(root, value);
}

void deleteNode(T value) {
    root = deleteRec(root, value);
}

T getMin() {
    Node* current = root;
    while (current -> pLeft != nullptr) {
        current = current -> pLeft;
    }
    return current -> value;
}

T getMax() {
    Node* current = root;
    while (current -> pRight != nullptr) {
        current = current -> pRight;
    }
    return current -> value;
}

bool findRec(Node* root, T value) {
    if (root == nullptr) return false;

    if (value == root -> value) return true;
    else if (value < root -> value) return findRec(root -> pLeft, value);
    else return findRec(root -> pRight, value);
}


bool find(T value) {
    return findRec(root, value);
}


T sumRec(Node* root, T l, T r) {
    if (root == nullptr) return 0;

    T sum = 0;
    if (root -> value >= l && root -> value <= r) sum += root -> value;

    if (root -> value > l) sum += sumRec(root -> pLeft, l, r);
    if (root -> value < r) sum += sumRec(root -> pRight, l, r);

    return sum;
}


T sum(T l, T r) {
    return sumRec(root, l, r);
}
