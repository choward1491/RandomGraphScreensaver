/*
 *  point.hpp
 *
 *  Project: meshing
 *  Author : Christian J Howard
 *  Date   : 11/28/17
 *  Purpose:
 *
 */

#ifndef point_interface_hpp
#define point_interface_hpp

namespace aSDG {
    namespace math {
        
        /*!
         * \class   point
         * \file    point.hpp
         * \brief   Data structure representing a generic mathematical pointtor
         *
         * This data structure repersents a generic mathematical pointtor and typical operations done on it
         */
        template<int dim, typename num_t = double>
        class point {
        public:
            
            // specify typedefs
            typedef num_t num_type;
            
            // specify useful constexpr
            static constexpr int ndims = dim;
            
            // ctor/dtor
            point();
            ~point() = default;
            
            // specify accessor methods
            num_t & operator[](int idx);
            const num_t & operator[](int idx) const;
            
            // specify norm-like methods
            num_t dot( const point & v ) const;
            num_t mag() const;
            num_t magsq() const;
            void normalize();
            point getNormal() const;
            
            // specify element-wise math operators
            point operator+( const point & v ) const;
            point operator-( const point & v ) const;
            point operator*( const point & v ) const;
            point operator/( const point & v ) const;
            point operator+( const num_t & d ) const;
            point operator-( const num_t & d ) const;
            point operator*( const num_t & d ) const;
            point operator/( const num_t & d ) const;
            
            // overloaded operator =
            void operator=( const num_t & s );
            
            // specify method to get the number of dimensions
            int getNumDimensions() const;
            
            // print method
            void print() const;
            
        protected:
            num_t d[dim];
        };
        
    }// end namespace math
}// end namespace aSDG


#include "point.hxx"

#endif /* point_interface_hpp */
