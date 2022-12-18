#pragma once

// Drogon
#include <drogon/drogon.h>

namespace Service
{
    class HttpServer
    {
    public:
        HttpServer();
        
        void start();
        void stop();
    };
}
