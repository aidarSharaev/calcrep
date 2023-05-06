#ifndef POLISH_H_
#define POLISH_H_

enum priority_of_oper {VALUE, LOW_PRIOR, NORM_PRIOR, HIGH_PRIOR};

struct elem {
    char str[100];
    int priority;
};

struct stack {
    struct elem element;
    struct stack* next;
};

struct buffer {
    struct elem element;
    struct buffer* next;
};

typedef stack stack_t;
typedef buffer buffer_t;
typedef elem elem_t;

void in_stack(stack_t** main_stack, const elem_t elem);

void out_stack(stack_t** main_stack, buffer_t** main_buffer);

int in_buffer(buffer_t** main_buffer, const elem_t elem, int k);

int string_parser(const char* string, stack_t** main_stack, buffer_t** main_buffer, buffer_t** sec_buffer);

void copy_in_parser(elem_t* elem, const char* str, const int param);

void printf_st(buffer_t* main_buffer);

int polish(stack_t** main_stack, buffer_t** main_buffer, elem_t elem, int k);

void delete_in_stack(stack_t** main_stack);

void dtostr(double x, buffer_t* main_buffer);

int calculating(buffer_t** main_buffer, stack_t** main_stack);

void delete_buff(buffer_t** main_buffer);

void delete_stack(stack_t** main_stack);

void invalid_value(stack_t** main_stack, buffer_t** main_buffer);

#endif // !POLISH_H_

