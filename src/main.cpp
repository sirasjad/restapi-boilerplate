#include <iostream>

#include "test.hpp"
#include "service/MongoDbHandler.hpp"

int main()
{
    std::cout << "Running API" << std::endl;

    mongocxx::instance instance;
    mongodb::MongoDbHandler mHandler;

    mHandler.AddCharacterToDb("Test", "Test", 0);

    mHandler.UpdateWins("635467cf1e2f283acc061bc1");
    mHandler.UpdateWins("635467cf1e2f283acc061bc9");

    mHandler.RemoveCharacterFromDb("635467cf1e2f283acc061bc1");
    mHandler.RemoveCharacterFromDb("635467cf1e2f283acc061bc9");
    
    drogon::app().setLogPath("./")
                 .setLogLevel(trantor::Logger::kWarn)
                 .addListener("0.0.0.0", 80)
                 .run();
    
    return 0;
}
