#include "TestCtrl.h"
#include <drogon/HttpResponse.h> // Cần để tạo response
#include <json/json.h>         // Cần nếu muốn trả về JSON

// Hàm xử lý cho GET /testctrl/hello
void TestCtrl::sayHello(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr&)>&& callback)
{
    // Lấy query parameter 'name', nếu không có thì dùng "World"
    auto name = req->getParameter("name");
    if (name.empty())
    {
        name = "World";
    }

    auto resp = HttpResponse::newHttpResponse();
    resp->setStatusCode(k200OK);
    resp->setContentTypeCode(CT_TEXT_PLAIN);
    resp->setBody("Hello, " + name + " from TestCtrl!"); // Thêm chữ TestCtrl để phân biệt
    callback(resp); // Gửi response
}

// Hàm xử lý cho GET /testctrl/user/{user-id}
void TestCtrl::getUserInfo(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr&)>&& callback,
                           std::string userId)
{
    Json::Value responseJson;
    responseJson["userId"] = userId; // Sử dụng userId từ path parameter
    responseJson["message"] = "User info from TestCtrl";
    responseJson["data"]["name"] = "Mock User " + userId;
    responseJson["data"]["email"] = userId + "@example.com";

    auto resp = HttpResponse::newHttpJsonResponse(responseJson); // Tạo JSON response
    callback(resp); // Gửi response
}

// Quan trọng: Đảm bảo dòng này có trong file .cc (thường ở cuối)
// REGISTER_CONTROLLER(TestCtrl); // dường như dòng này được thêm tự động vào một file khác hoặc trong CMakeLists.txt tuỳ cấu hình project,
// nhưng nếu build lỗi không tìm thấy controller thì bạn cần thêm dòng này vào đây.
// Thông thường drogon_ctl sẽ xử lý việc đăng ký này.
