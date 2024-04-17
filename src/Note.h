#include <iostream>


struct Note {
  std::string info;
  std::string sum;
  std::string category;

  Note(std::string info, std::string sum, std::string category);
};


struct Income: Note {
  std::string date;

  Income(const std::string& info, const std::string& sum, std::string date, const std::string& category);
};

std::ostream& operator<<(std::ostream& out, const Income& note);


struct Expense: Note {
  std::string date;

  Expense(const std::string& info, const std::string& sum, std::string date, const std::string& category);
};

std::ostream& operator<<(std::ostream& out, const Expense& note);


struct Debt: Note {
  std::string deadline;

  Debt(const std::string& info, const std::string& sum, std::string deadline, const std::string& category);
};

std::ostream& operator<<(std::ostream& out, const Debt& note);
