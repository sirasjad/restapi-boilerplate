#pragma once

#include <iostream>
#include <string>

// MongoDB
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/oid.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/database.hpp>
#include <mongocxx/uri.hpp>

namespace mongodb
{
    // temp variables
    constexpr char kMongoDbUri[] = "insert_connectionstring_here";
    constexpr char kDatabaseName[] = "db_name";

    class MongoDbHandler
    {
    public:
        MongoDbHandler();

        bool AddCharacterToDb(const std::string& characterName, 
                              const std::string& size, const int& wins);

        bool UpdateWins(const std::string& characterId);
        bool RemoveCharacterFromDb(const std::string& characterId);

    private:
        mongocxx::uri uri;
        mongocxx::client client;
        mongocxx::database db;
    };
}
