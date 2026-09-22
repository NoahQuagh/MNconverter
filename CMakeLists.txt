cmake_minimum_required(VERSION 3.20)
project(MNconverter)

set(CMAKE_C_STANDARD 11)

include_directories(include)

set(SOURCES
        src/main.c
        src/utils.c
        src/cleaner/clean_data.c
        src/extractor/extract_csv.c
        src/extractor/extract_db.c
        src/formatters/format_csv.c
        src/formatters/format_json.c
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(converter ${SOURCES})

# target_link_libraries(converter sqlite3)