/**
 * Using a function wrapper (resolved creating only one template)
 */

#include "somedefs.h"
#include <iostream>
#include <math.h>
#include <functional>

double dub(double x)
{ return 2.0 * x; }

inline double custom_sqrt(double x)
{
   return static_cast<double>(sqrt(x));
}

int main()
{
   using std::cout;
   using std::endl;
   using std::function;

   typedef function<double(double)> fdd;
   double y = 1.21;
   function<double(double)> ef1 = dub;
   function<double(double)> ef2 = custom_sqrt;
   function<double(double)> ef3 = Fq(10.0);
   function<double(double)> ef4 = Fp(10.0);
   function<double(double)> ef5 = [](double u)
   {
      return u * u;
   };
   function<double(double)> ef6 = [](double u)
   {
      return u + u / 2.0;
   };
   cout << use_f(y, function<double(double)>(dub)) << endl;
   cout << use_f(y, fdd(custom_sqrt)) << endl;
   cout << use_f(y, ef3) << endl;
   cout << use_f(y, ef4) << endl;
   cout << use_f(y, ef5) << endl;
   cout << use_f(y, ef6) << endl;

   return 0;
}
