#pragma once
#include <pxr/usd/stage.h> 
#include <pxr/usd/prim.h> 
#include <cstdlib>
#include <iostream>


class navigation
{ 
    public: 
        navigation(); 
        ~navigation(); 

        void getCurrentSession(); 
        pxr::UsdStageRefPtr getElementName(std::string elementName); 

    private: 
        pxr::UsdStageRefPtr currentSession; 
        void* operator new(size_t size); 
        void operator delete(void * ptr); 

}