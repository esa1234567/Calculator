#include "add.h"
#include "compare.h"
#include "reverse.h"
#include <cstdio>
#include <cstring>
#include <string>
void multiply(const char *number1, const char *number2, char *answer) {
  int a = compare(number1, number2);
  int found_two = 0;
  int found_three = 0;
  int count = 0;
  int spe = 0;
  int m = -1;
  int cari = 0;
  int found = 0;
  int found2 = 0;
  const char *o = number1;
  const char *p = number2;
  int check = 0, check2 = 0;
  if (*o == '-') {
    o++;
    check = 2;
  }
  while (*o != 0) {
    if (*o >= '0' && *o <= '9') {
    } else {
      check = 1;
    }
    o++;
  }
  if (*p == '-') {
    check2 = 2;
    p++;
  }

  while (*p != 0) {
    if (*p >= '0' && *p <= '9') {
    } else {
      check2 = 1;
    }
    p++;
  }
  if (strlen(number1) > 128 || strlen(number2) > 128) {
    check = 4;
    check2 = 20;
  }
  const char *f = number1;
  const char *l = number2;
  char *s = answer;
  while (*s != 0) {
    *s = 0;
    s++;
  }
  char *e = answer;
  *e = '0';
  while (*f != 0) {
    f++;
  }
  while (*l != 0) {
    l++;
  }
  f--;
  l--;
  int counts = strlen(number1);
  int counter = strlen(number2);
  if (check == 0 && check2 == 0 || check == 2 && check2 == 2 ||
      check == 0 && check2 == 2 ||
      check == 2 && check2 == 0 && *number1 != '0') {
    if (check2 == 2 && check == 2) {
      counts--;
      counter--;
    }
    if (check2 == 0 && check == 2) {
      counter--;
    }
    if (check2 == 2 && check == 0) {
      counts--;
    }
    char *m = answer;
    m += 127;
    int g = 0;
    char M[128] = {0};
    char P[128] = {0};
    char O[128] = {0};
    for (int i = 0; i < counter + counter; i++) {
      g++;
      if (found == 1) {
        found = 0;
        char *f_f = P;
        int founds_count = strlen(P);
        int founds_count2 = strlen(O);
        if (i > 1) {
          while (*f_f != 0) {
            f_f++;
          }
          f_f--;
        }
        if (i == 1) {
          char *V = O;
          reverse(P);
          for (int i = 0; i < founds_count; i++) {
            int fer = *f_f - 48;
            char m = fer + 48;
            *V = m;
            V++;
            f_f++;
          }
          char * L = O;
          L += 127;
          if(*L != 0){
            break;
            found_three = 1;
          }
          if (i == counter + counter - 1) {
            char *v = O;
            char *mm = answer;
            while (*v != 0) {
              *mm = *v;
              v++;
              mm++;
            }
          }
          V -= founds_count;
          spe = founds_count;
          if (*m != 0) {
            char *q = answer;
            while (*q != 0) {
              *q = '0';
              q++;
            }
            break;
          }
        }
        if (i > 1) {
          if (i >= 3) {
            reverse(P);
          }
          add(P, O, M);
          char * MM = M;
          MM += 127;
          if(*MM != 0){
            found_three = 1;
            break;
          }
          char *O_ptr = O;
          char *M_ptr = M;
          while (*M_ptr != 0) {
            *O_ptr = *M_ptr;
            O_ptr++;
            M_ptr++;
          }
          char *v = P;
          while (*v != 0) {
            *v = 0;
            v++;
          }
          if (i == counter + counter - 1) {
            char *answer_ptr = answer;
            char *M_ptr = M;
            while (*M_ptr != 0) {
              *answer_ptr = *M_ptr;
              answer_ptr++;
              M_ptr++;
              if(*m != 0){
                *m = 0;
                char * q = answer;
                while(*q != 0){
                  *q = 0;
                  q++;
                  found_three = 1;
                }
              }
              if(found_three == 1){
                break;
              }
            }
          }
        }
      } else {
        char *L = P;
        if (i > 1) {
          for (int j = 0; j < i / 2; j++) {
            *L = '0';
            L++;
          }
        }
        char *o = P;
        o += 127;
        for (int j = 0; j < counts; j++) {
          int fer = 0;
          int ferr = 0;
          if (found_two == 0) {
            fer = *f - 48;
            ferr = *l - 48;
            fer *= ferr;
          }
          fer += cari;
          int fere = fer;
          fer %= 10;
          char m = fer + 48;
          *L = m;
          fere /= 10;
          cari = fere;
          f--;
          L++;
          fer = 0;
          if (cari > 0 && j == counts - 1) {
            counts++;
            found_two = 1;
          }
          if (found_two == 1 && j == counts - 1) {
            counts--;
            f += counts;
          }
        }
        if(*o != 0){
          break;
          found_three = 1;
        }
        l--;
        if (found_two != 1) {
          f += counts;
        }
        found_two = 0;
        L--;
        found = 1;
      }
    }
    if (check == 0 && check2 == 2 || check == 2 && check2 == 0) {
     if(found_three == 0){
      char *l = answer;
      while (*l != 0) {
        l++;
      }
      *l = '-';
    }
    }
  }
}
void test_multiply(const char *number1, const char *number2,
                   const char *result2) {
  char answer[128] = {0};
  multiply(number1, number2, answer);
  printf("number1 %s number2 %s result %s result2 %s(%s)\n", number1, number2,
         answer, result2,
         strcmp(answer, result2) == 0 ? "it is correct" : "it is wrong");
}
int main() {
  test_multiply("383838", "2847", "1092786786");
  test_multiply(
      "-9909409312034203038383888888882018302130938018",
      "-28479402934902044209",
      "282214060644292528804232966701060943704665003735670569810874837762");
  test_multiply(
      "-9909409390482094023842012034203038383888888882018302130938018",
      "-284794402984092380888889423409283002934902044209",
      "2822144331287306739510102014496283311182695075663104947778181279528737310045493690797486366935369810874837762");
  test_multiply(
      "990940939048884839028884088888881389048039809432348220940238420120342030"
      "38383888888882018302130938018",
      "-28479444093284092834028304029840923808888894234092594805289083002934902"
      "044209",
      "0");
  test_multiply(
      "-99094093904888888888813890480398094323482209402384201203420303838388888"
      "8882018302130938018",
      "-2847944409328409283402830402984092380888889423409283002934902044209",
      "0");

}
