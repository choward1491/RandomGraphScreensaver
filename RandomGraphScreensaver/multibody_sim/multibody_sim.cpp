/*
 *  multibody_sim.cpp
 *
 *  Project: ChristiansScreensaver
 *  Author : Christian J Howard
 *  Date   : 6/3/18
 *  Purpose:
 *
 */

#include <random>
#include <time.h>
#include "multibody_sim.hpp"

namespace sim {
    
    namespace version2 {
        void multibody_sim( custom::graph& graph, sim_traits& traits ) {
            
            // get the vertices from the graph to update their positions
            auto& vertices = graph.getVertices();
            
            // loop through the vertices and update their position
            double new_time = traits.time + traits.dt;
            int n = vertices.size();
            for(int i = 0; i < n; ++i){
                
                // grab ith vertex and associated data
                auto& vertex = vertices[i];
                auto& data = vertex.getData();
                auto r = (traits.attractor_pos - static_cast<aSDG::math::point<2>&>(vertex));
                auto d = r.mag();
                vertex[0] = traits.attractor_pos[0] + d*cos(data.omega*new_time + data.bias);
                vertex[1] = traits.attractor_pos[1] + d*sin(data.omega*new_time + data.bias);
            }
            
            traits.time = new_time;
        }
    }
    
}
