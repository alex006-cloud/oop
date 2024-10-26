#include <iostream>
#include <string>

// Класс EmailService
class EmailService {
public:
    void sendEmail(const std::string &recipient, const std::string &message) {
        std::cout << "Sending email to " << recipient << ": " << message << std::endl;
    }
};

// Класс NotificationService
class NotificationService {
private:
    EmailService emailService;

public:
    void notifyUser(const std::string &recipient, const std::string &message) {
        emailService.sendEmail(recipient, message);
    }
};

int main() {
    NotificationService notificationService;
    notificationService.notifyUser("user@example.com", "Hello, this is a notification!");

    return 0;
}
