#ifndef CSV_HELPER_H_
#define CSV_HELPER_H_

#include "core/util/csv_reader.h"
#include "core/util/log.h"

#include <experimental/filesystem>
#include <string>

namespace fs = std::experimental::filesystem;

namespace bdm {

// Reads in a CSV and converts it to a C++ 2D vector
template <typename T>
inline void CsvTo2DMatrix(const std::string& file_path,
                          std::vector<std::vector<T>>* matrix,
                          int skip_header = -1) {
  if (!fs::exists(file_path)) {
    Log::Fatal("CsvTo2DMatrix", "File not found: ", file_path);
  }
  rapidcsv::ConverterParams converter(true);
  rapidcsv::SeparatorParams separator;
  rapidcsv::LabelParams labels(skip_header);  // no header

  auto doc = rapidcsv::Document(file_path, labels, separator, converter);
  auto num_rows = doc.GetRowCount();

  for (size_t row = 0; row < num_rows; row++) {
    matrix->push_back(doc.GetRow<T>(row));
  }
}

// Reads in a CSV and converts it to a C++ 2D array
template <typename T, int size>
inline void CsvTo2DMatrix(const std::string& file_path,
                          std::array<std::array<T, size>, size>* matrix,
                          int skip_header = -1) {
  if (!fs::exists(file_path)) {
    Log::Fatal("CsvTo2DMatrix", "File not found: ", file_path);
  }
  rapidcsv::ConverterParams converter(true);
  rapidcsv::SeparatorParams separator;
  rapidcsv::LabelParams labels(skip_header);  // no header

  auto doc = rapidcsv::Document(file_path, labels, separator, converter);
  auto num_rows = doc.GetRowCount();
  auto num_cols = doc.GetColumnCount();

  if (static_cast<int>(num_rows) != size ||
      static_cast<int>(num_cols) != size) {
    Log::Fatal("CsvTo2DMatrix", "Size mismatch: trying to read a (", num_rows,
               "x", num_rows, ") CSV matrix into a (", size, "x", size,
               ") C++ 2D array");
  }

  for (size_t row = 0; row < num_rows; row++) {
    for (size_t col = 0; col < num_cols; col++) {
      if (std::isnan(doc.GetCell<T>(col, row))) {
        Log::Warning("CsvTo2DMatrix", "Found NaN value in ", file_path,
                     ". Entry (", row, ",", col, ")");
      }
      (*matrix)[row][col] = doc.GetCell<T>(col, row);
    }
  }
}

// This function reads in a CSV file and converts it to a C++ 1D vector.
// @param file_path The path to the CSV file to be converted.
// @param vector A pointer to the vector object that will store the CSV data.
// @param column (Optional) The index of the column to retrieve from the CSV.
// Defaults to 0.
// @param skip_header (Optional) The number of header rows to skip in the CSV.
// Defaults to -1, which means no header row will be used.
template <typename T>
inline void CsvToVector(const std::string& file_path, std::vector<T>* vector,
                        size_t column = 0, int skip_header = -1) {
  // Check if file exists
  if (!fs::exists(file_path)) {
    Log::Fatal("CsvToVector", "File not found: ", file_path);
  }
  // Set up parameters for CSV conversion
  rapidcsv::ConverterParams converter(true);
  rapidcsv::SeparatorParams separator;
  rapidcsv::LabelParams labels(skip_header);

  // Convert CSV to vector
  auto doc = rapidcsv::Document(file_path, labels, separator, converter);
  *vector = doc.GetColumn<T>(column);
}

template <typename T>
inline void CsvToVector(const std::string& file_path, std::vector<T>* vector,
                        const std::string& column_name, int skip_header = -1) {
  // Check if file exists
  if (!fs::exists(file_path)) {
    Log::Fatal("CsvToVector", "File not found: ", file_path);
  }
  // Set up parameters for CSV conversion
  rapidcsv::ConverterParams converter(true);
  rapidcsv::SeparatorParams separator;
  rapidcsv::LabelParams labels(skip_header);

  // Convert CSV to vector
  auto doc = rapidcsv::Document(file_path, labels, separator, converter);
  *vector = doc.GetColumn<T>(column_name);
}

}  // namespace bdm

#endif  // CSV_HELPER_H_
