#include "Service/HttpServer.hpp"

Service::HttpServer::HttpServer()
{
    // Connect internal signals and slots
    this->serviceStarted.connect(boost::bind(&Service::HttpServer::onHttpServerStarted, this));
    this->serviceStopped.connect(boost::bind(&Service::HttpServer::onHttpServerStopped, this));
}

void Service::HttpServer::start()
{
    std::cout << "Starting API service" << '\n';

    drogon::app().setLogPath("./")
        .setLogLevel(trantor::Logger::kWarn)
        .addListener("0.0.0.0", 80)
        .run();

    // Emit signal
    serviceStarted();
}

void Service::HttpServer::stop()
{
    std::cout << "Stopping API service" << '\n';

    // Emit signal
    serviceStopped();
}

void Service::HttpServer::onHttpServerStarted()
{
    std::cout << "API service is now running" << '\n';
}

void Service::HttpServer::onHttpServerStopped()
{
    std::cout << "API service is no longer running" << '\n';
}
