#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

class rooms : public drogon::HttpController<rooms>
{
  public:
    METHOD_LIST_BEGIN
    METHOD_ADD(rooms::danhsach, "/danh_sach", Get); // Giá phòng
    // use METHOD_ADD to add your custom processing function here;
    // METHOD_ADD(rooms::get, "/{2}/{1}", Get); // path is /rooms/{arg2}/{arg1}
    // METHOD_ADD(rooms::your_method_name, "/{1}/{2}/list", Get); // path is /rooms/{arg1}/{arg2}/list
    // ADD_METHOD_TO(rooms::your_method_name, "/absolute/path/{1}/{2}/list", Get); // path is /absolute/path/{arg1}/{arg2}/list

    METHOD_LIST_END
    void danhsach(
    const HttpRequestPtr& req,
    std::function<void (const HttpResponsePtr&)>&& callback
);
    // your declaration of processing function maybe like this:
    // void get(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, int p1, std::string p2);
    // void your_method_name(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, double p1, int p2) const;
};
