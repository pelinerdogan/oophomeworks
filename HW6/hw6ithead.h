
#include <iostream>
#include <cstddef>
#include <iterator> 

#include "hw6head.h"



namespace hw6
{
   template<typename T, size_t SIZE>
   class PFArray<T, SIZE>::normal_iter : public Iterator
   {
      public:
         using iterator_category = std::random_access_iterator_tag;
         using difference_type   = std::ptrdiff_t;
         using value_type        = T;
         using pointer           = value_type*;  
         using reference         = value_type&; 

         friend class const_iter;
         
         normal_iter();
         normal_iter(T* other);
         normal_iter(const const_iter& rightvalue);
         normal_iter(const normal_iter& rightvalue);
         normal_iter(normal_iter&& rightvalue);
         ~normal_iter();
         normal_iter& operator=(const normal_iter& rightvalue);
         normal_iter& operator=(normal_iter&& rightvalue);
         T& operator*();
         T* operator->();
         normal_iter& operator++();
         normal_iter operator++(int x);
         normal_iter& operator--();
         normal_iter operator--(int x);
         bool operator==(const normal_iter& rightvalue) const;
         bool operator!=(const normal_iter& rightvalue) const;
         normal_iter operator+(int toadd);
         normal_iter operator+(const difference_type &addptr);
         normal_iter operator-(int tosub);
         normal_iter operator-(const difference_type &subptr);
         operator bool() const;

      private:
         T* iter;
   };
}

