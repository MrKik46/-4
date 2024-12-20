#define _CRT_SECURE_NO_WARNINGS
#include "catch.hpp"
#include "one_phase_merge_sort.h"

TEST_CASE("One phase: Normal file") {
	one_phase_merge_sort("normal_file.txt", 0);

	FILE* file_1 = fopen("normal_file.txt", "r+");

	float number_1;
	float number_2;

	int file_1_length = 0;


	if (file_1 != NULL) {
		while (feof(file_1) == false) {
			file_1_length++;
			std::ignore = fscanf(file_1, "%f ", &number_1);
		}
	}

	fclose(file_1);
	fopen("normal_file.txt", "r+");

	fscanf(file_1, "%f ", &number_1);
	for (int i = 1; i < file_1_length; i++) {
		std::ignore = fscanf(file_1, "%f ", &number_2);
		if (number_1 > number_2) {
			REQUIRE(false);
			break;
		}
		number_1 = number_2;
	}
}

TEST_CASE("One phase: Reverse file") {
	one_phase_merge_sort("reverse_file.txt", 0);
	FILE* file = fopen("reverse_file.txt", "r+");

	float number_1;
	float number_2;

	int file_length = 0;

	if (file != NULL) {
		while (feof(file) == false) {
			file_length++;
			std::ignore = fscanf(file, "%f ", &number_1);
		}
	}

	fclose(file);
	fopen("reverse_file.txt", "r+");


	fscanf(file, "%f ", &number_1);
	for (int i = 1; i < file_length - 1; i++) {
		std::ignore = fscanf(file, "%f ", &number_2);
		if (number_1 > number_2) {
			std::cout << number_1 << " " << number_2;
			REQUIRE(false);
			break;
		}
		number_1 = number_2;
	}
}

TEST_CASE("One phase: Similar file") {
	one_phase_merge_sort("similar_file.txt", 0);
	FILE* file = fopen("similar_file.txt", "r+");

	float number_1;
	float number_2;

	int file_length = 0;

	if (file != NULL) {
		while (feof(file) == false) {
			file_length++;
			std::ignore = fscanf(file, "%f ", &number_1);
		}
	}

	fclose(file);
	fopen("similar_file.txt", "r+");

	fscanf(file, "%f ", &number_1);
	for (int i = 1; i < file_length - 1; i++) {
		std::ignore = fscanf(file, "%f ", &number_2);
		if (number_1 > number_2) {
			REQUIRE(false);
			break;
		}
		number_1 = number_2;
	}
}

TEST_CASE("One phase: Empty file") {
	one_phase_merge_sort("empty_file.txt", 0);
	FILE* file = fopen("empty_file.txt", "r+");

	float number_1;
	float number_2;

	int file_length = 0;

	if (file != NULL) {
		while (feof(file) == false) {
			file_length++;
			std::ignore = fscanf(file, "%f ", &number_1);
		}
	}

	fclose(file);
	fopen("empty_file.txt", "r+");

	fscanf(file, "%f ", &number_1);
	for (int i = 1; i < file_length - 1; i++) {
		std::ignore = fscanf(file, "%f ", &number_2);
		if (number_1 > number_2) {
			REQUIRE(false);
			break;
		}
		number_1 = number_2;
	}
}