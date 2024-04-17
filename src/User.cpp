#include "User.h"

User::User(std::string username): name_(std::move(username)) { std::cout << "Hello, " << name_ << "! 😉\n"; }

User::~User() { std::cout << "Goodbye, " << name_ << "! 🙃\n"; }

void User::ProcessOperation(const std::string& operation) {
  if (operation == "ri") {
    std::cout << "Type the information (ending with '.'), the sum (positive integer), "
                 "the date (dd.mm.yyyy) and the category ('-' not to add a category).\n";
    std::string info, sum, date, category;
    std::string subinfo;
    std::cin >> subinfo;
    while (subinfo.back() != '.') {
      info += subinfo + ' ';
      std::cin >> subinfo;
    }
    info += subinfo;
    std::cin >> sum >> date >> category;
    i_note_.AddNote(std::unordered_map<std::string, std::string>({{"info",     info},
                                                                  {"sum",      sum},
                                                                  {"date",     date},
                                                                  {"category", category}}));
    std::cout << "Successfully added income note.\n\n";
  } else if (operation == "re") {
    std::cout << "Type the information (ending with '.'), the sum (positive integer), "
                 "the date (dd.mm.yyyy) and the category ('-' not to add a category).\n";
    std::string info, sum, date, category;
    std::string subinfo;
    std::cin >> subinfo;
    while (subinfo.back() != '.') {
      info += subinfo + ' ';
      std::cin >> subinfo;
    }
    info += subinfo;
    std::cin >> sum >> date >> category;
    e_note_.AddNote(std::unordered_map<std::string, std::string>{{"info",     info},
                                                                 {"sum",      sum},
                                                                 {"date",     date},
                                                                 {"category", category}});
    std::cout << "Successfully added expense note.\n\n";
  } else if (operation == "rd") {
    std::cout << "Type the information (ending with '.'), the sum (positive integer), "
                 "the deadline (dd.mm.yyyy) and the category ('-' not to add a category).\n";
    std::string info, sum, deadline, category;
    std::string subinfo;
    std::cin >> subinfo;
    while (subinfo.back() != '.') {
      info += subinfo + ' ';
      std::cin >> subinfo;
    }
    info += subinfo;
    std::cin >> sum >> deadline >> category;
    d_note_.AddNote(std::unordered_map<std::string, std::string>{{"info",     info},
                                                                 {"sum",      sum},
                                                                 {"deadline", deadline},
                                                                 {"category", category}});
    std::cout << "Successfully added debt note.\n\n";
  } else if (operation == "di") {
    std::cout << "Type the index of income note you want to delete.\n";
    uint64_t index;
    std::cin >> index;
    i_note_.DeleteNote(index);
    std::cout << "Successfully deleted income note.\n\n";
  } else if (operation == "de") {
    std::cout << "Type the index of expense note you want to delete.\n";
    uint64_t index;
    std::cin >> index;
    e_note_.DeleteNote(index);
    std::cout << "Successfully deleted expense note.\n\n";
  } else if (operation == "dd") {
    std::cout << "Type the index of debt note you want to delete and "
                 "the date it is payed (dd.mm.yyyy).\n";
    uint64_t index;
    std::string pay_date;
    std::cin >> index >> pay_date;
    const Debt& payed_debt = d_note_.GetByIndex(index);
    e_note_.AddNote(std::unordered_map<std::string, std::string>{
        {"info",     payed_debt.info},
        {"sum",      payed_debt.sum},
        {"date",     pay_date},
        {"category", payed_debt.category}});
    d_note_.DeleteNote(index);
    std::cout << "Successfully deleted debt note and recorded new expense.\n\n";
  } else if (operation == "gi") {
    std::cout << "Type the start date (dd.mm.yyyy), the end date (dd.mm.yyyy)"
                 " and the category ('-' to search across all categories).\n";
    std::string start_date, end_date, category;
    std::cin >> start_date >> end_date >> category;
    std::unordered_map<std::string, std::string> parameters{{"start_date", start_date},
                                                            {"end_date",   end_date}};
    if (category != "-") parameters.emplace("category", category);
    std::vector<std::pair<uint64_t, Income>> notes = i_note_.GetNotes(parameters);
    std::cout << "Found notes:\n";
    for (std::pair<uint64_t, Income>& note : notes) {
      std::cout << note.first << ":" << note.second;
    }
    std::cout << "That's all!\n\n";
  } else if (operation == "ge") {
    std::cout << "Type the start date (dd.mm.yyyy), the end date (dd.mm.yyyy)"
                 " and the category ('-' to search across all categories).\n";
    std::string start_date, end_date, category;
    std::cin >> start_date >> end_date >> category;
    std::unordered_map<std::string, std::string> parameters{{"start_date", start_date},
                                                            {"end_date",   end_date}};
    if (category != "-") parameters.emplace("category", category);
    std::vector<std::pair<uint64_t, Expense>> notes = e_note_.GetNotes(parameters);
    std::cout << "Found notes:\n";
    for (std::pair<uint64_t, Expense>& note : notes) {
      std::cout << note.first << ":" << note.second;
    }
    std::cout << "That's all!\n\n";
  } else if (operation == "gd") {
    std::cout << "Type the end date (dd.mm.yyyy) and "
                 "the category ('-' to search across all categories).\n";
    std::string start_date, end_date, category;
    std::cin >> end_date >> category;
    std::unordered_map<std::string, std::string> parameters{{"end_date", end_date}};
    if (category != "-") parameters.emplace("category", category);
    std::vector<std::pair<uint64_t, Debt>> notes = d_note_.GetNotes(parameters);
    std::cout << "Found notes:\n";
    for (std::pair<uint64_t, Debt>& note : notes) {
      std::cout << note.first << ":" << note.second;
    }
    std::cout << "That's all!\n\n";
  } else {
    std::cout << "Oops! There is no such option.\n\n";
  }
}

