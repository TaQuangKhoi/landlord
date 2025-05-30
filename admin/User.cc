#include "User.h"

using namespace admin;

void UserController::asyncHandleHttpRequest(const drogon::HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    std::string path = req->getPath();
    auto resp = HttpResponse::newHttpResponse();
    resp->setBody("Bạn là Admin");
    callback(resp);
}
