#pragma once

// Drogon
#include <drogon/drogon.h>

// Boost
#include <boost/signals2.hpp>

namespace Service
{
    class HttpServer
    {
    public:
        HttpServer();
        
        void start();
        void stop();

    public: // Signals
        boost::signals2::signal<void()> serviceStarted;
        boost::signals2::signal<void()> serviceStopped;

    protected: // Slots
        void onHttpServerStarted();
        void onHttpServerStopped();
    };
}
