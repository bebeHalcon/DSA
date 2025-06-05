template<class T>
typename DGraph<T>::VertexNode* DGraph<T>::getVertexNode(T vertex) {
    //TODO: Iterate through the Node list of the graph 
    //      check if any vertexNode contains vertex. 
    //      If such a vertexNode exists, return it; otherwise, return nullptr.
    VertexNode* curr = this -> nodeList;
    while (curr){
        if (curr -> vertex == vertex) return curr;
        curr = curr -> next;
    }
    return nullptr;
    
}

template<class T>
void DGraph<T>::add(T vertex) {
    //TODO: create a new vertexNode with vertex.
    
    //TODO: add new vertexNode to the end of Node list of the graph.
    
    //TODO: increase the countVertex.
    VertexNode* newNode = new VertexNode(vertex);
    
    if (!nodeList){
        this -> nodeList = newNode;
    }
    else {
        VertexNode* prev = this -> nodeList;
        while (prev -> next) prev = prev -> next;
        prev -> next = newNode;
    }
    this -> countVertex++;
}

template <class T>
void DGraph<T>::connect(T from, T to, float weight) {
    //TODO: get vertexNode with "from" and vertexNode with "to".
    VertexNode* nodeFrom = getVertexNode(from);
    VertexNode* nodeTo = getVertexNode(to);
    
    //TODO: If either of the two vertexNode objects does not exist, 
    //      throw an exception: VertexNotFoundException("Vertex doesn't exist!").
    if (!nodeFrom || ! nodeTo) throw VertexNotFoundException("Vertex doesn't exist!");
    
    //TODO: connect "from" vertexNode to "to" vertexNode. 
    //      If a new edge is created, increase the countEdge.
    if(nodeFrom -> connectTo(nodeTo, weight)) this -> countEdge++;
}
