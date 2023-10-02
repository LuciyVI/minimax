#include <iostream>
#include <vector>

#include <cmath>

using namespace std;

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
    float table_value[ptr->N];
    for (size_t k = 1; k < ptr->N; k++)
    {
       table_value[k]=ptr->a+(k*((ptr->b-ptr->a)/(ptr->N+1)));

    }
    for (size_t k = 1; k < ptr->N; k++)
    {
         std::cout<<table_value[k]<<std::endl;
        
    }
    for (size_t k = 0; k < ptr->N; k++)
    {

    float func_x = std::pow(table_value[k]-2,2);
        
    std::cout<<func_x<<std::endl;
    
    }
    
    
    
}




int unimodal_func(struct data *ptr)
{
    return   0; 
}


int main() 
    
    {
        struct data data;

        struct data *p_data = &data;

        around_struct(p_data);
        
        calculation_N(p_data);

        delta_N(p_data);

        std::cout<<"Это А "<<data.a<<std::endl;

        std::cout<<"Это Б "<<data.b<<std::endl; 

        std::cout<<"Это Eps "<<data.epsel<<std::endl;

        std::cout<<"Это N "<<data.N<<std::endl;

        std::cout<<"Это Дельта "<<data.delta_N<<std::endl;
        calculation_delta_N(p_data);
        // search_epslent(p_data);
        // std::cout<<"Это Расчётный Epselent "<<data.epsel<<std::endl;
        calculation_func_x(p_data);
        std::cout<<"Это Расчётная дельта "<<data.calc_delta_N<<std::endl;
        
        
        
    
    
        return 0;


    }   
