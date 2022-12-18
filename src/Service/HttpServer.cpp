#include "Service/HttpServer.hpp"

Service::HttpServer::HttpServer()
{
    
}

void Service::HttpServer::start()
{
    std::cout << "Starting API service" << '\n';

    drogon::app().setLogPath("./")
        .setLogLevel(trantor::Logger::kWarn)
        .addListener("0.0.0.0", 80)
        .run();
}

void Service::HttpServer::stop()
{
    
}
