#pragma once

#include "core.hpp"

#include <json/value.h>
#include <boost/signals2.hpp>

#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/exception/exception.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/oid.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/database.hpp>
#include <mongocxx/uri.hpp>

namespace Service
{
    // temp variables
    constexpr char kMongoDbUri[] = "";
    constexpr char kDatabaseName[] = "";

    class MongoDb
    {
    public:
        MongoDb();
        
        void start();
        void stop();

        bool newDocument(const std::string& collectionName, 
                         const Json::Value& jsonDocument);

        bool newDocument(const std::string& collectionName, 
                         const std::string& jsonDocument);

        bool AddCharacterToDb(const std::string& characterName, 
                              const std::string& size, const int& wins);

        bool UpdateWins(const std::string& characterId);
        bool RemoveCharacterFromDb(const std::string& characterId);

    public: // Slots
        void onHttpServerStopped();

    private:
        mongocxx::uri uri;
        mongocxx::client client;
        mongocxx::database db;
    };
}
