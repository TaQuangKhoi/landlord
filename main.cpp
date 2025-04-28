#include <drogon/drogon.h>

#include "TanController.h"

int main()
{
    drogon::app().loadConfigFile("../config.json");

    drogon::app().registerHandler(
        "/",
        [](
        const drogon::HttpRequestPtr& req,
        std::function<void(const drogon::HttpResponsePtr&)>&& callback
    )
        {
            auto resp = drogon::HttpResponse::newHttpResponse();
            resp->setBody("Hello, World!");

            callback(resp);
        }
        );

    drogon::app().registerHandler(
        "/hello",
        [](const drogon::HttpRequestPtr& req,
           std::function<void(const drogon::HttpResponsePtr&)>&& callback)
        {
            auto resp = drogon::HttpResponse::newHttpResponse();
            resp->setBody("Hello, Drogon!");
            callback(resp);
        });

    drogon::app().registerHandler(
        "/tan",
        [](const drogon::HttpRequestPtr& req,
           std::function<void(const drogon::HttpResponsePtr&)>&& callback)
        {
            auto resp = drogon::HttpResponse::newHttpResponse();
            resp->setBody("Hello, Tan!");
            callback(resp);
        });


    drogon::app().registerHandler(
    "/about",
    [](const drogon::HttpRequestPtr& req,
       std::function<void(const drogon::HttpResponsePtr&)>&& callback)
    {
        auto resp = drogon::HttpResponse::newHttpResponse();
        resp->setBody("Hello, guest! i am Tan! I am a software engineer!");
        callback(resp);
    });

    drogon::app().run();

    return 0;
}
