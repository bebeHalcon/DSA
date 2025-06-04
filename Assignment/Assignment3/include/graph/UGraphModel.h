/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   UGraphModel.h
 * Author: LTSACH
 *
 * Created on 24 August 2020, 15:16
 */

#ifndef UGRAPHMODEL_H
#define UGRAPHMODEL_H

#include "graph/AbstractGraph.h"
#include "stacknqueue/Queue.h"

//////////////////////////////////////////////////////////////////////
///////////// UGraphModel: Undirected Graph Model ////////////////////
//////////////////////////////////////////////////////////////////////

template <class T>
class UGraphModel : public AbstractGraph<T>
{
private:
public:
    // class UGraphAlgorithm;
    // friend class UGraphAlgorithm;

    UGraphModel(
        bool (*vertexEQ)(T &, T &),
        string (*vertex2str)(T &)) : AbstractGraph<T>(vertexEQ, vertex2str)
    {
    }

    void connect(T from, T to, float weight = 0)
    {
        // TODO
        typename AbstractGraph<T>::VertexNode* fromNode = this -> getVertexNode(from);
        typename AbstractGraph<T>::VertexNode* toNode = this -> getVertexNode(to);
        
        // if (!fromNode) throw VertexNotFoundException(vertex2str(from));
        // if (!toNode) throw VertexNotFoundException(vertex2str(to));
        if (!(fromNode && toNode)) throw VertexNotFoundException("Vertex doesn't exist!");

        fromNode -> connect(toNode, weight);
        if (from != to)
            toNode -> connect(fromNode, weight);
    }

    void disconnect(T from, T to)
    {
        // TODO
        typename AbstractGraph<T>::VertexNode* fromNode = this -> getVertexNode(from);
        typename AbstractGraph<T>::VertexNode* toNode = this -> getVertexNode(to);
        
        // if (!fromNode) throw VertexNotFoundException(vertex2str(from));
        // if (!toNode) throw VertexNotFoundException(vertex2str(to));
        if (!(fromNode && toNode)) throw VertexNotFoundException("Vertex doesn't exist!");

        // Edge* edge = fromNode -> getEdge(toNode);
        // if (!edge) throw EdgeNotFoundException(vertex2str(from) + ", " + vertex2str(to));

        if (!(fromNode -> getEdge(toNode))) throw EdgeNotFoundException(this -> vertex2str(from) + ", " + this -> vertex2str(to));
          
        fromNode -> removeTo(toNode);
        if (from != to)
            toNode -> removeTo(fromNode);
    }

    void remove(T vertex)
    {
        // TODO
        typename AbstractGraph<T>::VertexNode* temp = this -> getVertexNode(vertex);
        if (!temp) throw VertexNotFoundException(this -> vertex2str(vertex));

        auto inwardEdges = this -> getInwardEdges(vertex);
        for (auto it = inwardEdges.begin(); it != inwardEdges.end(); ++it)
        {
            auto node = this -> getVertexNode(*it);
            node -> removeTo(temp);
            temp -> removeTo(node);
        }

        this -> nodeList.removeItem(temp);
    }

    static UGraphModel<T> *create(
        T *vertices, int nvertices, Edge<T> *edges, int nedges,
        bool (*vertexEQ)(T &, T &),
        string (*vertex2str)(T &))
    {
        // TODO
        UGraphModel<T>* graph = new UGraphModel<T>(vertexEQ, vertex2str);

		for (int i = 0; i < nvertices; i++) {
			graph -> add(vertices[i]);
		}

		for (int i = 0; i < nedges; i++) {
			graph -> connect(edges[i].from, edges[i].to, edges[i].weight);
		}
        
		return graph;
    }
};

#endif /* UGRAPHMODEL_H */
