#include "CCryptoNote.h" // For CBinaryArray

template <typename T>
inline void convertVectorToArray(const std::vector<T>& vec, T** arr, uint64_t& items) {
   *arr = NULL;
   items = 0;
   if (vec.size() > 0) {
      *arr = new T[vec.size()];
      if (*arr != NULL) {
         for (size_t i = 0; i < vec.size(); i++) {
            (*arr)[i] = vec[i];
         }
         items = vec.size();
      }
   }
}

template <typename T>
inline void convertVectorToArray(const std::vector<std::unique_ptr<T>>& vec, T*** arr, uint64_t& items) {
   *arr = NULL;
   items = 0;
   if (vec.size() > 0) {
      *arr = new T * [vec.size()];
      if (arr) {
         for (size_t i = 0; i < vec.size(); i++) {
            (*arr)[i] = vec[i].get();
         }
         items = vec.size();
      }
   }
}

template <typename T>
inline std::vector<T> convertArrayToVector(T* arr, uint64_t items) {
   std::vector<T> vec;
   vec.reserve(items);
   for (int i = 0; i < items; i++) {
      vec.push_back(arr[i]);
   }
   return vec;
}

inline std::vector<std::string> convertArrayToVector(const char** strings, uint64_t items) {
   std::vector<std::string> vec;
   vec.reserve(items);
   for (int i = 0; i < items; i++) {
      vec.push_back(strings[i]);
   }
   return vec;
}