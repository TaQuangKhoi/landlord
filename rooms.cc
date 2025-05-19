#include "rooms.h"

void rooms::danhsach(
    const HttpRequestPtr &req,
    std::function<void (const HttpResponsePtr &)> &&callback
) {
    auto dbClient = drogon::app().getDbClient();

    dbClient->execSqlAsync(
        "SELECT * FROM rooms",
        [callback](const orm::Result &result) {
            HttpViewData data;

            // Tạo mảng Json để lưu danh sách phòng
            Json::Value roomList(Json::arrayValue);

            for (const auto &row : result) {
                Json::Value room;

                // Thêm thông tin từng phòng vào object
                room["name"] = row["name"].as<std::string>();
                room["area"] = row["area"].as<float>(); // Ví dụ cột area là diện tích
                room["price"] = row["price"].as<int>(); // Ví dụ cột giá

                // Thêm phòng vào danh sách
                roomList.append(room);
            }

            // Đưa danh sách phòng vào HttpViewData
            data.insert("rooms", roomList);

            auto resp = HttpResponse::newHttpViewResponse("DanhSachPhong.csp", data);
            callback(resp);
        },
        [callback](const orm::DrogonDbException &e) {
            auto errorResp = HttpResponse::newHttpResponse();
            errorResp->setBody("Database Error: " + std::string(e.base().what()));
            callback(errorResp);
        }
    );
}
