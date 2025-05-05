#pragma once
#include <drogon/HttpController.h>

using namespace drogon;

class MessageHandler : public drogon::HttpController<MessageHandler> {
public:
    METHOD_LIST_BEGIN
        ADD_METHOD_TO(MessageHandler::postMessage, "/postMessage", Post);
    METHOD_LIST_END


    void postMessage(const HttpRequestPtr &req,
                     std::function<void (const HttpResponsePtr &)> &&callback);
};