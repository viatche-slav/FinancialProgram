#include "Note.h"


Note::Note(std::string info, std::string sum, std::string category):
    info(std::move(info)), sum(std::move(sum)), category(std::move(category)) {}


Income::Income(const std::string& info, const std::string& sum, std::string date, const std::string& category):
    date(std::move(date)), Note(info, sum, category) {}

std::ostream& operator<<(std::ostream& out, const Income& note) {
  out << "\n\tInfo: " << note.info << "\n\tSum: " << note.sum << "\n\tDate: " << note.date << '\n';
  if (note.category != "-") out << "\tCategory: " << note.category << '\n';
  return out;
}


Expense::Expense(const std::string& info, const std::string& sum, std::string date, const std::string& category):
    date(std::move(date)), Note(info, sum, category) {}

std::ostream& operator<<(std::ostream& out, const Expense& note) {
  out << "\n\tInfo: " << note.info << "\n\tSum: " << note.sum << "\n\tDate: " << note.date << '\n';
  if (note.category != "-") out << "\tCategory: " << note.category << '\n';
  return out;
}


Debt::Debt(const std::string& info, const std::string& sum, std::string deadline, const std::string& category):
    deadline(std::move(deadline)), Note(info, sum, category) {}

std::ostream& operator<<(std::ostream& out, const Debt& note) {
  out << "\n\tInfo: " << note.info << "\n\tSum: " << note.sum << "\n\tDeadline: " << note.deadline
      << '\n';
  if (note.category != "-") out << "\tCategory: " << note.category << '\n';
  return out;
}
