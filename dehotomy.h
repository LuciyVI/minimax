#include <cmath>
#include <iostream>
#include <vector>
#define DEBUG
struct deh_data 
{
    float a, b, x1 , x2 = 0; 
    int k = 1; 
    float epsel = 0.1;
    float derivative = 0.01;

};
// void check_func(struct deh_data *ptr , float func1, float func2)
// {       
    
//     // std::cout<<"Fun1= "<<func1<<std::endl;
//     // std::cout<<"Fun2= "<<func2<<std::endl;

//     std::cout<<"BEFORE A "<<ptr->a<<std::endl;
//     std::cout<<"BEFORE B "<<ptr->b<<std::endl;
//     func1 > func2 ? ptr->b = ptr->x2 : ptr->a = ptr->x1;
//     std::cout<<"AFTER A "<<ptr->a<<std::endl;
//     std::cout<<"AFTER A "<<ptr->b<<std::endl;    
    

// }
int func(struct deh_data *ptr)
{
    printf("ptr x1 = %f ptr x2 = %f \n",ptr->x1 , ptr->x2);
    float fun_x1 = pow((ptr->x1)-2,2);
    float fun_x2 = pow((ptr->x2)-2,2);
    std::cout<<"Fun1= "<<fun_x1<<std::endl;
    std::cout<<"Fun2= "<<fun_x2<<std::endl;
    fun_x1 > fun_x2 ? ptr->a = ptr->x1 : ptr->b = ptr->x2 ;
    
}
void x1_x2(struct deh_data *ptr)
{



    ptr->a=0;ptr->b=3;
    do{
    #ifdef DEBUG
        // std::cout<<"iteration "<<ptr->k<<std::endl;
        std::cout<<"A= "<<ptr->a<<std::endl;
        std::cout<<"B= "<<ptr->b<<std::endl;
        std::cout<<"result K="<<ptr->k<<std::endl;
    #endif    
        ptr->x1=((ptr->a+ptr->b)/2)-ptr->derivative;
    #ifdef DEBUG   
        std::cout<<"X1= "<<ptr->x1<<std::endl;
    #endif    
        ptr->x2=((ptr->a+ptr->b)/2)+ptr->derivative;
        
    #ifdef DEBUG
        std::cout<<"X2= "<<ptr->x2<<std::endl;
   
    #endif 

    float fun_x1 = pow((ptr->x1)-2,2);
    float fun_x2 = pow((ptr->x2)-2,2);
    std::cout<<"Fun1= "<<fun_x1<<std::endl;
    std::cout<<"Fun2= "<<fun_x2<<std::endl;
    fun_x1 > fun_x2 ? ptr->a = ptr->x1 : ptr->b = ptr->x2 ;
    
    // func(ptr);
    ptr->k++;
    } while ((ptr->b-ptr->a)>ptr->epsel);
    



}