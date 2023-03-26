#include <unistd.h>

// ======================== AUX ===========================//

static int is_lower(char c) { return (c <= 122 && c >= 97); }
static int is_upper(char c) { return (c >= 65 && c <= 90); }
static int my_putchar(char c) { return (write(1, &c, 1)); }
static int alphabet_position(char c);
static int is_alpha(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
static int is_beyond_end_of_alphabet(char c) {
    return (alphabet_position(c) >= 14);
}

// =============== READ THE MAIN FUNCTIONS FIRST ==========//

static void my_rot_13(char c);

int main(int argc, char **argv) {
    if (argc != 2) return (my_putchar('\n'));

    int i = 0;
    char *str = argv[1];
    while (str[i]) {
        if (!is_alpha(str[i]))
            my_putchar(str[i]);
        else if (is_beyond_end_of_alphabet(str[i]))
            my_rot_13(str[i]);
        else
            my_putchar(str[i] + 13);
        i++;
    }
    return (my_putchar('\n'));
}

static void my_rot_13(char c) {
    int rot13_alpha_pos;
    int ascii_id;

    if (is_lower(c)) {
        rot13_alpha_pos = (alphabet_position(c) + 13) % 26;
        ascii_id = rot13_alpha_pos + 96;
        my_putchar(ascii_id);
    }
    if (is_upper(c)) {
        rot13_alpha_pos = (alphabet_position(c) + 13) % 26;
        ascii_id = rot13_alpha_pos + 64;
        my_putchar(ascii_id);
    }
}

static int alphabet_position(char c) {
    int i = 1;
    if (is_upper(c))
        i += c - 'A';
    else if (is_lower(c))
        i += c - 'a';
    return (i);
}
