#include <iostream>
#include <vector>

using namespace std;

main()
{
   // Declare size of two dimensional array and initialize.
   vector< vector<int> > vI2Matrix(3, vector<int>(3,1));    

   vI2Matrix[0][0] = 0;
   vI2Matrix[0][1] = 1;
   vI2Matrix[1][0] = 10;
   vI2Matrix[1][1] = 11;
   vI2Matrix[2][0] = 20;
   vI2Matrix[2][1] = 21;

   cout << "Loop by index:" << endl;

   vector< vector<int> >::iterator ii;
   vector<int>::iterator jj;
   for(ii=vI2Matrix.begin(); ii != vI2Matrix.end(); ++ii)
   {
      for(jj=(*ii).begin(); jj != (*ii).end(); ++jj)
      {
         cout << *jj << endl;
      }
   }
}
                
