#include <drogon/drogon.h>
#include <drogon/orm/DbClient.h>

int main()
{
    auto dbClient = drogon::orm::DbClient::newSqlite3Client("filename=landlord.db", 1);

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

    drogon::app().loadConfigFile("../config.json");

    drogon::app().registerHandler(
        "/",
        [dbClient](
        const drogon::HttpRequestPtr& req,
        std::function<void(const drogon::HttpResponsePtr&)>&& callback
    )
        {
            std::string sql = "SELECT id, name, description FROM rooms;";


            dbClient->execSqlAsync(
                sql,
                [callback](const drogon::orm::Result& result)
                {
                    std::ostringstream os;
                    os << "<!DOCTYPE html><html><head><title>Rooms List</title></head><body>";
                    os << "<h1>Available Rooms:</h1>";

                    if (result.empty())
                    {
                        os << "<p>No rooms found in the database.</p>";
                    }
                    else
                    {
                        os << "<ul>";
                        for (const auto& row : result)
                        {
                            os << "<li>";
                            os << "<b>ID:</b> " << row["id"].as<std::string>();
                            os << ", <b>Name:</b> " << row["name"].as<std::string>();
                            os << ", <b>Description:</b> " << row["description"].as<std::string>();
                            os << "</li>";
                        }
                        os << "</ul>";
                    }
                    os << "</body></html>";

                    auto resp = drogon::HttpResponse::newHttpResponse();
                    resp->setBody(os.str());
                    resp->setContentTypeCode(drogon::CT_TEXT_HTML);
                    callback(resp);
                },
                [callback](const drogon::orm::DrogonDbException& e)
                {
                    LOG_ERROR << "Database query failed for /: " << e.base().what();
                    auto resp = drogon::HttpResponse::newHttpResponse();
                    resp->setStatusCode(drogon::k500InternalServerError);
                    resp->setBody(
                        "Error: Could not retrieve room data from the database. Details: " + std::string(e.base().what()));
                    callback(resp);
                }
            );
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
