#include "test.hpp"

api::v1::User::User()
{
    LOG_DEBUG << "User constructor!";
}

// path is /api/v1/User/{arg1}
void api::v1::User::getInfo(
    const drogon::HttpRequestPtr &req, 
    std::function<void(const drogon::HttpResponsePtr &)> &&callback, int userId) const
{
    std::cout << "Heisann" << std::endl;
    std::cout << "Path: " << req->getPath() << std::endl;

    Json::Value ret;
    ret["message"] = "Hello, World!";

    auto resp = drogon::HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}

// path is /api/v1/User/{arg1}/detailinfo
void api::v1::User::getDetailInfo(
    const drogon::HttpRequestPtr &req, 
    std::function<void(const drogon::HttpResponsePtr &)> &&callback, int userId) const
{

}

// path is /api/v1/User/{arg1}
void api::v1::User::newUser(
    const drogon::HttpRequestPtr &req, 
    std::function<void(const drogon::HttpResponsePtr &)> &&callback, std::string &&userName)
{

}
