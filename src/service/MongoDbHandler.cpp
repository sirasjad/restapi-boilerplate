#include "service/MongoDbHandler.hpp"

mongodb::MongoDbHandler::MongoDbHandler()
{
    this->uri = mongocxx::uri(kMongoDbUri);
    this->client = mongocxx::client(this->uri);
    this->db = this->client[kDatabaseName];
}

bool mongodb::MongoDbHandler::AddCharacterToDb(
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

bool mongodb::MongoDbHandler::UpdateWins(const std::string& characterId)
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

bool mongodb::MongoDbHandler::RemoveCharacterFromDb(const std::string& characterId)
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
