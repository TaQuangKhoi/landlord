#include "MessageHandler.h"

void MessageHandler::postMessage(const HttpRequestPtr &req,
                                 std::function<void (const HttpResponsePtr &)> &&callback) {
    // Parse form-urlencoded data
    auto form = req->getParameter("content");  // Lấy nội dung form trường "content"
    std::string responseText = "recived message: " + form;

    auto resp = HttpResponse::newHttpResponse();
    resp->setContentTypeCode(CT_TEXT_PLAIN);
    resp->setBody(responseText);

    callback(resp);
}