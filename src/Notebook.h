#include <ctime>
#include <unordered_map>
#include <vector>
#include "Note.cpp"


class Notebook {
 public:
  virtual void AddNote(const std::unordered_map<std::string, std::string>& parameters) = 0;

  virtual void DeleteNote(uint64_t index) = 0;

 protected:
  static bool DateIsNotGreater(const std::string& first_date, const std::string& second_date);
};


class IncomeNotebook: Notebook {
 public:
  void AddNote(const std::unordered_map<std::string, std::string>& parameters) override;

  void DeleteNote(uint64_t index) override;

  std::vector<std::pair<uint64_t, Income>> GetNotes(const std::unordered_map<std::string, std::string>& parameters);

 private:
  std::vector<Income> notes_;
};


class ExpenseNotebook: Notebook {
 public:
  void AddNote(const std::unordered_map<std::string, std::string>& parameters) override;

  void DeleteNote(uint64_t index) override;

  std::vector<std::pair<uint64_t, Expense>> GetNotes(const std::unordered_map<std::string, std::string>& parameters);

 private:
  std::vector<Expense> notes_;
};


class DebtNotebook: Notebook {
 public:
  void AddNote(const std::unordered_map<std::string, std::string>& parameters) override;

  void DeleteNote(uint64_t index) override;

  std::vector<std::pair<uint64_t, Debt>> GetNotes(const std::unordered_map<std::string, std::string>& parameters);

  const Debt& GetByIndex(uint64_t index);

 private:
  std::vector<Debt> notes_;
};
