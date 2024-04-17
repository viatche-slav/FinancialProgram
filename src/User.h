#include "Notebook.cpp"

class User {
 public:
  explicit User(std::string username);

  ~User();

  void ProcessOperation(const std::string& operation);

 private:
  std::string name_;
  IncomeNotebook i_note_;
  ExpenseNotebook e_note_;
  DebtNotebook d_note_;
};