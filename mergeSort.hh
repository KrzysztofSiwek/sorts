#ifndef MERGESORT_HH
#define MERGESORT_HH

#include<iterator>
#include<algorithm>
template<typename iter>
void merge(const iter& begin,const iter& middle,const iter& end)
{
  
    std::vector<typename iter::value_type> a(begin,middle);
    std::vector<typename iter::value_type> b(middle,end);
    
    int i=0,j=0;
    auto k = begin;
    int  maxi=a.size();
    int maxj=b.size();

    for(k=begin;k<end;++k)
      {
       if(i<maxi && (j>=maxj || a[i]<=b[j]))
         *k=a[i++];
       else
         *k=b[j++];
      }
        
    
}
    

template<typename iter>
void mergeSortHelper(const iter& begin,const iter& end, std::random_access_iterator_tag)
 {
  if(std::distance(begin,end)>=2)
   {
     int q = std::distance(begin,end)/2;
     mergeSortHelper(begin,begin+q,typename std::iterator_traits<iter>::iterator_category{});
     mergeSortHelper(begin+q,end,typename std::iterator_traits<iter>::iterator_category{});
     merge(begin,begin+q,end);
   }
}
 

template<typename iter>
void mergeSort(const iter& begin,const iter& end)
{
  mergeSortHelper(begin,end,typename std::iterator_traits<iter>::iterator_category{});
}
#endif
