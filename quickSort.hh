#ifndef QUICKSORT_HH
#define QUICKSORT_HH

#include<iterator>
#include<algorithm>
template<typename iter>
int partition(const iter& lo,const iter& hi)
{
  
   
    typename iter::value_type pivot=*lo,temp;
    int i=-1,
        j=std::distance(lo,hi)+1;
     while(1)
      {
        do  --j; while(*(lo+j)>pivot);
        do  ++i; while(*(lo+i)<pivot);
            
       if(i<j)
        {
         temp=*(lo+i);
         *(lo+i)=*(lo+j);
         *(lo+j)=temp;
        }
       else
           return j;
       }
        
    
}
    

template<typename iter>
void quickSortHelper(const iter& lo,const iter& hi, std::random_access_iterator_tag)
 {
  if(std::distance(lo,hi)+1>=2)
   {
     int q = partition(lo,hi);
     quickSortHelper(lo,lo+q,typename std::iterator_traits<iter>::iterator_category{});
     quickSortHelper(lo+q+1,hi,typename std::iterator_traits<iter>::iterator_category{});
   }
}
 

template<typename iter>
void quickSort(const iter& lo,const iter& hi)
{
  quickSortHelper(lo,hi-1,typename std::iterator_traits<iter>::iterator_category{});
}
#endif
