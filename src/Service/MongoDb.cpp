#include "Service/MongoDb.hpp"

Service::MongoDb::MongoDb()
{
    // Set credentials
    this->uri = mongocxx::uri(kMongoDbUri);
    this->client = mongocxx::client(this->uri);
    this->db = this->client[kDatabaseName];
}

void Service::MongoDb::start()
{
    // Start MongoDB instance
    mongocxx::instance instance;
}

void Service::MongoDb::stop()
{
    
}

bool Service::MongoDb::newDocument(
    const std::string& collectionName,
    const Json::Value& jsonDocument)
{
    try
    {
        // Convert from Json::Value to std::string
        std::string document = jsonDocument.toStyledString();

        // Call overloaded method
        return this->newDocument(collectionName, document);
    }
    catch(Json::Exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return false;
}

bool Service::MongoDb::newDocument(
    const std::string& collectionName,
    const std::string& jsonDocument)
{
    try
    {
        mongocxx::collection collection = db[collectionName];
        auto builder = bsoncxx::builder::stream::document{};

        bsoncxx::document::value newDocument = bsoncxx::from_json(jsonDocument);
        collection.insert_one(newDocument.view());

        std::cout << "Added new document to collection: " << collectionName << '\n';
        return true;
    }
    catch(bsoncxx::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return false;
}

bool Service::MongoDb::AddCharacterToDb(
    const std::string& characterName, 
    const std::string& size, const int& wins)
{
    mongocxx::collection collection = db["users"];
    auto builder = bsoncxx::builder::stream::document{};

    bsoncxx::document::value docToAdd = 
        builder << "characterName" << characterName 
                << "size" << size
                << "wins" << wins 
                << bsoncxx::builder::stream::finalize;

    collection.insert_one(docToAdd.view());

    std::cout << "Added character" << std::endl;

    return true;
}

bool Service::MongoDb::UpdateWins(const std::string& characterId)
{
    mongocxx::collection collection = db["users"];
    auto builder = bsoncxx::builder::stream::document{};
    bsoncxx::oid documentId(characterId);

    // Query document
    bsoncxx::document::value queryDoc = 
        builder << "_id" << documentId
                << bsoncxx::builder::stream::finalize;

    // Increment
    bsoncxx::document::value updateDoc = 
        builder << "$inc" << bsoncxx::builder::stream::open_document 
                << "wins" << 1 
                << bsoncxx::builder::stream::close_document 
                << bsoncxx::builder::stream::finalize;

    // Update document
    bsoncxx::stdx::optional<mongocxx::result::update> result =
        collection.update_one(queryDoc.view(), updateDoc.view());

    if (result)
    {
        std::cout << result->modified_count() << " documents were updated" << std::endl;
        
        // Return true if one document was modified
        return result->modified_count() == 1;
    }
    else return false;
}

bool Service::MongoDb::RemoveCharacterFromDb(const std::string& characterId)
{
    mongocxx::collection collection = db["users"];
    auto builder = bsoncxx::builder::stream::document{};
    bsoncxx::oid documentId(characterId);

    // Query document
    bsoncxx::document::value queryDoc = 
        builder << "_id" << documentId
                << bsoncxx::builder::stream::finalize;

    // Delete document
    bsoncxx::stdx::optional<mongocxx::result::delete_result> result =
        collection.delete_one(queryDoc.view());

    if (result)
    {
        std::cout << result->deleted_count() << " documents were deleted" << std::endl;
        
        // Return true if one document was deleted
        return result->deleted_count() == 1;
    }
    else return false;
}

void Service::MongoDb::onHttpServerStopped()
{
    std::cout << "Received signal in MongoDb object" << std::endl;
}
