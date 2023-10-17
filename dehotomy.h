#include <cmath>
#include <iostream>
#include <vector>
#include <iomanip> 

struct deh_data 
{
    double a, b, x1 , x2 = 0; 
    int k = 1; 
    double epsel = 0.1;
    double derivative = 0.01;

};

void x1_x2(struct deh_data *ptr)
{


    std::cout<<"    Метод Дихитомии   "<<std::endl;
    ptr->a=-5;ptr->b=2;
    std::cout<<" +-----------+"<<"------------"<<"+------------+"<<"---------+"<<std::fixed<<std::endl;
    std::cout<<" | "<<"    X1  "<<"  |     "<<"X2  "<<"   "<<std::fixed<<"|   "<<" Fun1 "<<"   |   "<<"Fun2 "<<" | "<<std::endl;
    std::cout<<" +-----------+"<<"------------"<<"+------------+"<<"---------+"<<std::fixed<<std::endl;
    do{
    #ifdef DEBUG
        std::cout<<"iteration "<<ptr->k<<std::endl;
        std::cout<<"A= "<<ptr->a<<std::endl;
        std::cout<<"B= "<<ptr->b<<std::endl;
        std::cout<<"result K="<<ptr->k<<std::endl;
    #endif    
        
        ptr->x1=((ptr->a+ptr->b)/2)-ptr->derivative;
  
        ptr->x2=((ptr->a+ptr->b)/2)+ptr->derivative;
        


    double fun_x1 = (-0.5*cos(0.5*ptr->x1)-0.5);
    double fun_x2 = (-0.5*cos(0.5*ptr->x2)-0.5);
    
    // std::cout<<std::fixed<<"Fun1 "<<"   "<<"Fun2 "<<std::endl;
    // std::cout<<"X1 "<<"   "<<"X2"<<"   "<<std::fixed<<"Fun1 "<<"   "<<"Fun2 "<<std::endl;
    std::cout<<std::setprecision(4)<<" |"<<"  "<<ptr->x1<<"  "<<std::setprecision(4)<<"    "<<ptr->x2<<"      "<<fun_x1<<"     "<<std::setprecision(4)<<fun_x2<<" | "<<std::setprecision(4)<<std::endl;
    fun_x1 > fun_x2 ? ptr->a = ptr->x1 : ptr->b = ptr->x2 ;
  
    // func(ptr);
    ptr->k++;
    } while ((ptr->b-ptr->a)>ptr->epsel);

    double X_min = ((ptr->a+ptr->b)/2)+-((ptr->b-ptr->a)/2);
    
    double Y_min = (-0.5*cos(0.5*X_min)-0.5);

     std::cout<<" +-----------+"<<"------------"<<"+------------+"<<"---------+"<<std::fixed<<std::endl;
     std::cout<<"X-min = "<<std::setprecision(4)<<((ptr->a+ptr->b)/2)<<"+-"<<((ptr->b-ptr->a)/2)<<std::setprecision(4)<<std::endl;
     std::cout<<"Y-min = "<<std::fixed<<Y_min<<std::setprecision(4)<<std::endl;



}
