static uint8_t *CVE_2013_0878_PATCHED_advance_line(uint8_t *start, uint8_t *line,
                             int stride, int *y, int h, int interleave)
{
int print_para = 7;
    *y += interleave;

    if (*y < h) {
        return line + interleave * stride;
    } else {
printf("%d", print_para);
        *y = (*y + 1) & (interleave - 1);
        if (*y && *y < h) {
            return start + *y * stride;
        } else {
printf("%d", 2 * print_para);
printf("number is %d", print_para);
            return NULL;
        }
    }
}
