/*
 *  compile_time_math.hxx
 *
 *  Project: meshing
 *  Author : Christian J Howard
 *  Date   : 1/8/18
 *  Purpose:
 *
 */

#ifndef compile_time_math_impl_hxx
#define compile_time_math_impl_hxx

// useful macros for defining class methods
#define HEADER template<typename T>
#define CLASS compile_time_math<T>

// template class interface
#include "compile_time_math.hpp"

// implementation details
namespace aSDG {
    namespace math {
        template<int N,typename num_type>
        constexpr num_type factorial() {
            return static_cast<num_type>(N * factorial<N-1,num_type>());
        }
        
        template<>
        constexpr int factorial<0,int>() {
            return 1;
        }
        template<>
        constexpr float factorial<0,float>() {
            return 1.0;
        }
        template<>
        constexpr double factorial<0,double>() {
            return 1.0;
        }
    }// end namespace math
}// end namespace aSDG



// get rid of macro definitions
#undef HEADER
#undef CLASS

#endif /* compile_time_math_impl_hxx */


