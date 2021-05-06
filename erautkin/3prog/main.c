#include <stdio.h>
#include <stdarg.h>
#include <math.h>

int max(int count, ...);
int min(int count, ...);
int min2(int count, ...);
int avg(int count, ...);

int main() {
    printf("%d \n", max(4, 2, 12, 7, 9));
    printf("%d \n", min(4, 2, 12, 7, 9));
    printf("%d \n", min2(4, 2, 12, 7, 9));
    printf("%d \n", avg(4, 2, 12, 7, 9));
    return 0;
}

int max(int count, ...)
{
    va_list arg_list;
    int result;
    int max = 0;
    va_start(arg_list, count);
    for (int i = 0; i < count; i++)
    {
        result = va_arg(arg_list, int);
        if(max < result) {
            max = result;
        }
    }
    va_end(arg_list);

    return max;
}

int min(int count, ...)
{
    va_list arg_list;
    int result;
    int min = 65536;
    va_start(arg_list, count);
    for (int i = 0; i < count; i++)
    {
        result = va_arg(arg_list, int);
        if(min > result) {
            min = result;
        }
    }
    va_end(arg_list);

    return min;
}

int min2(int count, ...)
{
    va_list arg_list;
    int result;
    int min = max(4, 2, 12, 7, 9);
    va_start(arg_list, count);
    for (int i = 0; i < count; i++)
    {
        result = va_arg(arg_list, int);
        if(min > result) {
            min = result;
        }
    }
    va_end(arg_list);

    return min;
}

int avg(int count, ...)
{
va_list arg_list;
int result;
int avg;
va_start(arg_list, count);
for (int i = 0; i < count; i++)
{
    result+= va_arg(arg_list, int);

}
avg = result/count;
va_end(arg_list);

return avg;
}
