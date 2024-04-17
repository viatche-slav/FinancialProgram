#include "User.cpp"

void Start() {
  std::cout << "This is a financial program that helps you control your budget. 🤑\n";
  std::cout << "What is your name? \n";
  std::string name;
  std::cin >> name;
  User user(name);
  std::cout << "Tell me what you want to do. Options:\n"
               "- Record\n\t\tincome [ri]\n\t\texpense [re]\n\t\tdebt [rd]\n"
               "- Exit program [exit]\n";
  std::string operation;
  std::cin >> operation;
  while (operation != "exit") {
    user.ProcessOperation(operation);
    std::cout << "Tell me what you want to do next. Options:\n"
                 "- Record\n\t\tincome [ri]\n\t\texpense [re]\n\t\tdebt [rd]\n"
                 "- Delete\n\t\tincome note [di]\n\t\texpense note [de]\n\t\tdebt note [dd]\n"
                 "- Review\n\t\tincome notes [gi]\n\t\texpense notes [ge]\n\t\tdebt notes [gd]\n"
                 "- Exit program [exit]\n";
    std::cin >> operation;
  }
}

int main() {
  Start();
}

