#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

// Đại lộ mặt trời
class BieuDo : public drogon::HttpController<BieuDo>
{
public:
    METHOD_LIST_BEGIN
        // use METHOD_ADD to add your custom processing function here;
        // METHOD_ADD(BieuDo::get, "/{2}/{1}", Get); // path is /BieuDo/{arg2}/{arg1}
        // METHOD_ADD(BieuDo::your_method_name, "/{1}/{2}/list", Get); // path is /BieuDo/{arg1}/{arg2}/list
        // ADD_METHOD_TO(BieuDo::your_method_name, "/absolute/path/{1}/{2}/list", Get); // path is /absolute/path/{arg1}/{arg2}/list

        // Gọi là route => con đường
        METHOD_ADD(BieuDo::bieuDoNuoc, "/nuoc", Get);
        METHOD_ADD(BieuDo::bieuDoDien, "/dien", Get);
        METHOD_ADD(BieuDo::bieuDoGa, "/ga", Get);

    METHOD_LIST_END

    // your declaration of processing function maybe like this:
    // void get(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, int p1, std::string p2);
    // void your_method_name(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, double p1, int p2) const;

    // Số nhà
    void bieuDoNuoc(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr&)>&& callback);
    void bieuDoDien(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr&)>&& callback);
    void bieuDoGa(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr&)>&& callback);
};
