#include <iostream>

 
int main ()
 {
  int tree[100];
  for (int i=0; i<100; i++)
  {
    tree[i]=i+1;
  }
 
   // 输出数组中每个元素的值                     
   for ( int j = 0; j < 100; j++ )
   {
      std::cout << tree[ j ] << std::endl;
   }
 
   return 0;
}
 
