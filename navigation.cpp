#include "navigation.h"

void navigation::getCurrentSession()
 {
    const char* env_var_path = "USD_FILE_PATH"; 

    const std::string* stage_path = std::getenv(env_var_path);
    
    if (stage != nullptr){ 
        std::cout << "Could not correct path to the USD" << std::endl; 
        exit(EXIT_FAILURE); 
    }

    pxr::UsdStageRefPtr stage = NULL; 

    try{
        currentSession = pxr::UsdStage::Open(stge_path); 
    }
    catch{
        
        exit(EXIT_FAILURE);
    }
 }

pxr::UsdStageRefPtr navigation::getElementName(str::string elementName
){




    return element
}