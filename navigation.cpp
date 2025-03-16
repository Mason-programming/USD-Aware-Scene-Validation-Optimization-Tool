#include "navigation.h"

navigation::navigation(); 
navigation::~navigation(); 


void navigation::getCurrentSession()
 {
    const char* env_var_path = "USD_FILE_PATH"; 

    const std::string* stage_path = std::getenv(env_var_path);
    
    if (!stage_path){ 
        throw std::runtime_error("Could not correct path to the USD"); 
    }

    try{

        stage = pxr::UsdStage::Open(stge_path); 

        if (!stage){
            throw std::runtime_error("Could not open the stage"); 
        }

        currentSession = stage->GetSessionLayer(); 

        if (!currentSession){ 
            throw std::runtime_error("Could not open the seesion"); 
        }
    }
    catch(const std::exception& e){
        std:::cer << "Exception: " << e.what() << std::endl;
        throw; 
    }
 }

pxr::UsdStageRefPtr navigation::getElement(str::string& elementName
){
    if (!stage){
        throw std::runtime_error("Stage is not loaded"); 
    }

    pxr::UsdPrim prim = stage->GetPrimAtPath(pxr::SdfPth(elementName)); 

    if(!prim.IsValid()){
        throw std::runtime_error("Prim is not found: " + elementName); 
    }

    return prim; 
}