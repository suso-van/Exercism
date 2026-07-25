#include "grade_school.h"
#include <algorithm> // This is safely outside the namespace too

namespace grade_school {

void school::add(const std::string& name, int grade) {
    roster_[grade].push_back(name);
    std::sort(roster_[grade].begin(), roster_[grade].end());
}

const std::map<int, std::vector<std::string>>& school::roster() const {
    return roster_;
}

std::vector<std::string> school::grade(int g) const {
    auto it = roster_.find(g);
    
    if (it != roster_.end()) {
        return it->second;
    }
    
    return {};
}

}  // namespace grade_school