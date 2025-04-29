#pragma once

#include <drogon/HttpSimpleController.h>

using namespace drogon;

namespace admin
{
class UserController : public drogon::HttpSimpleController<UserController>
{
  public:
    void asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    // list path definitions here;
     PATH_ADD("/adminUser", Get);
    PATH_LIST_END
};
}
