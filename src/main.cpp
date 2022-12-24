#include "Core.hpp"
#include "Service/MongoDb.hpp"
#include "Service/HttpServer.hpp"
#include "Endpoint/UserController.hpp"

int main(int argc, char **argv)
{
    // Initialize services
    std::shared_ptr<Service::MongoDb> mongoDbService = std::make_shared<Service::MongoDb>();
    std::shared_ptr<Service::HttpServer> httpServerService = std::make_shared<Service::HttpServer>();

    // Connect signals and slots
    httpServerService->serviceStopped.connect(
        boost::bind(&Service::MongoDb::onHttpServerStopped, mongoDbService));
    
    // Start services as async threads
    std::thread t_mongoDbService(&Service::MongoDb::start, mongoDbService);
    std::thread t_httpServerService(&Service::HttpServer::start, httpServerService);

    /*
    mongoDbService->AddCharacterToDb("Test", "Test", 0);
    mongoDbService->UpdateWins("635467cf1e2f283acc061bc1");
    mongoDbService->UpdateWins("635467cf1e2f283acc061bc9");
    mongoDbService->RemoveCharacterFromDb("635467cf1e2f283acc061bc1");
    mongoDbService->RemoveCharacterFromDb("635467cf1e2f283acc061bc9");

    Json::Value jsonDocument;
    jsonDocument["message"] = "Hello World!";
    jsonDocument["Age"] = 10;
    jsonDocument["Test"] = true;

    mongoDbService->newDocument("products", jsonDocument);
    */

    // Test
    httpServerService->stop();

    std::cout << "Press a key to exit" << '\n';
    std::string tmp; std::getline(std::cin, tmp);
    
    return 0;
}
