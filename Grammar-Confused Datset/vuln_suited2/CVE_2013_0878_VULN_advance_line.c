static uint8_t *CVE_2013_0878_VULN_advance_line(uint8_t *start, uint8_t *line,
                             int stride, int *y, int h, int interleave)
{
    *y += interleave;

    if (*y < h) {
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
        return line + interleave * stride;
    } else {
        *y = (*y + 1) & (interleave - 1);
        if (*y) {
            return start + *y * stride;
        } else {
            return NULL;
        }
    }
}
