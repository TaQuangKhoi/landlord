#include "BieuDo.h"

// Add definition of your processing function here
void BieuDo::bieuDoDien(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    drogon::HttpViewData data;
    data.insert("name", "Tan");

    auto resp = drogon::HttpResponse::newHttpViewResponse("BieuDoDien.csp", data);
    callback(resp);
}

void BieuDo::bieuDoNuoc(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    drogon::HttpViewData data;
    data.insert("name", "Tan");

    auto resp = drogon::HttpResponse::newHttpViewResponse("BieuDoNuoc.csp", data);
    callback(resp);
}
void BieuDo::bieuDoGa(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    drogon::HttpViewData data;
    data.insert("name", "Tan");

    auto resp = drogon::HttpResponse::newHttpViewResponse("BieuDoGa.csp", data);
    callback(resp);
}
