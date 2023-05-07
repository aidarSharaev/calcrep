#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "polish.h"
#include <math.h>
#include <QDebug>

static const char* list_of_oper[] = {
    "sin",/*0*/
    "cos",/*1*/
    "tan",/*2*/
    "asin",/*3*/
    "acos",/*4*/
    "atan",/*5*/
    "lg",/*6*/
    "ln",/*7*/
    "sqrt",/*8*/
    "%",/*9*/
    "/",/*10*/
    "^",/*12*/
    "*",/*12*/
    "+",/*13*/
    "-",/*14*/
    "0",/*15*/
    "1",/*16*/
    "2",/*17*/
    "3",/*18*/
    "4",/*19*/
    "5",/*20*/
    "6",/*21*/
    "7",/*22*/
    "8",/*23*/
    "9",/*24*/
    ".",/*25*/
    "x",/*26*/
    ")",/*27*/
    "(" /*28*/
};

static int flag = 0;
static int x_value = 0;
static int count_in_buffer = 0;

void in_stack(stack_t** main_stack, const elem_t elem) {
    stack_t* tmp = (stack_t*)calloc(1, sizeof(stack_t));
    strcpy_s(tmp->element.str, elem.str);
    tmp->element.priority = elem.priority;
    tmp->next = *main_stack;
    (*main_stack) = tmp;
}

void delete_in_stack(stack_t** main_stack) {
    stack_t* tmp = *main_stack;
    *main_stack = (*main_stack)->next;
    free(tmp);
}

void out_stack(stack_t** main_stack, buffer_t** main_buffer) {
    elem_t element = { "\0", 0 };
    element.priority = (*main_stack)->element.priority;
    strcpy_s(element.str, (*main_stack)->element.str);
    size_t len = strlen((*main_stack)->element.str);
    element.str[len] = '\0';
    in_buffer(main_buffer, element, 1);
    stack_t* tmp = *main_stack;
    *main_stack = (*main_stack)->next;
    free(tmp);
}

int in_buffer(buffer_t** main_buffer, const elem_t elem, int k) {
  if (k < 0) {
      char buff[101];
      strcpy(buff, elem.str);
      size_t m_size = strlen(buff);
      if (*buff == '-' || *buff == '+') {
        for (size_t i = 0; i < (m_size - 1); i++)
          buff[i] = buff[i + 1];
        buff[m_size - 1] = '\0';
        m_size = strlen(buff);
      }
      if (m_size > 19) {
        return 1;
      } else if (m_size < 19) {
      } else if (m_size == 19) {
        if (strcmp(buff, "9223372036854775807") > 0) {
          return 1;
        }
        printf("tut\n");
      }
    }
    buffer_t* tmp = (buffer_t*)calloc(1, sizeof(buffer_t));
    strcpy_s(tmp->element.str, elem.str);
    tmp->element.priority = elem.priority;
    if ((*main_buffer) == NULL) {
        tmp->next = NULL;
        *main_buffer = tmp;
    } else {
        buffer_t* pt = *main_buffer;
        buffer_t* crr = pt;
        while (pt) {
            crr = pt;
            pt = pt->next;
        }
        crr->next = tmp;
        tmp->next = NULL;
    }
    return 0;
}

void delete_buff(buffer_t** main_buffer) {
    while ((*main_buffer)) {
        buffer_t* tmp = *main_buffer;
        *main_buffer =  (*main_buffer)->next;
        free(tmp);
    }
}

void delete_stack(stack_t** main_stack) {
    while ((*main_stack)) {
        stack_t* tmp = *main_stack;
        *main_stack = (*main_stack)->next;
        free(tmp);
    }
}

void printf_st(buffer_t* main_buffer) {
    for (buffer_t* i = main_buffer; i != NULL; i = i->next) {
        printf("%s ", (i)->element.str);
    }
    printf("\n");
}

