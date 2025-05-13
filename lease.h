#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

class lease : public drogon::HttpController<lease>
{
  public:
    METHOD_LIST_BEGIN
    METHOD_ADD(lease::giaPhong, "/gia-phong", Get); //
    METHOD_LIST_END
    void giaPhong(
    const HttpRequestPtr& req,
    std::function<void (const HttpResponsePtr&)>&& callback
);
};
