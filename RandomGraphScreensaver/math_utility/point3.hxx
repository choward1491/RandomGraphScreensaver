/*
 *  point3.hxx
 *
 *  Project: meshing
 *  Author : Christian J Howard
 *  Date   : 11/28/17
 *  Purpose:
 *
 */

#ifndef point3_impl_hxx
#define point3_impl_hxx

// useful macros for defining class methods
#define HEADER template<typename num_t>
#define CLASS point<3,num_t>

// template class interface
#include "point3.hpp"

// implementation details
namespace aSDG {
    namespace math {
            
        HEADER CLASS::point(){
            d[0] = d[1] = d[2] = num_t();
        }
        
        HEADER CLASS::point( num_t x, num_t y, num_t z){
            d[0] = x;
            d[1] = y;
            d[2] = z;
        }
        
        HEADER CLASS CLASS::cross( const point & v ) const {
            point out;
            out.d[0] = d[1]*v.d[2] - d[2]*v.d[1];
            out.d[1] = d[2]*v.d[0] - d[0]*v.d[2];
            out.d[2] = d[0]*v.d[1] - d[1]*v.d[0];
            return out;
        }
        
        HEADER void CLASS::cross( const point & v, point & output) const {
            output.d[0] = d[1]*v.d[2] - d[2]*v.d[1];
            output.d[1] = d[2]*v.d[0] - d[0]*v.d[2];
            output.d[2] = d[0]*v.d[1] - d[1]*v.d[0];
            return output;
        }
        // specify accessor methods
        HEADER num_t & CLASS::operator[](int idx){ return d[idx];}
        HEADER const num_t & CLASS::operator[](int idx) const { return d[idx]; }
        
        // specify norm-like methods
        HEADER num_t CLASS::dot( const point & v ) const {
            return d[0]*v.d[0] + d[1]*v.d[1] + d[2]*v.d[2];
        }
        HEADER num_t CLASS::mag() const {
            return sqrt(magsq());
        }
        HEADER num_t CLASS::magsq() const{
            return d[0]*d[0] + d[1]*d[1] + d[2]*d[2];
        }
        HEADER void CLASS::normalize() {
            num_t mag_ = mag();
            d[0] /= mag_;
            d[1] /= mag_;
            d[2] /= mag_;
        }
        HEADER CLASS CLASS::getNormal() const {
            num_t m = mag();
            return point(d[0]/m,d[1]/m,d[2]/m);
        }
        
        HEADER void CLASS::operator=( const num_t & s ) {
            d[0] = d[1] = d[2] = s;
        }
        
        HEADER CLASS CLASS::operator+( const point & v ) const {
            return point(d[0] + v.d[0], d[1] + v.d[1], d[2] + v.d[2]);
        }
        HEADER CLASS CLASS::operator-( const point & v ) const {
            return point(d[0] - v.d[0], d[1] - v.d[1], d[2] - v.d[2]);
        }
        HEADER CLASS CLASS::operator*( const point & v ) const {
            return point(d[0] * v.d[0], d[1] * v.d[1], d[2] * v.d[2]);
        }
        HEADER CLASS CLASS::operator/( const point & v ) const {
            return point(d[0] / v.d[0], d[1] / v.d[1], d[2] / v.d[2]);
        }
        HEADER CLASS CLASS::operator+( const num_t & d_ ) const {
            return point(d[0] + d_, d[1] + d_, d[2] + d_);
        }
        HEADER CLASS CLASS::operator-( const num_t & d_ ) const {
            return point(d[0] - d_, d[1] - d_, d[2] - d_);
        }
        HEADER CLASS CLASS::operator*( const num_t & d_ ) const {
            return point(d[0] * d_, d[1] * d_, d[2] * d_);
        }
        HEADER CLASS CLASS::operator/( const num_t & d_ ) const {
            return point(d[0] / d_, d[1] / d_, d[2] / d_);
        }
        
        // print method
        HEADER void CLASS::print() const{
            printf("[ %lf, %lf, %lf ]\n",(double)d[0],(double)d[1],(double)d[2]);
        }
        
    }// end namespace math
}// end namespace aSDG


// get rid of macro definitions
#undef HEADER
#undef CLASS

#endif /* point3_impl_hxx */