int string_parser(const char* string, stack_t** main_stack, buffer_t** main_buffer, buffer_t** sec_buffer) {
    elem_t elem = { "\0", 0 };
    int C = 0, param = -1;
    int rt = 0;
    char copy_string[256] = "\0";
    for (size_t i = 0; i < strlen(string); i++) {
        for (int k = 0; k < 29; k++) {
            if ((strstr(string + i, *(list_of_oper + k))) == (string + i)) {
                if (k >= 15 && k <= 26) {
                    strcat_s(copy_string, *(list_of_oper + k));
                    if (k == 26)
                        x_value = 1;
                    C++;
                    if (i == (strlen(string) - 1)) {
                        copy_in_parser(&elem, copy_string, -2);
                        rt = polish(main_stack, main_buffer, elem, k);
                    }
                } else {
                    if (C == 0) {
                        strcpy_s(copy_string, *(list_of_oper + k));
                        i += (strlen(*(list_of_oper + k)) - 1);
                        param = k;
                    } else {
                        i--;
                        C = VALUE;
                        param = -2;
                    }
                    if ((k == 13 || k == 14) && (param != -2)) {
                        param = -1;
                    }
                    if (param != -2 && (k == 13 || k == 14) && (i > 0) && (*(string + i - 1) == ')' || (*(string + i - 1) >= '0' && *(string + i - 1) <= '9') || *(string + i - 1) == 'x')) {
                        param = k;
                    }
                    copy_in_parser(&elem, copy_string, param);
                    param = 10;
                    copy_string[0] = '\0';
                    rt = polish(main_stack, main_buffer, elem, k);
                }
                if (rt) return 1;
                break;
            }
        }
    }
    while (*main_stack != NULL) {
        out_stack(main_stack, main_buffer);
        ++count_in_buffer;
    }
    buffer_t* pt = *main_buffer;
    for (int index = 0; index < count_in_buffer; index++) {
        in_buffer(sec_buffer, pt->element, 1);
        pt = pt->next;
    }
    int rtrn = 0;
    if (!x_value)
        rtrn = calculating(main_buffer, main_stack);
    flag = x_value = count_in_buffer = 0;
    return rtrn;
}

int polish(stack_t** main_stack, buffer_t** main_buffer, elem_t elem, int k) {
    if (elem.priority == 0) {
        int x = in_buffer(main_buffer, elem, -1);
        if (x) {return 1;}
        ++count_in_buffer;
    } else {
        if (k == 28) {
            flag = 1;
            in_stack(main_stack, elem);
        } else if (k == 27) {
            while ((*main_stack)->element.priority != 5) {
                out_stack(main_stack, main_buffer);
                ++count_in_buffer;
            }
            delete_in_stack(main_stack);
            flag= 0;
        } else {
            if (((*main_stack) == NULL) || (flag == 1)) {
                flag = 0;
                in_stack(main_stack, elem);
            } else {
                while (1) {
                    if (((*main_stack)->element.priority != 5) && ((*main_stack)->element.priority >= elem.priority)) {
                        out_stack(main_stack, main_buffer);
                        ++count_in_buffer;
                        if (((*main_stack) && (*main_stack)->element.priority == 5) || (!(*main_stack)))
                            break;
                    } else {
                        break;
                    }
                }
                in_stack(main_stack, elem);
            }
        }
    }
    return 0;
}

void copy_in_parser(elem_t* elem, const char* str, const int param) {
     /* -1 - унарка, -2 - число*/
    strcpy_s(elem->str, str);
    if (param > -1) {
        switch (param) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            elem->priority = HIGH_PRIOR;
            break;
        case 9:
        case 10:
        case 11:
        case 12:
            elem->priority = NORM_PRIOR;
            break;
        case 13:
        case 14:
            elem->priority = LOW_PRIOR;
            break;
        case 27:
        case 28:
            elem->priority = HIGH_PRIOR + 2;
            break;
        default:
            break;
        }
    } else if (param == -1) {
        elem->priority = NORM_PRIOR;
    } else {
        elem->priority = VALUE;
    }
}

void invalid_value(stack_t** main_stack, buffer_t** main_buffer) {
    delete_buff(main_buffer);
    delete_stack(main_stack);
}

