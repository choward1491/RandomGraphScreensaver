/*
 *  compile_time_math.hpp
 *
 *  Project: meshing
 *  Author : Christian J Howard
 *  Date   : 1/8/18
 *  Purpose:
 *
 */

#ifndef compile_time_math_interface_hpp
#define compile_time_math_interface_hpp

#include <stdio.h>

namespace aSDG {
    namespace math {
        template<int N, typename num_type> constexpr num_type factorial();
        
    }// end namespace math
}// end namespace aSDG


#include "compile_time_math.hxx"

#endif /* compile_time_math_interface_hpp */
