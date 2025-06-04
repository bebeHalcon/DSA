/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TopoSorter.h
 * Author: ltsach
 *
 * Created on July 11, 2021, 10:21 PM
 */

#ifndef TOPOSORTER_H
#define TOPOSORTER_H
#include "graph/DGraphModel.h"
#include "list/DLinkedList.h"
#include "sorting/DLinkedListSE.h"

template<class T>
class TopoSorter{
public:
    static int DFS;
    static int BFS; 
    
protected:
    DGraphModel<T>* graph;
    int (*hash_code)(T&, int);
    
public:
    TopoSorter(DGraphModel<T>* graph, int (*hash_code)(T&, int)=0){
        //TODO
        this -> graph = graph;
        this -> hash_code = hash_code;
    }

    DLinkedList<T> sort(int mode=0, bool sorted=true){
        //TODO
        if (mode == BFS) return bfsSort(sorted);  
        return dfsSort(sorted);
    }

    DLinkedList<T> bfsSort(bool sorted=true){ 
        //TODO
        DLinkedListSE<T> topo;
        xMap<T, int> indegreeMap = vertex2inDegree();
        DLinkedListSE<T> listZero = listOfZeroInDegrees();
        if (sorted && !listZero.empty())
            listZero.sort();

        Queue<T> q;
        for (const auto &vertex : listZero)
            q.push(vertex);

        while (!q.empty())
        {
            T vertex = q.pop();
            topo.add(vertex);
            DLinkedListSE<T> neighbors = graph -> getOutwardEdges(vertex);
            if (sorted && !neighbors.empty())
                neighbors.sort();

            for (const auto &neighbor : neighbors)
            {
                if (q.contains(neighbor) || topo.contains(neighbor))
                    continue;

                int inDegree = indegreeMap.get(neighbor) - 1;
                indegreeMap.put(neighbor, inDegree);
                if (inDegree == 0)
                    q.push(neighbor);
            }
        }
        return topo;
    }

    DLinkedList<T> dfsSort(bool sorted=true){
        //TODO
        DLinkedListSE<T> topo;
        xMap<T, int> outdegreeMap = vertex2outDegree();
        DLinkedListSE<T> listZero = listOfZeroInDegrees();
        if (sorted && !listZero.empty())
            listZero.sort();

        Stack<T> st;
        for (const auto &vertex : listZero)
            st.push(vertex);

        while (!st.empty())
        {
            T vertex = st.peek();
            int outDegree = outdegreeMap.get(vertex);
            if (outDegree == 0)
            {
                st.pop();
                topo.add(0, vertex);
            }
            else
            {
                DLinkedListSE<T> neighbors = graph -> getOutwardEdges(vertex);
                if (sorted && !neighbors.empty())
                    neighbors.sort();

                for (const auto &neighbor : neighbors)
                {
                    if (topo.contains(neighbor))
                        continue;

                    if (st.contains(neighbor))
                        st.remove(neighbor);
                    st.push(neighbor);
                }
                outdegreeMap.put(vertex, 0);
            }
        }
        return topo;
    }

protected:

    //Helper functions
    xMap<T, int> vertex2inDegree()
    {
        xMap<T, int> map(this -> hash_code);
        for (auto it = this -> graph -> begin(); it != this -> graph -> end(); ++it)
        {
            T vertex = *it;
            int inDegree = this -> graph -> inDegree(vertex);
            map.put(vertex, inDegree);
        }
        return map;
    }

    xMap<T, int> vertex2outDegree()
    {
        xMap<T, int> map(this -> hash_code);
        for (auto it = this -> graph -> begin(); it != this -> graph -> end(); ++it)
        {
            T vertex = *it;
            int outDegree = this -> graph -> outDegree(vertex);
            map.put(vertex, outDegree);
        }
        return map;
    }

    DLinkedListSE<T> listOfZeroInDegrees()
    {
        DLinkedListSE<T> listZero;
        for (auto it = this -> graph -> begin(); it != this -> graph -> end(); ++it)
        {
            T vertex = *it;
            int inDegree = this -> graph -> inDegree(vertex);
            if (inDegree == 0)
                listZero.add(vertex);
        }
        return listZero;
    }

}; //TopoSorter
template<class T>
int TopoSorter<T>::DFS = 0;
template<class T>
int TopoSorter<T>::BFS = 1;

/////////////////////////////End of TopoSorter//////////////////////////////////


#endif /* TOPOSORTER_H */

