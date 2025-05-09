#include <drogon/drogon.h>
#include <drogon/orm/DbClient.h>

int main()
{
    auto dbClient = drogon::orm::DbClient::newSqlite3Client("filename=landlord.db", 1);

    drogon::app().loadConfigFile("../config.json");


    try
    {
        auto createTableResult = dbClient->execSqlSync(
            "CREATE TABLE IF NOT EXISTS rooms (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT NOT NULL, description TEXT)");

        auto countResult = dbClient->execSqlSync("SELECT COUNT(*) FROM rooms");
        if (!countResult.empty() && countResult[0][0].as<int>() == 0)
        {
            dbClient->execSqlSync(
                "INSERT INTO rooms (name, description) VALUES ('Living Room', 'A cozy place to relax and watch TV.')");
            dbClient->execSqlSync(
                "INSERT INTO rooms (name, description) VALUES ('Kitchen', 'Fully equipped kitchen with modern appliances.')");
            dbClient->execSqlSync(
                "INSERT INTO rooms (name, description) VALUES ('Master Bedroom', 'Spacious master bedroom with an en-suite bathroom.')");
            dbClient->execSqlSync(
                "INSERT INTO rooms (name, description) VALUES ('Guest Bedroom', 'Comfortable room for guests.')");
        }
        else if (countResult.empty())
        {
            LOG_WARN << "Could not determine count from 'rooms' table, or table is empty.";
        }
        else
        {
        }
    }
    catch (const drogon::orm::DrogonDbException& e)
    {
        LOG_ERROR << "Database setup error for 'rooms' table: " << e.base().what();
    }

    drogon::app().registerHandler("/",
                                  [=](const drogon::HttpRequestPtr& req,
                                      std::function<void(const drogon::HttpResponsePtr&)>&& callback)
                                  {
                                      drogon::HttpViewData data;
                                      data.insert("name", "Tan");


                                      auto resp = drogon::HttpResponse::newHttpViewResponse("Main.csp", data);
                                      callback(resp);
                                  });

    drogon::app().registerHandler(
        "/hi/{}",
        [](const drogon::HttpRequestPtr& req, std::function<void(const drogon::HttpResponsePtr&)>&& callback,
           const std::string& name)
        {
            drogon::HttpViewData data;
            data.insert("name", name);

            auto resp = drogon::HttpResponse::newHttpViewResponse("Example.csp", data);
            callback(resp);
        });

    drogon::app().registerHandler("/list_para",
                                  [=](const drogon::HttpRequestPtr& req,
                                      std::function<void (const drogon::HttpResponsePtr&)>&& callback)
                                  {
                                      auto para = req->getParameters();
                                      drogon::HttpViewData data;
                                      data.insert("title", "ListParameters");
                                      data.insert("parameters", para);
                                      auto resp = drogon::HttpResponse::newHttpViewResponse("ListParameters.csp", data);
                                      callback(resp);
                                  });

    drogon::app().registerHandler(
        "/room-list",
        [dbClient](
        const drogon::HttpRequestPtr& req,
        std::function<void(const drogon::HttpResponsePtr&)>&& callback)
        {
            std::string sql = "SELECT id, name, description FROM rooms;";

            dbClient->execSqlAsync(
                sql,
                [callback](const drogon::orm::Result& result)
                {
                    if (result.empty())
                    {
                        // KIỂM TRA Ở ĐÂY
                        // Nếu không có room nào, trả về text thuần
                        auto resp = drogon::HttpResponse::newHttpResponse();
                        resp->setBody("No rooms found in the database.");
                        resp->setContentTypeCode(drogon::CT_TEXT_PLAIN); // Quan trọng: đặt content type là text
                        callback(resp);
                    }
                    else
                    {
                        // Nếu có room, tiếp tục render file CSP như bình thường
                        drogon::HttpViewData view_data;
                        std::vector<std::map<std::string, std::string>> rooms_list_for_view;

                        for (const auto& row : result)
                        {
                            LOG_INFO << "Room ID: " << row["id"].as<std::string>()
                                     << ", Name: " << row["name"].as<std::string>()
                                     << ", Description: " << row["description"].as<std::string>();

                            std::map<std::string, std::string> room;
                            room["id"] = row["id"].as<std::string>();
                            room["name"] = row["name"].as<std::string>();
                            room["description"] = row["description"].as<std::string>();


                            rooms_list_for_view.push_back(room);
                        }

                        view_data.insert("rooms_for_view", rooms_list_for_view);
                        auto resp = drogon::HttpResponse::newHttpViewResponse("RoomsList.csp", view_data);
                        callback(resp);
                    }
                },
                [callback](const drogon::orm::DrogonDbException& e)
                {
                    LOG_ERROR << "Database query failed for /: " << e.base().what();
                    auto resp = drogon::HttpResponse::newHttpResponse();
                    resp->setStatusCode(drogon::k500InternalServerError);
                    resp->setBody(
                        "<html><body><h1>Error</h1><p>Could not retrieve room data. Details: " +
                        std::string(e.base().what()) + "</p></body></html>");
                    resp->setContentTypeCode(drogon::CT_TEXT_HTML);
                    callback(resp);
                });
        });

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
