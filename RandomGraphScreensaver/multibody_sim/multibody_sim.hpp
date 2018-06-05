/*
 *  multibody_sim.hpp
 *
 *  Project: ChristiansScreensaver
 *  Author : Christian J Howard
 *  Date   : 6/3/18
 *  Purpose:
 *
 */

#ifndef multibody_sim_hpp
#define multibody_sim_hpp

#include "../graph/graph.hpp"

namespace sim {
    
    struct sim_traits {
        double time;
        double dt;
        aSDG::math::point<2> attractor_pos;
    };
    
    void multibody_sim( custom::graph& graph, const sim_traits& traits );
    namespace version2 {
        void multibody_sim( custom::graph& graph, sim_traits& traits );
    }
    
}

#endif /* multibody_sim_hpp */
