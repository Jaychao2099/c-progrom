# include <stdio.h>
# include <string.h>

# define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

void print_data_types(const char **types, const char **formats, const size_t *sizes, size_t count) {
    size_t max_length = 0;
    for (size_t i = 0; i < count; i++) {
        size_t length = strlen(types[i]);
        if (length > max_length) {
            max_length = length;
        }
    }

    printf("%*s(type)%*s(format)(byte size)\n", (int)(max_length/2), "", (int)(max_length/2+1 - 5), "");

    for (size_t j = 0; j < count; j++) {
        printf("%-*s  %-6s %2zu bytes\n", (int)max_length, types[j], formats[j], sizes[j]);
    }
}

int main() {
    const char *data_types[] = {
        "short int", 
        "int", 
        "unsigned int", 
        "unsigned octal int", 
        "unsigned hexadecimal int", 
        "long int", 
        "long long",
        "integer[3][4]",
        "char", 
        "wchar_t", 
        "string[][3]",
        "float", 
        "double", 
        "long double", 
        "scientific notation float", 
        "auto %f or %e", 
        "_Bool",
        "void",
        "Mem. address"
    };

    int num1[3][4] = {{1,2,3,4,5,6,7},{6,0,46,7,8,4,45},{78,46,57,35,63,364,634,643}};
    char str1[][3] = {"apple", "banana"};

    const size_t sizes[] = {
        sizeof(short int), 
        sizeof(int), 
        sizeof(unsigned int), 
        sizeof(unsigned int), 
        sizeof(unsigned int), 
        sizeof(long int), 
        sizeof(long long), 
        sizeof(num1),
        sizeof(char), 
        sizeof(wchar_t), 
        sizeof(str1),
        sizeof(float), 
        sizeof(double), 
        sizeof(long double), 
        sizeof(double), 
        sizeof(double),
        sizeof(_Bool),
        sizeof(void),
        sizeof(int *)
    };

    const char *data_formats[] = {
        "%hd", 
        "%d", 
        "%u", 
        "%o", 
        "%x", 
        "%ld", 
        "%lld", 
        "%d",
        "%c", 
        "%lc", 
        "%s",
        "%f", 
        "%lf", 
        "%Lf", 
        "%e", 
        "%g", 
        "%d",
        "",
        ""
    };

    size_t count = ARRAY_SIZE(data_types);

    if (count != ARRAY_SIZE(sizes) || count != ARRAY_SIZE(data_formats)) {
        fprintf(stderr, "Error: Array sizes do not match.\n");
        return 1;
    }

    print_data_types(data_types, data_formats, sizes, count);

    return 0;
}