#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

class TestCtrl : public drogon::HttpController<TestCtrl>
{
  public:
    METHOD_LIST_BEGIN
    // use METHOD_ADD to add your custom processing function here;
    // METHOD_ADD(TestCtrl::get, "/{2}/{1}", Get); // path is /TestCtrl/{arg2}/{arg1}
    // METHOD_ADD(TestCtrl::your_method_name, "/{1}/{2}/list", Get); // path is /TestCtrl/{arg1}/{arg2}/list
    // ADD_METHOD_TO(TestCtrl::your_method_name, "/absolute/path/{1}/{2}/list", Get); // path is /absolute/path/{arg1}/{arg2}/list

    METHOD_ADD(TestCtrl::sayHello, "/user/hello", Get); // Map GET /testctrl/hello tới hàm sayHello
    METHOD_ADD(TestCtrl::getUserInfo, "/user/{id}", Get); // Map GET /testctrl/user/{id} tới hàm getUserInfo

    METHOD_LIST_END
    // your declaration of processing function maybe like this:
    // void get(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, int p1, std::string p2);
    // void your_method_name(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, double p1, int p2) const;

    void sayHello(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback);
    void getUserInfo(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, std::string userId); // Ví dụ với path parameter
};
