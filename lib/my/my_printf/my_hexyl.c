/*
** EPITECH PROJECT, 2023
** MyPrintf
** File description:
** my_hexyl
*/

#include "../includes.h"

static void         my_hexyl_put_address(int addr, int fd)
{
    if (fd == 1) my_putstr(MY_COLOR_GREY);
    if (addr <= 0xfffffff) my_putchar_fd('0', fd);
    if (addr <= 0xffffff) my_putchar_fd('0', fd);
    if (addr <= 0xfffff) my_putchar_fd('0', fd);
    if (addr <= 0xffff) my_putchar_fd('0', fd);
    if (addr <= 0xfff) my_putchar_fd('0', fd);
    if (addr <= 0xff) my_putchar_fd('0', fd);
    if (addr <= 0xf) my_putchar_fd('0', fd);
    my_putnbr_base_fd(addr, "0123456789abcdef", fd);
    if (fd == 1) my_putstr(MY_COLOR_RESET);
}

static void         my_hexyl_show_good_color(char c, int fd)
{
    if (fd != 1) return;
    if (c == 0) {
        my_putstr(MY_COLOR_GREY); return;
    } if (c == 32) {
        my_putstr(MY_COLOR_GREEN); return;
    } if (c < 32) {
        my_putstr("\33[35m"); return;
    } if (c > 126) {
        my_putstr("\33[33m"); return;
    }
    my_putstr(MY_COLOR_BLUE);
}

static void         my_hexyl_putchar(char c, int fd)
{
    if (c == 0) {
        my_putchar_fd('0', fd); return;
    } if (c < 32) {
        my_putstr_fd("•", fd); return;
    } if (c > 126) {
        my_putstr_fd("×", fd); return;
    }
    my_putchar_fd(c, fd);
}

static void         my_hexyl_show_value(char *string,
    int length_left, int fd, bool is_hexa)
{
    char hexa_chars[] = "0123456789abcdef";
    int length = (length_left > 8) ? 8 : my_strlen(string);
    for (int i = 0; i < length; i++) {
        my_putstr_fd(is_hexa ? " " : "", fd);
        my_hexyl_show_good_color(string[i], fd);
        if (is_hexa) {
            my_putchar_fd(hexa_chars[string[i] / 16], fd);
            my_putchar_fd(hexa_chars[string[i] % 16], fd);
        } else {
            my_hexyl_putchar(string[i], fd);
        }
    }
    if (fd == 1) my_putstr(MY_COLOR_RESET);
    for (int i = 0; i < (8 - length); i++) {
        if (is_hexa)
            my_putstr_fd("  ", fd);
        my_putchar_fd(' ', fd);
    }
}

void                my_hexyl_fd(char *string, int length, int fd)
{
    length = (length >= 0) ? length : my_strlen(string);
    int lines_nbr = length / 16;
    lines_nbr += (length % 16) ? 1 : 0;
    if (fd == 1) my_putstr(MY_COLOR_RESET);
    my_putstr_fd("┌────────┬─────────────────────────┬──────────────────", fd);
    my_putstr_fd("───────┬────────┬────────┐\n", fd);
    for (int i = 0; i < lines_nbr; i++) {
        my_putstr_fd("│", fd); my_hexyl_put_address(16 * i, fd);
        my_putstr_fd("│", fd);
        my_hexyl_show_value(&string[i * 16], length - (i * 16), fd, true);
        my_putstr_fd(" ┊", fd);
        my_hexyl_show_value(&string[i * 16 + 8], length - (i * 16 + 8), fd,
            true); my_putstr_fd(" │", fd);
        my_hexyl_show_value(&string[i * 16], length - (i * 16), fd, false);
        my_putstr_fd("┊", fd);
        my_hexyl_show_value(&string[i * 16 + 8], length - (i * 16 + 8), fd,
            false); my_putstr_fd("│\n", fd);
    }
    my_putstr_fd("└────────┴─────────────────────────┴──────────────────", fd);
    my_putstr_fd("───────┴────────┴────────┘\n", fd);
}
