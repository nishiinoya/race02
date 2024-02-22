#include "../inc/list.h"

bool mx_isspace(char c) {
    if (c == ' ' ||
        c == '\t' || c == '\n' ||
        c == '\v' || c == '\f' ||
        c == '\r') {
        return true;
    } else {
        return false;
    }
}

bool mx_isdigit(int c) {
    if (c >= 48 && c <= 57) {
        return 1;
    } else {
        return 0;
    }
}

int mx_atoi(const char *str) {
    int result = 0;
    int sign = 1;
    bool valid = false;

    while (mx_isspace(*str)) {
        str++;
    }

    if (*str == '+' || *str == '-') {
        sign = (*str++ == '-') ? -1 : 1;
    }

    while (mx_isdigit(*str)) {
        result = result * 10 + (*str - '0');
        valid = true;
        str++;
    }

    if (!valid || (*str != '\0' && !mx_isspace(*str))) {
        return 0;
    }

    return result * sign;
}
