/*
 *  graph.hpp
 *
 *  Project: ChristiansScreensaver
 *  Author : Christian J Howard
 *  Date   : 6/3/18
 *  Purpose:
 *
 */

#ifndef graph_hpp
#define graph_hpp

#include <vector>
#include <set>
#include "../math_utility/math_bundle.hpp"


namespace custom {
    
    // get a namespace alias
    namespace math = aSDG::math;
    
    // define a vertex, based on the 2-D point class,
    // that also encloses some vertex data for the graph
    class vertex : public math::point<2> {
    public:
        
        // internal data type
        struct vertex_data {
            double radius;
            double omega;
            double bias;
        };
        
        // ctor/dtor
        vertex() = default;
        vertex(double x, double y);
        
        // methods to get the data
        struct vertex_data& getData();
        const struct vertex_data& getData() const;
        
    private:
        struct vertex_data data;
    };
    
    // tailored graph data structure for the purposes of this screensaver plug-in
    class graph {
    public:
        
        // set a vertex type alias
        using vert_type = vertex;
        
        // ctor/dtor
        graph() = default;
        ~graph() = default;
        
        // modify the state of the graph
        void addVertex(const vert_type& v);
        void addVertex(double x, double y);
        void addEdge(int from_vertex, int to_vertex);
        
        // get an individual vertex
        vert_type& getVertex(int vertex_id);
        const vert_type& getVertex(int vertex_id) const;
        
        // get the set of vertices
        std::vector<vert_type>& getVertices();
        const std::vector<vert_type>& getVertices() const;
        
        // get iterators to traverse edges
        std::set<int>::iterator getConnectivityStartIterator(int from_vertex_id);
        std::set<int>::const_iterator getConnectivityStartIterator(int from_vertex_id) const;
        std::set<int>::iterator getConnectivityEndIterator(int from_vertex_id);
        std::set<int>::const_iterator getConnectivityEndIterator(int from_vertex_id) const;
        
        // clear the graph
        void clear();
        
    private:
        std::vector<vert_type> vertices;
        std::vector<std::set<int>> connectivity;
    };
    
    // method to generate a random graph
    void generateRandomGraph(double width, double height, int num_vertices, graph& G);
    
}

#endif /* graph_hpp */
