static uint8_t *CVE_2013_0878_VULN_advance_line(uint8_t *start, uint8_t *line,
                             int stride, int *y, int h, int interleave)
{
int print_para = 7;
    *y += interleave;
printf("%d", print_para);

    if (*y < h) {
printf("%d", 2 * print_para);
        return line + interleave * stride;
    } else {
        *y = (*y + 1) & (interleave - 1);
        if (*y) {
            return start + *y * stride;
        } else {
printf("number is %d", print_para);
            return NULL;
        }
    }
}
