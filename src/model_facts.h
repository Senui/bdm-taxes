#ifndef MODEL_FACTS_H_
#define MODEL_FACTS_H_

#include <string>

namespace bdm {

inline void RemoveQuotes(std::string* s) {
  s->erase(remove(s->begin(), s->end(), '\"'), s->end());
}

inline std::string GetDataDir() {
  std::string data_dir = DATA_DIR;
  RemoveQuotes(&data_dir);
  return data_dir;
}

}  // namespace bdm

#endif  // MODEL_FACTS_H_