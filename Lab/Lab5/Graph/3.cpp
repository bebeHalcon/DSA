template <class T>
bool DGraph<T>::removeEdge(T from, T to) {
    //TODO: get vertexNode with "from" and vertexNode with "to".
    VertexNode* nodeFrom = getVertexNode(from);
    VertexNode* nodeTo = getVertexNode(to);
    
    //TODO: If either of the two vertexNode objects does not exist, 
    //      throw an exception: VertexNotFoundException("Vertex doesn't exist!").
    if (!(nodeFrom && nodeTo)) throw VertexNotFoundException("Vertex doesn't exist!");

    //TODO: Delete the edge between the "from" vertexNode and the "to" vertexNode. (use removeTo method)
    //      If success return true and decrement the countEdge; otherwise, return false; 
    if (nodeFrom -> removeTo(nodeTo)) {
        countEdge--;
        return true;
    }
    return false;
}

template <class T>
void DGraph<T>::removeVertex(T removeVertex) {
    //TODO: get vertexNode with "removeVertex"
    VertexNode* delVertex = getVertexNode(removeVertex);
    
    //TODO: If this vertexNode isn't existed,
    //      throw an exception: VertexNotFoundException("Vertex doesn't exist!").
    if (!delVertex) throw VertexNotFoundException("Vertex doesn't exist!");
    
    //TODO: Iterate through all the vertexNode in the graph's Node list. For each vertexNode:
    //      - Check for an edge from the current vertex to the "removeVertex". 
    //      If such an edge exists, delete it (use removeTo method) and decrement the countEdge. 
    //      - Check for an edge from the "removeVertex" to the current vertex. 
    //      If such an edge exists, delete it (use removeTo method) and decrement the countEdge.
    VertexNode* curr = this->nodeList;
    while (curr) {
        if (curr -> removeTo(delVertex)) countEdge--;
        if (delVertex -> removeTo(curr)) countEdge--;
        curr = curr -> next;
    }
    
    //TODO: Delete the vertexNode containing removeVertex from the Node list of the graph
    //      Decrement the countVertex.
    curr = this -> nodeList;
    VertexNode* prev = nullptr;
    while (curr) {
        if (curr -> vertex == delVertex -> vertex) {
            if (prev) prev -> next = delVertex -> next;
            delete delVertex;
            countVertex--;
            return;
        }
        prev = curr;
        curr = curr -> next;
    }
}
