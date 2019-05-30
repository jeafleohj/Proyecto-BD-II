#include "FileManager.h"

int main(){
    std::string fn = "../../res/titanic_test.csv";
    FileManager fm; 
    fm.setFileName(fn);
    std::cout<<fm.search(1, "892");
    return 0;
}
