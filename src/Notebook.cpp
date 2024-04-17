#include "Notebook.h"


bool Notebook::DateIsNotGreater(const std::string& first_date, const std::string& second_date) {
  std::tm first{};
  first.tm_year = stoi(first_date.substr(6, 4)) - 1900;
  first.tm_mon = stoi(first_date.substr(3, 2)) - 1;
  first.tm_mday = stoi(first_date.substr(0, 2));

  std::tm second{};
  second.tm_year = stoi(second_date.substr(6, 4)) - 1900;
  second.tm_mon = stoi(second_date.substr(3, 2)) - 1;
  second.tm_mday = stoi(second_date.substr(0, 2));

  return std::mktime(&first) <= std::mktime(&second);
}


void IncomeNotebook::AddNote(const std::unordered_map<std::string, std::string>& parameters) {
  notes_.emplace_back(parameters.at("info"), parameters.at("sum"), parameters.at("date"), parameters.at("category"));
}

void IncomeNotebook::DeleteNote(uint64_t index) { notes_.erase(std::next(notes_.begin(), index)); }

std::vector<std::pair<uint64_t, Income>> IncomeNotebook::GetNotes(const std::unordered_map<std::string,
    std::string>& parameters) {
  std::vector<std::pair<uint64_t, Income>> relevant_notes;
  auto category = parameters.find("category");
  for (uint64_t i = 0; i < notes_.size(); ++i) {
    if (DateIsNotGreater(parameters.at("start_date"), notes_[i].date) &&
        DateIsNotGreater(notes_[i].date, parameters.at("end_date"))) {
      if (category != parameters.end() && notes_[i].category != category->second) continue;
      relevant_notes.emplace_back(i, notes_[i]);
    }
  }
  return relevant_notes;
}


void ExpenseNotebook::AddNote(const std::unordered_map<std::string, std::string>& parameters) {
  notes_.emplace_back(parameters.at("info"), parameters.at("sum"), parameters.at("date"), parameters.at("category"));
}

void ExpenseNotebook::DeleteNote(uint64_t index) { notes_.erase(std::next(notes_.begin(), index)); }

std::vector<std::pair<uint64_t, Expense>> ExpenseNotebook::GetNotes(const std::unordered_map<std::string,
    std::string>& parameters) {
  std::vector<std::pair<uint64_t, Expense>> relevant_notes;
  auto category = parameters.find("category");
  for (uint64_t i = 0; i < notes_.size(); ++i) {
    if (DateIsNotGreater(parameters.at("start_date"), notes_[i].date) &&
        DateIsNotGreater(notes_[i].date, parameters.at("end_date"))) {
      if (category != parameters.end() && notes_[i].category != category->second) continue;
      relevant_notes.emplace_back(i, notes_[i]);
    }
  }
  return relevant_notes;
}


void DebtNotebook::AddNote(const std::unordered_map<std::string, std::string>& parameters) {
  notes_.emplace_back(parameters.at("info"), parameters.at("sum"), parameters.at("deadline"),
                      parameters.at("category"));
}

void DebtNotebook::DeleteNote(uint64_t index) { notes_.erase(std::next(notes_.begin(), index)); }

std::vector<std::pair<uint64_t, Debt>> DebtNotebook::GetNotes(const std::unordered_map<std::string,
    std::string>& parameters) {
  std::vector<std::pair<uint64_t, Debt>> relevant_notes;
  auto category = parameters.find("category");
  for (uint64_t i = 0; i < notes_.size(); ++i) {
    if (DateIsNotGreater(notes_[i].deadline, parameters.at("end_date"))) {
      if (category != parameters.end() && notes_[i].category != category->second) continue;
      relevant_notes.emplace_back(i, notes_[i]);
    }
  }
  return relevant_notes;
}

const Debt& DebtNotebook::GetByIndex(uint64_t index) { return notes_[index]; }
