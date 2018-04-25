#ifndef INTROSORT_HH
#define INTROSORT_HH

#include<iterator>
#include<algorithm>
#include<cstdlib>

template<typename iter>
void siftDown(const iter& lo,const iter& hi,const int& start)
{
  int root=start;
  int end=std::distance(lo,hi)+1;
  int child,swap;
  while(2*root+1<end )
   {
     child=(2*root+1);
     swap=root;

     if(*(lo+swap)<*(lo+child))
         swap=child;

     if(child+1 < end && *(lo+swap) < *(lo+child+1))
         swap=child+1;

     if(swap==root)
         return;
     else
       {
         std::swap(*(lo+root),*(lo+swap));
         root=swap;
       }
   }
}


template<typename iter>
void heapify(const iter& lo, const iter& hi)
{
  int n=std::distance(lo,hi)+1;
  
  for( int start =(n-1)/2;start>=0;--start)
   {
     siftDown(lo,hi-1,start);
   }
 
}


template<typename iter>    
void heapSort(const iter& lo, const iter& hi)
{
  heapify(lo,hi);
  
  int end=std::distance(lo,hi);
  for(int i=end;i>0;--i)
    {
      std::swap(*(lo+end),*(lo));
      --end;
      siftDown(lo,lo+end,0);
         
    }
}
    
    
    
    
    
    
    
    
template<typename iter>
int introPartition(const iter& lo,const iter& hi)
{
  
   
    typename iter::value_type pivot=*lo,temp;
    int i=-1,
        j=std::distance(lo,hi)+1;
     while(1)
      {
       do
        {
          ++i;
        }while(*(lo+i)<pivot);
       do
         {
          --j;
         }while(*(lo+j)>pivot);
       
       if(i>=j)
           return j;
       temp=*(lo+i);
       *(lo+i)=*(lo+j);
       *(lo+j)=temp;
      }
        
    
}
    



template<typename iter>
void introSortHelper(const iter& lo,const iter& hi,const int& depth, std::random_access_iterator_tag)
 {
  int n=std::distance(lo,hi)+1;
  int q = introPartition(lo,hi);
  if(n<=1)
    return;
  else if (q>depth)
      heapSort(lo,hi);
  else 
  {
     introSortHelper(lo,lo+q,depth-1,typename std::iterator_traits<iter>::iterator_category{});
     introSortHelper(lo+q+1,hi,depth-1,typename std::iterator_traits<iter>::iterator_category{});
  }
}
 

template<typename iter>
void introSort(const iter& lo,const iter& hi)
{
 int a= std::log(std::distance(lo,hi));
   introSortHelper(lo,hi-1,a*2,typename std::iterator_traits<iter>::iterator_category{});
}
#endif
