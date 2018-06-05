/*
 *  math_operators.hpp
 *
 *  Project: meshing
 *  Author : Christian J Howard
 *  Date   : 11/28/17
 *  Purpose:
 *
 */

#ifndef math_operators_interface_hpp
#define math_operators_interface_hpp

// useful macros
#define H1 template<int R, int C, typename data>
#define H2 template<int R, int I, int C, typename data>

// include pointtor and matrix headers
#include "point.hpp"
#include "point3.hpp"
#include "mat.hpp"

namespace aSDG {
    namespace math {
        
        // scalar matrix operators
        H1 mat<R,C,data> operator+( const mat<R,C,data> & m, const data & s );
        H1 mat<R,C,data> operator+( const data & s, const mat<R,C,data> & m );
        H1 mat<R,C,data> operator-( const mat<R,C,data> & m, const data & s );
        H1 mat<R,C,data> operator-( const data & s, const mat<R,C,data> & m );
        H1 mat<R,C,data> operator*( const mat<R,C,data> & m, const data & s );
        H1 mat<R,C,data> operator*( const data & s, const mat<R,C,data> & m );
        H1 mat<R,C,data> operator/( const mat<R,C,data> & m, const data & s );
        H1 mat<R,C,data> operator/( const data & s, const mat<R,C,data> & m );
        
        // matrix-pointtor products
        H1 point<R,data> operator*( const mat<R,C,data> & m, const point<C,data> & v );
        H1 point<C,data> operator*( const point<R,data> & v, const mat<R,C,data> & m );
        
        // matrix-matrix products
        H2 mat<R,C,data> operator*( const mat<R,I,data> & m1, const mat<I,C,data> & m2 );
        
    }// end namespace math
}// end namespace aSDG

#undef H1
#undef H2

#include "math_operators.hxx"

#endif /* math_operators_interface_hpp */
