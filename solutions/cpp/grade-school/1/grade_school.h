#pragma once

// 1. ALL includes must go up here, outside the namespace!
#include <map>
#include <string>
#include <vector>

// 2. ONLY the class definition goes inside the namespace
namespace grade_school {

class school {
public:
    void add(const std::string& name, int grade);
    const std::map<int, std::vector<std::string>>& roster() const;
    std::vector<std::string> grade(int grade) const;

private:
    std::map<int, std::vector<std::string>> roster_;
};

}  // namespace grade_school