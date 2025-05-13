#include "BieuDo.h"

#include <drogon/HttpResponse.h> // Cần để tạo response

// Add definition of your processing function here
void BieuDo::bieuDoDien(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    HttpViewData data;
    data.insert("name", "Tan");

    auto resp = HttpResponse::newHttpViewResponse("BieuDoDien.csp", data);
    callback(resp);
}

void BieuDo::bieuDoNuoc(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    HttpViewData data;
    data.insert("name", "Tan");

    auto resp = HttpResponse::newHttpViewResponse("BieuDoWater.csp", data);
    callback(resp);
}

void BieuDo::bieuDoGa(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    HttpViewData data;
    data.insert("name", "Tan");

    auto resp = HttpResponse::newHttpViewResponse("BieuDoGa.csp", data);
    callback(resp);
}
