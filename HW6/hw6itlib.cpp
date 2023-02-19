   
#include "hw6head.h"
#include "hw6ithead.h"
#include "hw6constit.h"


   hw6{

   template<typename T, size_t SIZE>
   PFArray<T, SIZE>::normal_iter::normal_iter() : itr(nullptr) {}


   template<typename T, size_t SIZE>
   PFArray<T, SIZE>::normal_iter::normal_iter(T* other) : itr(other) {}

   template<typename T, size_t SIZE>
   PFArray<T, SIZE>::normal_iter::normal_iter(const const_iter& rightvalue) : itr(rightvalue.itr) {}

   template<typename T, size_t SIZE>
   PFArray<T, SIZE>::normal_iter::normal_iter(const normal_iter& rightvalue) : itr(rightvalue.itr) {}

   template<typename T, size_t SIZE>
   PFArray<T, SIZE>::normal_iter::normal_iter(normal_iter&& rightvalue) : itr(rightvalue.itr) {rightvalue.itr = nullptr; }

   template<typename T, size_t SIZE>
   PFArray<T, SIZE>::normal_iter::~normal_iter() {}

   template<typename T, size_t SIZE>
   typename PFArray<T, SIZE>::normal_iter& PFArray<T, SIZE>::normal_iter::operator=(const normal_iter& rightvalue)
   {
      itr = rightvalue.itr;
      return *this;
   }

   template<typename T, size_t SIZE>
   typename PFArray<T, SIZE>::normal_iter& PFArray<T, SIZE>::normal_iter::operator=(normal_iter&& rightvalue)
   {
      itr = rightvalue.itr;
      rightvalue.itr = nullptr;
      return *this;
   }

   template<typename T, size_t SIZE>
   T& PFArray<T, SIZE>::normal_iter::operator*()
   {
      return *itr;
   }
   
   template<typename T, size_t SIZE>
   T* PFArray<T, SIZE>::normal_iter::operator->()
   {
      return itr;
   }

   // prefix
   template<typename T, size_t SIZE>
   typename PFArray<T, SIZE>::normal_iter& PFArray<T, SIZE>::normal_iter::operator++()
   {
      itr++;
      return *this;
   }

   // postfix
   template<typename T, size_t SIZE>
   typename PFArray<T, SIZE>::normal_iter PFArray<T, SIZE>::normal_iter::operator++(int x)
   {
      normal_iter temp(itr);
      itr++;
      return temp;
   }
   
   // prefix
   template<typename T, size_t SIZE>
   typename PFArray<T, SIZE>::normal_iter& PFArray<T, SIZE>::normal_iter::operator--()
   {
      itr--;
      return *this;
   }

   // postfix
   template<typename T, size_t SIZE>
   typename PFArray<T, SIZE>::normal_iter PFArray<T, SIZE>::normal_iter::operator--(int x)
   {
      normal_iter temp(itr);
      itr--;
      return temp;
   }

   template<typename T, size_t SIZE>
   bool PFArray<T, SIZE>::normal_iter::operator==(const normal_iter& rightvalue) const
   {
      return itr == rightvalue.itr ? true : false;
   }

   template<typename T, size_t SIZE>
   bool PFArray<T, SIZE>::normal_iter::operator!=(const normal_iter& rightvalue) const
   {
      return itr != rightvalue.itr ? true : false;
   }

   template<typename T, size_t SIZE>
   typename PFArray<T, SIZE>::normal_iter PFArray<T, SIZE>::normal_iter::operator+(int toadd)
   {
      normal_iter temp(itr);
      temp.itr += addint;
      return temp.itr;
   }
   
   template<typename T, size_t SIZE>
   typename PFArray<T, SIZE>::normal_iter PFArray<T, SIZE>::normal_iter::operator+(const difference_type& addptr)
   {
      normal_iter temp(itr);
      temp.itr += addptr;
      return temp;
   }

   template<typename T, size_t SIZE>
   typename PFArray<T, SIZE>::normal_iter PFArray<T, SIZE>::normal_iter::operator-(int tosub)
   {
      normal_iter temp(itr);
      temp.itr -= tosub;
      return temp;
   }

   template<typename T, size_t SIZE>
   typename PFArray<T, SIZE>::normal_iter PFArray<T, SIZE>::normal_iter::operator-(const difference_type& subptr)
   {
      normal_iter temp(itr);
      temp.itr -= subptr;
      return temp;
   }

   template<typename T, size_t SIZE>
   PFArray<T, SIZE>::normal_iter::operator bool() const
   {
      if (itr) 
      return true;
      else 
      return false;
   }

   }