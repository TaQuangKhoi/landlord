#pragma once
#include <drogon/HttpController.h>

using namespace drogon;

class SumController : public drogon::HttpController<SumController> {
public:
    METHOD_LIST_BEGIN
        METHOD_ADD(SumController::sum, "/sum", Get);
    METHOD_LIST_END

    void sum(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback);
};
