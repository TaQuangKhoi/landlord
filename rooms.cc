#include "rooms.h"

// Add definition of your processing function here
void rooms::danhsach(
    const HttpRequestPtr& req,
    std::function<void (const HttpResponsePtr &)> &&callback
) {
    HttpViewData data;
    data.insert("name", "Tan");

    auto resp = HttpResponse::newHttpViewResponse("DanhSachPhong.csp", data);
    callback(resp);
}