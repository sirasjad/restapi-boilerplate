#pragma once

#include "core.hpp"

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
        
        EXPORT_PUBLIC void start();
        EXPORT_PUBLIC void stop();

    public: // Signals
        boost::signals2::signal<void()> serviceStarted;
        boost::signals2::signal<void()> serviceStopped;

    protected: // Slots
        void onHttpServerStarted();
        void onHttpServerStopped();
    };
}
