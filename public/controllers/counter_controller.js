// Lấy lớp Controller từ Stimulus
const Controller = Stimulus.Controller;

// Định nghĩa class controller
class CounterController extends Controller {
    // Định nghĩa các 'targets' mà controller này quản lý
    static targets = [ "output" ]

    // Phương thức initialize() chạy một lần khi controller được khởi tạo
    initialize() {
        // Khởi tạo biến đếm 'count' cho instance này của controller
        this.count = 0;
        console.log("Counter controller initialized with count:", this.count);
    }

    // Phương thức connect() chạy mỗi khi controller kết nối với phần tử DOM
    connect() {
        console.log("Counter controller connected.");
        // Hiển thị giá trị count ban đầu khi controller kết nối
        this.updateOutput();
    }

    // Phương thức được gọi bởi data-action="click->counter#increment"
    increment() {
        this.count++; // Tăng biến đếm
        console.log("Count incremented to:", this.count);
        this.updateOutput(); // Cập nhật hiển thị
    }

    // Phương thức helper để cập nhật nội dung của target 'output'
    updateOutput() {
        this.outputTarget.textContent = this.count;
    }

    // (Tùy chọn) Phương thức disconnect() chạy khi controller bị ngắt kết nối
    disconnect() {
        console.log("Counter controller disconnected.");
    }
}

// Xuất class controller
export default CounterController;