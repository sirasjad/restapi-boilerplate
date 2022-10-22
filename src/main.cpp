#include <iostream>

#include <drogon/drogon.h>

using namespace drogon;

int main()
{
    std::cout << "Running API" << std::endl;
    
    app().setLogPath("./")
         .setLogLevel(trantor::Logger::kWarn)
         .addListener("0.0.0.0", 80)
         .run();
    
    return 0;
}
