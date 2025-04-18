#include <drogon/drogon.h>
#include <fmt/core.h>

int main() {
    drogon::app().loadConfigFile("../config.json");
    drogon::app().registerHandler(
    "/hello",
    [](const drogon::HttpRequestPtr& req,
       std::function<void(const drogon::HttpResponsePtr&)>&& callback) {
        auto resp = drogon::HttpResponse::newHttpResponse();
        resp->setBody("Hello, Drogon!");
        callback(resp);
    });
    drogon::app().registerHandler(
    "/tan",
    [](const drogon::HttpRequestPtr& req,
       std::function<void(const drogon::HttpResponsePtr&)>&& callback) {
        auto resp = drogon::HttpResponse::newHttpResponse();
        resp->setBody("Hello, Tan!");
        callback(resp);
    });
    drogon::app().run();
    // fmt::print("Hello World!\n");
    return 0;
}
