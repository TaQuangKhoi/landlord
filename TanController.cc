#include "TanController.h"

void TanController::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    std::string path = req->getPath();
    auto resp = HttpResponse::newHttpResponse();
    resp->setBody("Response for GET request to /2 from TanController");
    callback(resp);
}
