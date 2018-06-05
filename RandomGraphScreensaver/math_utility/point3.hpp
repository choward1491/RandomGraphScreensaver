/*
 *  point3.hpp
 *
 *  Project: meshing
 *  Author : Christian J Howard
 *  Date   : 11/28/17
 *  Purpose:
 *
 */

#ifndef point3_interface_hpp
#define point3_interface_hpp

#include "point.hpp"

namespace aSDG {
    namespace math {
        
        template<typename num_t>
        class point<3,num_t> {
        public:
            
            // specify typedefs
            typedef num_t num_type;
            
            // specify useful constexpr
            static constexpr int ndims = 3;
            
            //ctor/dtor
            point();
            point( num_t x, num_t y, num_t z);
            ~point() = default;
            
            // methods for cross products
            point cross( const point & v ) const;
            void cross( const point & v, point & output) const ;
            
            // specify accessor methods
            num_t & operator[](int idx);
            const num_t & operator[](int idx) const;
            
            // specify norm-like methods
            num_t dot( const point & v ) const;
            num_t mag() const;
            num_t magsq() const;
            void normalize();
            point getNormal() const;
            
            // operator = overload
            void operator=( const num_t & s );
            
            // mathematical operators
            point operator+( const point & v ) const;
            point operator-( const point & v ) const;
            point operator*( const point & v ) const;
            point operator/( const point & v ) const;
            point operator+( const num_t & d_ ) const;
            point operator-( const num_t & d_ ) const;
            point operator*( const num_t & d_ ) const;
            point operator/( const num_t & d_ ) const;
            
            // print method
            void print() const;
            
        protected:
            num_t d[ndims];
        };
        
    }// end namespace math
}// end namespace aSDG


#include "point3.hxx"

#endif /* point3_interface_hpp */
