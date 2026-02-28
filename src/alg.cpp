// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value < 2) return false;
  if (value == 2) return true;
  if (value % 2 == 0) return false;
  for (uint64_t i = 3; i * i <= value; i += 2) {
    if (value % i == 0) return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 0) return 0;
  if (n == 1) return 2;
  uint64_t count = 1;
  uint64_t value = 3;
  while (true) {
    if (checkPrime(value)) {
      count++;
      if (count == n) {
        return value;
      }
    }
    value += 2;
  }
}

uint64_t nextPrime(uint64_t value) {
  uint64_t variable = value + 1;
  while (!checkPrime(variable)) {
    variable++;
  }
  return variable;
}

uint64_t sumPrime(uint64_t hbound) {
  if (hbound <= 2) return 0;
  uint64_t sum = 2;
  for (uint64_t i = 3; i < hbound; i += 2) {
    if (checkPrime(i)) {
      sum += i;
    }
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  if (hbound < 5) return 0;
  uint64_t count = 0;
  for (uint64_t i = lbound; i + 2 < hbound; i++) {
    if (checkPrime(i) && checkPrime(i + 2)) {
      count++;
    }
  }
  return count;
}
