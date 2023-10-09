#include <cmath>
#include <iostream>
#include <vector>
#include <iomanip> 
#define DEBUG
struct deh_data 
{
    double a, b, x1 , x2 = 0; 
    int k = 1; 
    double epsel = 0.1;
    double derivative = 0.01;

};

void x1_x2(struct deh_data *ptr)
{



    ptr->a=0;ptr->b=3;
    do{
    #ifdef DEBUG
        // std::cout<<"iteration "<<ptr->k<<std::endl;
        // std::cout<<"A= "<<ptr->a<<std::endl;
        // std::cout<<"B= "<<ptr->b<<std::endl;
        // std::cout<<"result K="<<ptr->k<<std::endl;
    #endif    
        ptr->x1=((ptr->a+ptr->b)/2)-ptr->derivative;
    #ifdef DEBUG   
        std::cout<<"X1= "<<ptr->x1<<std::endl;
    #endif    
        ptr->x2=((ptr->a+ptr->b)/2)+ptr->derivative;
        
    #ifdef DEBUG
        std::cout<<"X2= "<<ptr->x2<<std::endl;
   
    #endif 

    double fun_x1 = pow((ptr->x1)-2,2.0);
    double fun_x2 = pow((ptr->x2)-2,2.0);
    
    std::cout<<"Fun1= "<< fun_x1<<std::setprecision(9)<<std::endl;
    std::cout<<"Fun2= " <<fun_x2 << std::setprecision(9) <<std::endl;

    fun_x1 > fun_x2 ? ptr->a = ptr->x1 : ptr->b = ptr->x2 ;
  
    // func(ptr);
    ptr->k++;
    } while ((ptr->b-ptr->a)>ptr->epsel);
    double X_min = ((ptr->a+ptr->b)/2)+-((ptr->b-ptr->a)/2);
    
    double Y_min = pow(X_min-2,2);

    std::cout<<"X-min = "<<std::setprecision(4)<<((ptr->a+ptr->b)/2)<<"+-"<<((ptr->b-ptr->a)/2)<<std::setprecision(4)<<std::endl;
    std::cout<<"Y-min = "<<std::fixed<<Y_min<<std::endl;



}
