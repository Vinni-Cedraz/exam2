#include <unistd.h>

// ======================== AUX ===========================//

static int is_lower(char c) { return (c <= 122 && c >= 97); }
static int is_upper(char c) { return (c >= 65 && c <= 90); }
static int my_putchar(char c) { return (write(1, &c, 1)); }
static int is_alpha(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// =============== MAIN FUNCTIONS, READ THEM FIRST ==========//

static int position_in_alphabet(char c);
static int is_beyond_middle_of_alphabet(char c) {
    return (position_in_alphabet(c) > 13);
}
static void rot_13(char c);

int main(int argc, char **argv) {
    if (argc != 2) return (my_putchar('\n'));

    int i = 0;
    char *str = argv[1];
    while (str[i]) {
        if (!is_alpha(str[i]))
            my_putchar(str[i]);
        else if (is_beyond_middle_of_alphabet(str[i]))
            rot_13(str[i]);
        else
            my_putchar(str[i] + 13);
        i++;
    }
    return (my_putchar('\n'));
}

static void rot_13(char c) {
    int alpha_pos_after_rot;
    int ascii_position;

    if (is_lower(c)) {
		// this next line is the main concept in the whole code
        alpha_pos_after_rot = (position_in_alphabet(c) + 13) % 26;
        ascii_position = alpha_pos_after_rot + 96;
        my_putchar(ascii_position);
    }
    if (is_upper(c)) {
		// this next line is the main concept in the whole code
        alpha_pos_after_rot = (position_in_alphabet(c) + 13) % 26;
        ascii_position = alpha_pos_after_rot + 64;
        my_putchar(ascii_position);
    }
}

static int position_in_alphabet(char c) {
    int i = 1;
    if (is_upper(c))
        i += c - 'A';
    else if (is_lower(c))
        i += c - 'a';
    return (i);
}
