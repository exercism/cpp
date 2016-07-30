#ifndef CIRCULAR_BUFFER_HPP_INCLUDED
#define CIRCULAR_BUFFER_HPP_INCLUDED 1

#include <cstddef>
#include <stdexcept>
#include <iterator>
#include <array>

namespace containers
{
   constexpr auto VERSION = 1;
   
   template<class Container>
   class indexing_iterator : public std::iterator<std::random_access_iterator_tag,typename Container::value_type>
   {
   public:
      using value_type = typename Container::value_type;
      
      indexing_iterator( Container& cont, std::size_t index )
      : cont_(cont), index_(index)
      {}
      indexing_iterator& operator++() { ++index_; return *this; }
      value_type& operator*() { return cont_[index_]; }
      bool operator!=( indexing_iterator const& rhs ) const
      {
         return index_ != rhs.index_ || &cont_ != &rhs.cont_;
      }
      
   private:
      Container&  cont_;
      std::size_t index_;
   };
   
   template<class ValueType,const std::size_t CAPACITY>
   class circular_buffer
   {
   public:
      using value_type = ValueType;
      
      //Basic interface
      value_type const& at( std::size_t index ) const
      {
         if ( index >= size_ )
            throw std::out_of_range( __func__ + std::to_string(index) + ">=" + std::to_string(size_) );
         return underlying_[ (off_ + index) % CAPACITY ];
      }
      value_type& at( std::size_t index )
      {
         if ( index >= size_ )
            throw std::out_of_range( __func__ + std::to_string(index) + ">=" + std::to_string(size_) );
         return (*this)[ index ];
      }
      void push_back( value_type const& val )
      {
         if ( size_ == CAPACITY )
            throw std::out_of_range( std::string(__func__) + " : no more room in buffer of size " + std::to_string(size_) );
         unchecked_push_back( val );
      }
      void force_back( value_type const& val )
      {
         if ( size_ == CAPACITY )
         {
            (*this)[0UL] = val;
            ++off_;
         }
         else
         {
            unchecked_push_back( val );
         }
      }
      void unchecked_push_back( value_type const& val )
      {
         (*this)[size_++] = val;
      }
      void push_front( value_type const& val )
      {
         if ( size_ == CAPACITY )
            throw std::out_of_range( std::string(__func__) + " : no more room in buffer of size " + std::to_string(size_) );
         unchecked_push_front( val );
      }
      void force_front( value_type const& val )
      {
         if ( size_ == CAPACITY )
         {
            (*this)[size_-1] = val;
            --off_;
         }
         else
         {
            unchecked_push_front( val );
         }
      }
      void unchecked_push_front( value_type const& val )
      {
         --off_;
         ++size_;
         (*this)[0UL] = val;
      }
      void pop_back()
      {
         if ( empty() )
            throw std::out_of_range( std::string(__func__) + " : can't pop off the back of an empty buffer!" );
         --size_;
      }
      void pop_front()
      {
         if ( empty() )
            throw std::out_of_range( std::string(__func__) + " : can't pop off the front of an empty buffer!" );
         ++off_;
         --size_;
      }

      //Extended interface
      bool empty() const { return !size_; }
      value_type& operator[] ( std::size_t index )
      {
         return underlying_[ (off_ + index) % CAPACITY ];
      }
      value_type const& operator[] ( std::size_t index ) const
      {
         return underlying_[ (off_ + index) % CAPACITY ];
      }
      
      using iterator       = indexing_iterator<circular_buffer>;
      using const_iterator = indexing_iterator<const circular_buffer>;
      
      iterator       begin()       { return {*this, 0UL  }; }
      iterator       end  ()       { return {*this, size_}; }
      const_iterator begin() const { return {*this, 0UL  }; }
      const_iterator end  () const { return {*this, size_}; }
      
   private:
      std::ptrdiff_t off_ = 0UL;
      std::size_t size_ = 0UL;
      
      //An extra credit test might check for when ctors & dtors are called 
      std::array<value_type,CAPACITY> underlying_;
   };
}

#endif