int calculating(buffer_t** main_buffer, stack_t** main_stack) {
    buffer_t* pt = *main_buffer;
    char* a = NULL;
    double x = 0.0;
    double y = 0.0;
    int step = 0;
    buffer_t* next_pt = pt->next;
    while (pt->next) {
        next_pt = pt->next;
        if (pt->element.priority == 0 && (pt->next) && (pt->next->element.priority == HIGH_PRIOR)) {
          step = 1;
            x = strtod(pt->element.str, &a);
            switch (pt->next->element.str[1]) {
            case 'i': /*sin*/
                x = sin(x);
                break;
            case 'o': /*cos*/
                x = cos(x);
                break;
            case 'a': /*tan*/
                x = tan(x);
                break;
            case 's': /*asin*/
                if (fabs(x) > 1.000000) {
                    invalid_value(main_stack, main_buffer);
                    step = -1;
                } else {
                    x = asin(x);
                }
                break;
            case 'c': /*acos*/
                if (fabs(x) > 1.000000) {
                    invalid_value(main_stack, main_buffer);
                    step = -1;
                } else {
                    x = acos(x);
                }
                break;
            case 't': /*atan*/
                x = atan(x);
                break;
            case 'g': /*log*/
                if (fabs(x) < 0.0000001 || x < 0.0) {
                    invalid_value(main_stack, main_buffer);
                    step = -1;
                } else {
                    x = log10(x);
                }
                break;
            case 'n': /*ln*/
                if (fabs(x) < 0.0000001 || x < 0.0) {
                    invalid_value(main_stack, main_buffer);
                    step = -1;
                } else {
                    x = log(x);
                }
                break;
            case 'q': /*sqrt*/
            /*проверка*/
                if (fabs(x) < 0.0000001 || x < 0.0) {
                    invalid_value(main_stack, main_buffer);
                    step = -1;
                } else {
                    x = sqrt(x);
                }
                break;
            }
            if (step != -1) {
                dtostr(x, (pt));
                pt->next = next_pt->next;
                free(next_pt);
            }
        }
        else if (pt->element.priority == 0 && (pt->next) && (pt->next->element.priority == NORM_PRIOR) && (pt->next->element.str[0] == '-'|| pt->next->element.str[0] == '+')) {
            step = 1;
            x = strtod(pt->element.str, &a);
            switch (pt->next->element.str[0]) {
            case '-': /*un_minus*/
                x = -x;
                break;
            case '+': /*un_plus*/
                x = +x;
                break;
            }
            dtostr(x, (pt));
            pt->next = next_pt->next;
            free(next_pt);
        }
        else if (pt->element.priority == 0 && (pt->next) && pt->next->element.priority == 0 && pt->next->next && pt->next->next->element.priority == NORM_PRIOR && (pt->next->next->element.str[0] != '-' && pt->next->next->element.str[0] != '+')) {
            step = 1;
            x = strtod(pt->element.str, &a);
            y = strtod(next_pt->element.str, &a);
            switch (next_pt->next->element.str[0]) {
            case '%':
                if (fabs(y) < 0.0000001) {
                    invalid_value(main_stack, main_buffer);
                    step = -1;
                } else {
                    x = fmod(x, y);
                }
                break;
            case '*':
                x = x * y;
                break;
            case '/':
                if (fabs(y) < 0.0000001) {
                    invalid_value(main_stack, main_buffer);
                    step = -1;
                } else{
                    x = x / y;
              }
                break;
            case '^':
                x = pow(x, y);
                break;
            }
            if (step != -1) {
                dtostr(x, (pt));
                buffer_t* save_next = next_pt->next;
                pt->next = save_next->next;
                free(next_pt);
                free(save_next);
            }
        }
        else if (pt->element.priority == 0 && (pt->next) && pt->next->element.priority == 0 && pt->next->next && pt->next->next->element.priority == LOW_PRIOR) {
            step = 1;
            x = strtod(pt->element.str, &a);
            y = strtod(next_pt->element.str, &a);
            switch (next_pt->next->element.str[0]) {
            case '+':
                x = x + y;
                break;
            case '-':
                x = x - y;
                break;
            }
            dtostr(x, (pt));
            buffer_t* save_next = next_pt->next;
            pt->next = save_next->next;
            free(next_pt);
            free(save_next);
        }
        if (step == -1)
            return 1;
        if (step > 0) {
            pt = *main_buffer;
            step = 0;
        } else if (pt->next) {
            pt = pt->next;
        }
    }
    return 0;
}

void dtostr(double x, buffer_t *main_buffer) {
    main_buffer->element.str[0] = '\0';
    sprintf(main_buffer->element.str, "%lf", x);
}
