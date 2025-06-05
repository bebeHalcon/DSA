template<class T>
string DGraph<T>::shape() {
    //TODO: return the string with format: [Vertices: <numOfVertex>, Edges: <numOfEdge>]
    return "[Vertices: " +  to_string(countVertex) + ", Edges: " + to_string(countEdge) + "]";
}

template<class T>
bool DGraph<T>::empty() {
    //TODO: return if graph is empty (it doesn't have any vertex and edge)
    return (countVertex == 0);
}

template<class T>
void DGraph<T>::clear() {
    //TODO: remove all edges and vertices of graph.
    while (nodeList) {
        this -> removeVertex(nodeList -> vertex);
    }
    countVertex = 0;
    countEdge = 0;
}
