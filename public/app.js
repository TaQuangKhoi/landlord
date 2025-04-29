// Import các controllers
import HelloController from './controllers/hello_controller.js'; // Controller từ ví dụ trước
import CounterController from './controllers/counter_controller.js'; // Controller mới

// Khởi tạo ứng dụng Stimulus (nếu chưa có)
// const application = Stimulus.Application.start(); // Chỉ gọi start() một lần

// Đăng ký các controllers
application.register("hello", HelloController);
application.register("counter", CounterController); // Đăng ký controller mới

console.log("Stimulus application started and controllers registered.");