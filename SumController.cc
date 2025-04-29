#include "SumController.h"

void SumController::sum(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) {
    auto aStr = req->getParameter("a");
    auto bStr = req->getParameter("b");

    long long a = 0, b = 0;
    if (!aStr.empty()) a = std::stoll(aStr);
    if (!bStr.empty()) b = std::stoll(bStr);

    long long result = a + b;

    auto resp = HttpResponse::newHttpResponse();
    resp->setContentTypeCode(CT_TEXT_PLAIN);
    resp->setBody("Sum is: " + std::to_string(result));
    callback(resp);

    resp->setBody("Sum is: " + std::to_string(result));
    callback(resp);
}