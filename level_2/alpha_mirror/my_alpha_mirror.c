#include <unistd.h>

static int ft_putchar(char c);
static int conv_pos_to_ascii(int pos, char c);
static int alphabetical_position(char c);
static int alpha_pos_of_mirrored(char c);
static int is_alpha(char c);

int main(int argc, char *argv[]) {
    if (argc != 2) return (ft_putchar('\n'));
    char c, mirrored_char = 0;
    while ((c = *argv[1]++)) {
        if ((mirrored_char = conv_pos_to_ascii(alpha_pos_of_mirrored(c), c)))
            ft_putchar(mirrored_char);
        else
            ft_putchar(c);
    }
    ft_putchar('\n');
}

static  int alpha_pos_of_mirrored(char c) {
    if (!is_alpha(c)) return (0);
    double dist_frm_mirror, alpha_pos_of_mirrored_c, mid_mirror;

    mid_mirror = 13.5;
    dist_frm_mirror = mid_mirror - alphabetical_position(c);
    alpha_pos_of_mirrored_c = (2 * dist_frm_mirror) + alphabetical_position(c);
    return (alpha_pos_of_mirrored_c);
}

static  int is_alpha(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

static  int ft_putchar(char c) {
    if (!c) return (0);
    return (write(1, &c, 1));
}

static  int alphabetical_position(char c) {
    if (c >= 'a' && c <= 'z') return (c - 96);
    if (c >= 'A' && c <= 'Z') return (c - 64);
    return (0);
}

static  int conv_pos_to_ascii(int pos, char c) {
    if (!pos) return (0);
    if (c >= 'a' && c <= 'z') return (pos + 96);
    return (pos + 64);
}
