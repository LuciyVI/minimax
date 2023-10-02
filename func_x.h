#include <cmath>

struct data {

    float a = 0.0 , b = 0.0 ;
    int N = 0;
    float epsel = 0.0;
    float delta_N = 0.0;
    float calc_delta_N = 0.0;
    int k=1;
    void *ptr_table_value;
};
void around_struct(struct data *ptr)
{
    ptr->a = 0; ptr->b = 3;
    
    ptr->epsel = 0.1;


};

void calculation_N(struct data *ptr)
{

    ptr->N = ((2*(ptr->b-ptr->a))/ptr->epsel)-1;
    
    


};

void delta_N(struct data *ptr)
{   

    ptr->delta_N=(ptr->epsel)/2;
         
};
void search_epslent(struct data *ptr)
{
    ptr->epsel = (2*(ptr->b-ptr->a))/(ptr->N+1);
}
void calculation_delta_N(struct data *ptr)
{
   ptr->calc_delta_N = (ptr->b-ptr->a)/(ptr->N+1);    
}

void calculation_func_x(struct data *ptr)
{   
    float table_value[ptr->N+1];
    for (size_t k = 1; k < ptr->N+1; k++)
    {
       table_value[k]=ptr->a+(k*((ptr->b-ptr->a)/(ptr->N+1)));

    }
    for (size_t k = 1; k < ptr->N+1; k++)
    {
        // std::cout<<table_value[k]<<std::endl;
        
    }
    float result = 0.0;
    float result_fx=0.0;
    for (size_t k = 0; k < ptr->N+1; k++)
    {

    float func_x = std::pow(table_value[k]-2,2);
    std::cout<<func_x<<std::endl;
    
    if (func_x == 0.0)
    {
        result = table_value[k]; 
        result_fx=func_x;
    }
    


    }
    
        std::cout<<"X min= "<<result<<"F(x)="<<result_fx<<std::endl;
        // std::cout<<"F(x)="<<result_fx<<std::endl;
    
}
