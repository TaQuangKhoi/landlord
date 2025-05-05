#include "MessageHandler.h"

void MessageHandler::postMessage(const HttpRequestPtr &req,
                                 std::function<void (const HttpResponsePtr &)> &&callback) {
    // Parse form-urlencoded data
    auto form = req->getParameter("content");  // Lấy nội dung form trường "content"
    auto user_name = req->getParameter("username");

    // print debug
    LOG_INFO << user_name;

    std::string responseText = "recived message: " + form + user_name;

    auto resp = HttpResponse::newHttpResponse();
    resp->setContentTypeCode(CT_TEXT_PLAIN);
    resp->setBody(responseText);

    callback(resp);
}