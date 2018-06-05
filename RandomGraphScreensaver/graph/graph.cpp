/*
 *  graph.cpp
 *
 *  Project: ChristiansScreensaver
 *  Author : Christian J Howard
 *  Date   : 6/3/18
 *  Purpose:
 *
 */

#include <time.h>
#include <random>
#include "graph.hpp"

namespace custom {
    
    vertex::vertex(double x, double y) {
        this->operator[](0) = x;
        this->operator[](1) = y;
    }
    struct vertex::vertex_data& vertex::getData() {
        return data;
    }
    const struct vertex::vertex_data& vertex::getData() const {
        return data;
    }
    
    // modify the state of the graph
    void graph::addVertex(const vert_type& v) {
        vertices.push_back(v);
        connectivity.push_back(std::set<int>());
    }
    void graph::addVertex(double x, double y) {
        vert_type pt;
        pt[0] = x; pt[1] = y;
        vertices.push_back(pt);
        connectivity.push_back(std::set<int>());
    }
    void graph::addEdge(int from_vertex, int to_vertex) {
        connectivity[from_vertex].insert(to_vertex);
    }
    
    // get state from the graph
    typename graph::vert_type& graph::getVertex(int vertex_id) {
        return vertices[vertex_id];
    }
    const typename graph::vert_type& graph::getVertex(int vertex_id) const {
        return vertices[vertex_id];
    }
    std::vector<typename graph::vert_type>& graph::getVertices() {
        return vertices;
    }
    const std::vector<typename graph::vert_type>& graph::getVertices() const {
        return vertices;
    }
    std::set<int>::iterator graph::getConnectivityStartIterator(int from_vertex_id) {
        return connectivity[from_vertex_id].begin();
    }
    std::set<int>::const_iterator graph::getConnectivityStartIterator(int from_vertex_id) const {
        return connectivity[from_vertex_id].begin();
    }
    std::set<int>::iterator graph::getConnectivityEndIterator(int from_vertex_id) {
        return connectivity[from_vertex_id].end();
    }
    std::set<int>::const_iterator graph::getConnectivityEndIterator(int from_vertex_id) const {
        return connectivity[from_vertex_id].end();
    }
    
    void graph::clear() {
        vertices.clear();
        connectivity.clear();
    }
    
    void generateRandomGraph(double width, double height, int num_vertices, graph& G) {
        // init random number generator and various distributions
        std::default_random_engine g(time(nullptr));
        std::uniform_real_distribution<double> U(0,1);
        std::uniform_int_distribution<int> Ui(0,num_vertices-1);
        std::uniform_int_distribution<int> Ur(3, 15);
        std::normal_distribution<double> N(0,1);
        
        // clear out the graph
        G.clear();
        
        // create the random vertices
        
        // define the maximal radius a vertex can be from center
        double r = sqrt(pow(width/4.0,2) + pow(height/4.0,2));
        
        // loop through vertices to assign their properties
        for(int i = 0; i < num_vertices; ++i){
            
            // random distance from center for ith vertex
            double d = U(g)*r + 10;
            
            // random wave bias for ith vertex
            double b = U(g)*2.0*M_PI;
            
            // position of vertex in absolute coordinates
            // and at the initial time of t = 0s
            double x = 0.5*width + d*cos(b);
            double y = 0.5*height + d*sin(b);
            
            // add vertex to the graph
            G.addVertex(x, y);
            
            // grab the vertex data bundle to modify properties
            auto& data = G.getVertex(i).getData();
            
            // assign a random vertex radius
            data.radius = Ur(g);
            
            // assign a random angular rate for the motion
            data.omega = (2*U(g)-1)*1/data.radius;
            
            // assign the wave bias found above
            data.bias = b;
        }
        
        // loop through vertices to create random connections
        for(int k = 0; k < num_vertices; ++k){
            
            // obtain a random probability
            double p = U(g)*0.04;
            
            // loop through other vertices and randomly
            // assign edges with probability p
            for(int i = 0; i < num_vertices; ++i){
                if( U(g) <= p ){ G.addEdge(k, i); }
            }// end for i
        }// end for k
    }
    
}
