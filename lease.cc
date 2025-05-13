#include "lease.h"

void lease::giaPhong(
    const HttpRequestPtr& req,
    std::function<void (const HttpResponsePtr &)> &&callback
) {
    auto resp = HttpResponse::newHttpResponse();

    resp->setStatusCode(k200OK);
    resp->setContentTypeCode(CT_TEXT_PLAIN);
    resp->setBody("This is Ly Gia Phong");
    //gray
    callback(resp); // Gửi về
}