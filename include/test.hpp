#pragma once
#include <drogon/HttpController.h>

namespace api::v1
{
    class User : public drogon::HttpController<User>
    {
    public:
        User();

    public:
        METHOD_LIST_BEGIN
        METHOD_ADD(User::getInfo, "/{id}", drogon::Get);
        METHOD_ADD(User::getDetailInfo, "/{id}/detailinfo", drogon::Get);
        METHOD_ADD(User::newUser, "/{name}", drogon::Post);
        METHOD_LIST_END

        void getInfo(const drogon::HttpRequestPtr &req, 
            std::function<void(const drogon::HttpResponsePtr &)> &&callback, int userId) const;

        void getDetailInfo(const drogon::HttpRequestPtr &req, 
            std::function<void(const drogon::HttpResponsePtr &)> &&callback, int userId) const;

        void newUser(const drogon::HttpRequestPtr &req, 
            std::function<void(const drogon::HttpResponsePtr &)> &&callback, std::string &&userName);
    };
}
